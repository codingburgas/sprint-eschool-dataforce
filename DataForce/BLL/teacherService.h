#pragma once
#include "../DAL/teacher.h"
#include "userService.h"

class TeacherService {
public:
    static QVector<Teacher> getAllTeachers();
    static void addTeacher(const Teacher& teacher);
    static Teacher getTeacherById(int teacherId);
    static int getNextTeacherId();
    static Teacher getTeacherByUserId(int usedId);
};
