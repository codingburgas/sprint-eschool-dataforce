#include "gradeService.h"

QVector<Grade> GradeService::getGradesByClass(QString className)
{
    QVector<Grade> classGrades = { };
    QVector<Grade> allGrades = Grade::readFromFile();

    for (const Grade& g : allGrades)
    {
        if (g.Class == className)
        {
            classGrades.push_back(g);
        }
    }
    return classGrades;
}

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

void GradeService::updateGrade(int gradeId, QString newGrade)
{
    QVector<Grade> grades = Grade::readFromFile();

    for (Grade& g : grades)
    {
        if (g.GradeId == gradeId)
        {
            g.GradeValue = newGrade;
            break;
        }
    }
    Grade::writeToFile(grades);
}

void GradeService::addGrade(int studentId, int teacherId, QString className, QString gradeValue)
{
    QVector<Grade> grades = Grade::readFromFile();
    int newGradeId = grades.isEmpty() ? 1 : grades.last().GradeId + 1;

    grades.append({ newGradeId, studentId, teacherId, className, gradeValue });
    Grade::writeToFile(grades);
}
