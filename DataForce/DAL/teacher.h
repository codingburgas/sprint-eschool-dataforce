#pragma once
#include <QString>
#include <QVector>

class Teacher {
public:
    int TeacherId;
    QString FirstName;
    QString LastName;
    QString Subject;
    int UserId;

    static QVector<Teacher> readFromFile();
    static void writeToFile(const QVector<Teacher>& teachers);
};
