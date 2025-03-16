#include "testStudentService.h"

QString TestStudentService::getTestGradeById(int testId, int studentId)
{
    QVector<TestStudent> allTestGrades = TestStudent::readFromFile();

    for (const TestStudent& tg : allTestGrades)
    {
        if (tg.StudentId == studentId && tg.TestId == testId)
        {
            return tg.Grade;
        }
    }

    return "Not Graded";
}

QVector<TestStudent> TestStudentService::getTestGradesByTestId(int testId)
{
    QVector<TestStudent> currentTestGrades = {};
    QVector<TestStudent> allTestGrades = TestStudent::readFromFile();

    for (const TestStudent& tg : allTestGrades)
    {
        if (tg.TestId == testId)
        {
            currentTestGrades.push_back(tg);
        }
    }


    return currentTestGrades;
}

void TestStudentService::addTestGrade(int testId, int studentId, QString grade)
{
    QVector<TestStudent> testGrades = TestStudent::readFromFile();

    int newTestStudentId = testGrades.isEmpty() ? 1 : testGrades.last().TestStudentId + 1;

    testGrades.append({ newTestStudentId, testId, studentId, grade});
    TestStudent::writeToFile(testGrades);
}
