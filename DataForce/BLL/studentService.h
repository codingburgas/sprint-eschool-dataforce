#pragma once

#include "../DAL/student.h"
#include "userService.h"

class StudentService 
{
public:
    static QVector<Student> getAllStudents();
    static void addStudent(const Student& student);
    static Student getStudentById(int studentId);
    static Student getStudentByUserId(int usedId);
    static int getNextStudentId();
};
