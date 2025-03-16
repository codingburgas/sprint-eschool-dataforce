#pragma once

#include <QString>

class TestStudent {
public:
    int TestStudentId;
    int TestId;
    int StudentId;
    QString Grade;

    TestStudent(int id, int testId, int studentId, QString grade)
        : TestStudentId(id), TestId(testId), StudentId(studentId), Grade(grade) {}

    TestStudent() : TestStudentId(0), TestId(0), StudentId(0), Grade("F") {}

    static QVector<TestStudent> readFromFile();
    static void writeToFile(QVector<TestStudent> testStudents);
};