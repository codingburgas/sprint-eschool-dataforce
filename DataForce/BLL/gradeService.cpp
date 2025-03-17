#include "gradeService.h"
#include <QDebug>

QVector<Grade> GradeService::getGradesByStudentId(int studentId)
{
    QVector<Grade> studentGrades = { };
    QVector<Grade> allGrades = Grade::readFromFile();

    for (const Grade& g : allGrades)
    {
        if (g.StudentId == studentId)
        {
            studentGrades.push_back(g);
        }
    }

    return studentGrades;
}

void GradeService::deleteGrade(int gradeId)
{
    QVector<Grade> newGrades = {};
    QVector<Grade> grades = Grade::readFromFile();


    for (Grade& g : grades)
    {
        if (g.GradeId != gradeId)
        {
            newGrades.append(g);
        }
    }

    Grade::writeToFile(newGrades);
}

void GradeService::addGrade(int studentId, int teacherId, QString gradeValue, QDateTime gradeDate)
{
    QVector<Grade> grades = Grade::readFromFile();
    int newGradeId = grades.isEmpty() ? 1 : grades.last().GradeId + 1;

    grades.append({ newGradeId, studentId, teacherId, gradeValue, gradeDate });
    Grade::writeToFile(grades);
}
