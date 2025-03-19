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

void TestService::addTest(Test test)
{
    QVector<Test> tests = Test::readFromFile();

    tests.append(test);
    Test::writeToFile(tests);

    qDebug() << "Test added: " << test.Title;
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


int TestService::getNextTestId()
{
    QVector<Test> tests = Test::readFromFile();

    if (tests.isEmpty()) return 1;

    int maxId = 0;

    for (const Test& t : tests)
    {
        if (t.TestId > maxId)
        {
            maxId = t.TestId;
        }
    }

    return maxId + 1;
}