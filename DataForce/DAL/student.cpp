#include "student.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<Student> Student::readFromFile() 
{
    QVector<Student> students = {};
    QFile file("../DAL/data/students.txt");

    if (file.open(QIODevice::ReadOnly)) 
    {
        QTextStream in(&file);
        in.readLine(); // Skip header line

        while (!in.atEnd()) 
        {
            QString line = in.readLine();
            QStringList fields = line.split(",");

            if (fields.size() == 4) 
            {
                Student student;
                student.StudentId = fields[0].toInt();
                student.FirstName = fields[1];
                student.LastName = fields[2];
                student.UserId = fields[3].toInt();

                students.push_back(student);
            }
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for reading!";
    }
    return students;
}

void Student::writeToFile(const QVector<Student>& students) {
    QFile file("../DAL/data/students.txt");

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "StudentId,FirstName,LastName,UserId\n";

        for (const Student& student : students) 
        {
            out << student.StudentId << ","
                << student.FirstName << ","
                << student.LastName << ","
                << student.UserId << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
