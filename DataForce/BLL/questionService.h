#pragma once

#include "../DAL/question.h"

class QuestionService
{
public:
    static QVector<Question> getQuestionsByTest(int testId);
    static void addQuestion(Question question);
    static void deleteQuestion(int id);
    static void updateQuestion(Question question);
};
