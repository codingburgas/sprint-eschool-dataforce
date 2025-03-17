#include "teacherService.h"
#include "../DAL/teacher.h"

QVector<Teacher> TeacherService::getAllTeachers() {
    return Teacher::readFromFile();
}

void TeacherService::addTeacher(const Teacher& teacher) {
    QVector<Teacher> teachers = Teacher::readFromFile();
    teachers.push_back(teacher);
    Teacher::writeToFile(teachers);
}

int TeacherService::getNextTeacherId()
{
    QVector<Teacher> teachers = Teacher::readFromFile();

    if (teachers.isEmpty()) return 1;

    int maxId = 0;

    for (const Teacher& t : teachers)
    {
        if (t.TeacherId > maxId)
        {
            maxId = t.TeacherId;
        }
    }

    return maxId + 1;
}


Teacher TeacherService::getTeacherByUserId(int userId)
{
    QVector<Teacher> teachers = Teacher::readFromFile();

    for (const Teacher& teacher : teachers)
    {
        if (teacher.UserId == userId)
        {
            return teacher;
        }
    }
}

Teacher TeacherService::getTeacherById(int teacherId)
{
    QVector<Teacher> teachers = Teacher::readFromFile();

    for (const Teacher& teacher : teachers)
    {
        if (teacher.TeacherId == teacherId)
        {
            return teacher;
        }
    }
}
