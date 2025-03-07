#pragma once

#include <QString>
#include <QVector>

class Grade
{
public:
    int GradeId;
    int StudentId;
    int TeacherId;
    QString Class;
    QString GradeValue;

    static QVector<Grade> readFromFile();
    static void writeToFile(const QVector<Grade>& grades);
};
