#pragma once
#include <QString>
#include <vector>

class Teacher {
public:
    int TeacherID;
    QString FirstName;
    QString LastName;
    QString Subject;
    QString Class;

    static std::vector<Teacher> readFromFile(const QString& filename);
    static void writeToFile(const QString& filename, const std::vector<Teacher>& teachers);
};
