#include "QuestionService.h"
#include <QDebug>

QVector<Question> QuestionService::getQuestionsByTest(int testId) 
{
    QVector<Question> questions = Question::readFromFile();
    QVector<Question> questionsByTest = {};

    for (Question& q : questions) 
    {   
        if (q.TestId == testId) 
        {
            questionsByTest.append(q);
        }
    }

    return questionsByTest;
}

void QuestionService::addQuestion(Question question) 
{
    QVector<Question> questions = Question::readFromFile();

    question.OptionA.replace(",", ";");
    question.OptionB.replace(",", ";");
    question.OptionC.replace(",", ";");
    question.OptionD.replace(",", ";");
    question.CorrectAnswer.replace(",", ";");

    int newId = getNextQuestionId();
    questions.append(Question(newId, question.TestId, question.Text, question.OptionA, question.OptionB, question.OptionC, question.OptionD, question.CorrectAnswer));

    Question::writeToFile(questions);

    qDebug() << "Question added: " << question.Text;
}

void QuestionService::updateQuestion(Question question)
{
    QVector<Question> questions = Question::readFromFile();

    for (Question& q : questions) 
    {
        if (q.QuestionId == question.QuestionId) 
        {
            q.Text = question.Text;
            q.OptionA = question.OptionA;
            q.OptionB = question.OptionB;
            q.OptionC = question.OptionC;
            q.OptionD = question.OptionD;
            q.CorrectAnswer = question.CorrectAnswer;
            
            Question::writeToFile(questions);
            
            qDebug() << "Question edited: " << question.Text;
        }
    }
}

void QuestionService::deleteQuestion(int id) 
{
    QVector<Question> questions = Question::readFromFile();

    for (int i = 0; i < questions.size(); i++) 
    {
        if (questions[i].QuestionId == id)
        {
            qDebug() << "Question deleted: " << questions[i].Text;
            questions.remove(i);
            Question::writeToFile(questions);
            
        }
    }
}

int QuestionService::getNextQuestionId()
{
    QVector<Question> questions = Question::readFromFile();

    if (questions.isEmpty()) return 1;

    int maxId = 0;

    for (const Question& q : questions)
    {
        if (q.QuestionId > maxId)
        {
            maxId = q.QuestionId;
        }
    }

    return maxId + 1;
}
