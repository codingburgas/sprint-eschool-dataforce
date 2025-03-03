#pragma once
#include <QString>
#include <vector>

class Student {
public:
    int StudentID;
    QString FirstName;
    QString LastName;
    QString DateOfBirth;
    QString Class;
    int TeacherID;

    static std::vector<Student> readFromFile(const QString& filename);
    static void writeToFile(const QString& filename, const std::vector<Student>& students);
};
