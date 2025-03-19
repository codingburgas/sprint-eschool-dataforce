#pragma once

#include <QString>

class Test {
public:
    int TestId;
    QString Title;
    int TeacherId;

    Test(int id, QString title, int teacherId)
        : TestId(id), Title(title), TeacherId(teacherId) {}

    Test() : TestId(0), Title(""), TeacherId(0) {}

    static QVector<Test> readFromFile();
    static void writeToFile(QVector<Test> tests);
};