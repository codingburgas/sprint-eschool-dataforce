#pragma once

#include "../DAL/student.h"
#include "userService.h"

class StudentService 
{
public:
    static QVector<Student> getAllStudents();
    static void addStudent(const Student& student);
    static void updateStudent(int studentId, const Student& student);
    static void removeStudent(int studentId);
    static Student getStudentById(int studentId);
    static Student getStudentByUserId(int usedId);
    static int getStudentIdByFirstName(QString firstName);
    static QVector<Student> getStudentsByClass(QString className);
};
