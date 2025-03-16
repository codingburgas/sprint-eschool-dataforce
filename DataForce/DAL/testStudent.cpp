#include "testStudent.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<TestStudent> TestStudent::readFromFile()
{
    QVector<TestStudent> testStudentStudents = {};
    QFile file("../DAL/data/testStudents.txt");

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
                TestStudent testStudent;
                testStudent.TestStudentId = fields[0].toInt();
                testStudent.TestId = fields[1].toInt();
                testStudent.StudentId = fields[2].toInt();
                testStudent.Grade = fields[3];

                testStudentStudents.push_back(testStudent);
            }
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for reading!";
    }
    return testStudentStudents;
}

void TestStudent::writeToFile(QVector<TestStudent> testStudents) 
{
    QFile file("../DAL/data/testStudents.txt");

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "TestStudentId,TestId,StudentId,Grade\n";

        for (const TestStudent& testStudent : testStudents)
        {
            out << testStudent.TestStudentId << ","
                << testStudent.TestId << ","
                << testStudent.StudentId << ","
                << testStudent.Grade << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
