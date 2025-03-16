#pragma once

#include <QString>

class Test {
public:
    int TestId;
    QString Title;
    int QuestionCount;
    int TeacherId;

    Test(int id, QString title, int questionCount, int teacherId)
        : TestId(id), Title(title), QuestionCount(questionCount), TeacherId(teacherId) {}

    Test() : TestId(0), Title(""), QuestionCount(0), TeacherId(0) {}

    static QVector<Test> readFromFile();
    static void writeToFile(QVector<Test> tests);
};