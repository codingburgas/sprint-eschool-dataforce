#include "grade.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<Grade> Grade::readFromFile()
{
    QVector<Grade> grades = {};
    QFile file("../DAL/data/grades.txt");

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
                Grade grade;

                grade.GradeId = fields[0].toInt();
                grade.StudentId = fields[1].toInt();
                grade.TeacherId = fields[2].toInt();
                grade.Class = fields[3];
                grade.GradeValue = fields[4];

                grades.push_back(grade);
            }
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for reading!";
    }
    return grades;
}

void Grade::writeToFile(const QVector<Grade>& grades) {
    QFile file("../DAL/data/grades.txt");

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "GradeId,StudentId,TeacherId,GradeValue\n";

        for (const Grade& grade : grades)
        {
            out << grade.GradeId << ","
                << grade.StudentId << ","
                << grade.TeacherId << ","
                << grade.Class << ","
                << grade.GradeValue << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
