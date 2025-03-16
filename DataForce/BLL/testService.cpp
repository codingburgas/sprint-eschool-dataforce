#include "TestService.h"
#include <QDebug>

QVector<Test> TestService::getAllTests() 
{
    QVector<Test> tests = Test::readFromFile();

    return tests;
}

Test TestService::getTestById(int testId)
{
    QVector<Test> tests = Test::readFromFile();

    for (Test& test : tests)
    {
        if (test.TestId == testId)
        {
            return test;
        }
    }
}

void TestService::addTest(QString title)
{
    QVector<Test> tests = Test::readFromFile();

    int newId = tests.size() + 1;
    tests.append(Test(newId, title, 0, CurrentUser::teacherId));
    Test::writeToFile(tests);

    qDebug() << "Test added: " << title;
}

void TestService::editTest(int id, QString title)
{
    QVector<Test> tests = Test::readFromFile();

    for (Test& test : tests) 
    {
        if (test.TestId == id) 
        {
            test.Title = title;
            test.TeacherId = CurrentUser::teacherId;
            Test::writeToFile(tests);

            qDebug() << "Test edited: " << title;

            return;
        }
    }
}

void TestService::deleteTest(int id) 
{
    QVector<Test> tests = Test::readFromFile();

    for (int i = 0; i < tests.size(); i++)
    {
        if (tests[i].TestId == id)
        {
            qDebug() << "Test deleted: " << tests[i].Title;
            tests.remove(i);
            Test::writeToFile(tests);

            return;
        }
    }
}