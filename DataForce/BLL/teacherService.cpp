#include "teacherService.h"
#include "../DAL/teacher.h"

std::vector<Teacher> TeacherService::getAllTeachers() {
    return Teacher::readFromFile("teachers.txt");
}

void TeacherService::addTeacher(const Teacher& teacher) {
    std::vector<Teacher> teachers = Teacher::readFromFile("teachers.txt");
    teachers.push_back(teacher);
    Teacher::writeToFile("teachers.txt", teachers);
}

void TeacherService::updateTeacher(int teacherID, const Teacher& teacher) {
    std::vector<Teacher> teachers = Teacher::readFromFile("teachers.txt");
    for (auto& t : teachers) {
        if (t.TeacherID == teacherID) {
            t = teacher;
            break;
        }
    }
    Teacher::writeToFile("teachers.txt", teachers);
}

void TeacherService::removeTeacher(int teacherID) {
    std::vector<Teacher> teachers = Teacher::readFromFile("teachers.txt");
    teachers.erase(std::remove_if(teachers.begin(), teachers.end(),
        [teacherID](const Teacher& t) { return t.TeacherID == teacherID; }),
        teachers.end());
    Teacher::writeToFile("teachers.txt", teachers);
}
