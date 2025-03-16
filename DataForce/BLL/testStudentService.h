#pragma once

#include "../DAL/grade.h"
#include "../DAL/testStudent.h"
#include <qdebug.h>

class TestStudentService
{
public:
    static QString getTestGradeById(int testId, int studentId);
    static QVector<TestStudent> getTestGradesByTestId(int testId);
    static void addTestGrade(int testId, int studentId, QString grade);
};