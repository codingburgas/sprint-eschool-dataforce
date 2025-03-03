#include "Teacher.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

std::vector<Teacher> Teacher::readFromFile(const QString& filename) 
{
    std::vector<Teacher> teachers;
    QFile file(filename);

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
                teacher.TeacherID = fields[0].toInt();
                teacher.FirstName = fields[1];
                teacher.LastName = fields[2];
                teacher.Subject = fields[3];
                teacher.Class = fields[4];
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

void Teacher::writeToFile(const QString& filename, const std::vector<Teacher>& teachers) 
{
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)) 
    {
        QTextStream out(&file);
        out << "TeacherID,FirstName,LastName,Subject,Class\n";

        for (const Teacher& teacher : teachers) 
        {
            out << teacher.TeacherID << ","
                << teacher.FirstName << ","
                << teacher.LastName << ","
                << teacher.Subject << ","
                << teacher.Class << "\n";
        }
        file.close();
    }
    else
    {
        qDebug() << "Failed to open the file for writing!";
    }
}
