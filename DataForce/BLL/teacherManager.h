#pragma once
#include "../DAL/teacher.h"
#include <vector>

class TeacherManager {
public:
    static std::vector<Teacher> getAllTeachers();
    static void addTeacher(const Teacher& teacher);
    static void updateTeacher(int teacherID, const Teacher& teacher);
    static void removeTeacher(int teacherID);
};
