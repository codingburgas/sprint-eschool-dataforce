#pragma once

#include <QString>

class Question {
public:
    int QuestionId;
    int TestId;
    QString Text;
    QString OptionA;
    QString OptionB;
    QString OptionC;
    QString OptionD;
    QString CorrectAnswer; // 'A', 'B', 'C', 'D'

    Question(int id, int testId, QString text, QString a, QString b, QString c, QString d, QString correct)
        : QuestionId(id), TestId(testId), Text(text), OptionA(a), OptionB(b), OptionC(c), OptionD(d), CorrectAnswer(correct) {}

    Question() : QuestionId(0), TestId(0), Text("Q"), OptionA("A"), OptionB("B"), OptionC("C"), OptionD("D"), CorrectAnswer('A') {}

    static QVector<Question> readFromFile();
    static void writeToFile(const QVector<Question>& questions);
};