#pragma once
#include <QString>
#include <QVector>

class Student {
public:
    int StudentId;
    QString FirstName;
    QString LastName;
    int UserId;

    static QVector<Student> readFromFile();
    static void writeToFile(const QVector<Student>& students);
};
