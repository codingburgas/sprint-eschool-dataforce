#pragma once

#include "../DAL/grade.h"

class GradeService
{
public:
    static QVector<Grade> getGradesByStudentId(int studentId);
    static void updateGrade(int gradeId, QString newGrade);
    static void addGrade(int studentId, int teacherId, QString gradeValue, QDateTime gradeDate);
};
