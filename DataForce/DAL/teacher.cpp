#include "Teacher.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<Teacher> Teacher::readFromFile()
{
    QVector<Teacher> teachers = {};
    QFile file("../DAL/data/teachers.txt");

    if (file.open(QIODevice::ReadOnly)) 
    {
        QTextStream in(&file);
        in.readLine(); // Skip header line

        while (!in.atEnd()) 
        {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 5) 
            {
                Teacher teacher;
                teacher.TeacherId = fields[0].toInt();
                teacher.FirstName = fields[1];
                teacher.LastName = fields[2];
                teacher.Subject = fields[3];
                teacher.UserId = fields[4].toInt();

                teachers.push_back(teacher);
            }
        }
        file.close();
    }
    else 
    {
        qDebug() << "Failed to open the file for reading!";
    }
    return teachers;
}

void Teacher::writeToFile(const QVector<Teacher>& teachers) 
{
    QFile file("../DAL/data/teachers.txt");

    if (file.open(QIODevice::WriteOnly)) 
    {
        QTextStream out(&file);
        out << "TeacherId,FirstName,LastName,Subject,UserId\n";

        for (const Teacher& teacher : teachers) 
        {
            out << teacher.TeacherId << ","
                << teacher.FirstName << ","
                << teacher.LastName << ","
                << teacher.Subject << ","
                << teacher.UserId << "\n";
        }
        file.close();
    }
    else
    {
        qDebug() << "Failed to open the file for writing!";
    }
}
