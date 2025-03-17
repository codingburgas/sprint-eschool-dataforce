#include "question.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<Question> Question::readFromFile()
{
    QVector<Question> questions = {};
    QFile file("../DAL/data/questions.txt");

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        in.readLine(); // Skip header line

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList fields = line.split(",");

            if (fields.size() == 8)
            {
                Question question;
                question.QuestionId = fields[0].toInt();
                question.TestId = fields[1].toInt();
                question.Text = fields[2];
                question.OptionA = fields[3];
                question.OptionB = fields[4];
                question.OptionC = fields[5];
                question.OptionD = fields[6];
                question.CorrectAnswer = fields[7];

                questions.push_back(question);
            }
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for reading!";
    }
    return questions;
}

void Question::writeToFile(const QVector<Question>& questions) 
{
    QFile file("../DAL/data/questions.txt");

    if (file.open(QIODevice::WriteOnly)) 
    {
        QTextStream out(&file);

        out << "QuestionId,TestId,Text,OptionA,OptionB,OptionC,OptionD,CorrectAnswer\n";

        for (const Question& question : questions)
        {
            out << question.QuestionId << ","
                << question.TestId << ","
                << question.Text << ","
                << question.OptionA << ","
                << question.OptionB << ","
                << question.OptionC << ","
                << question.OptionD << ","
                << question.CorrectAnswer << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
