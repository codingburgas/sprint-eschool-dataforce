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

void TeacherService::updateTeacher(int teacherId, const Teacher& teacher) {
    QVector<Teacher> teachers = Teacher::readFromFile();
    for (auto& t : teachers) {
        if (t.TeacherId== teacherId) {
            t = teacher;
            break;
        }
    }
    Teacher::writeToFile(teachers);
}

void TeacherService::removeTeacher(int teacherId) {
    QVector<Teacher> teachers = Teacher::readFromFile();
    teachers.erase(std::remove_if(teachers.begin(), teachers.end(),
        [teacherId](const Teacher& t) { return t.TeacherId == teacherId; }),
        teachers.end());
    Teacher::writeToFile(teachers);
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
