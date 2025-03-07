#pragma once

#include "../DAL/grade.h"

class GradeService
{
public:
    static QVector<Grade> getGradesByClass(QString className);
    static QVector<Grade> getGradesByStudentId(int studentId);
    static void updateGrade(int gradeId, QString newGrade);
    static void addGrade(int studentId, int teacherId, QString className, QString gradeValue);
};
