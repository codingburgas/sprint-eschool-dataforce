#pragma once

#include "../DAL/student.h"

class StudentManager 
{
public:
    static std::vector<Student> getAllStudents();
    static void addStudent(const Student& student);
    static void updateStudent(int studentID, const Student& student);
    static void removeStudent(int studentID);
};
