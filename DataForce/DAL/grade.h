#pragma once

#include <QString>
#include <QVector>
#include <QDateTime>

class Grade
{
public:
    int GradeId;
    int StudentId;
    int TeacherId;
    QString GradeValue;
    QDateTime GradeDate;

    static QVector<Grade> readFromFile();
    static void writeToFile(const QVector<Grade>& grades);
};
