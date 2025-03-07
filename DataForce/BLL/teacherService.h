#pragma once
#include "../DAL/teacher.h"
#include "userService.h"

class TeacherService {
public:
    static QVector<Teacher> getAllTeachers();
    static void addTeacher(const Teacher& teacher);
    static void updateTeacher(int teacherId, const Teacher& teacher);
    static void removeTeacher(int teacherId);
    static Teacher getTeacherById(int teacherId);
    static Teacher getTeacherByUserId(int usedId);
};
