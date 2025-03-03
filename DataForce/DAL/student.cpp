#include "student.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

std::vector<Student> Student::readFromFile(const QString& filename) {
    std::vector<Student> students;
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in.readLine(); // Skip header line

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 6) {
                Student student;
                student.StudentID = fields[0].toInt();
                student.FirstName = fields[1];
                student.LastName = fields[2];
                student.DateOfBirth = fields[3];
                student.Class = fields[4];
                student.TeacherID = fields[5].toInt();
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

void Student::writeToFile(const QString& filename, const std::vector<Student>& students) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "StudentID,FirstName,LastName,DateOfBirth,Class,TeacherID\n";

        for (const Student& student : students) {
            out << student.StudentID << ","
                << student.FirstName << ","
                << student.LastName << ","
                << student.DateOfBirth << ","
                << student.Class << ","
                << student.TeacherID << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
