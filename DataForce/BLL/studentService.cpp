#include "studentService.h"

QVector<Student> StudentService::getAllStudents()
{
    return Student::readFromFile();
}

void StudentService::addStudent(const Student& student) 
{
    QVector<Student> students = Student::readFromFile();
    students.push_back(student);
    Student::writeToFile(students);
}

Student StudentService::getStudentByUserId(int userId)
{
    QVector<Student> students = Student::readFromFile();

    for (Student& student : students)
    {
        if (student.UserId == userId)
        {
            return student;
        }
    }
}

Student StudentService::getStudentById(int studentId)
{
    QVector<Student> students = Student::readFromFile();

    for (Student& student : students)
    {
        if (student.StudentId == studentId)
        {
            return student;
        }
    }
}

int StudentService::getNextStudentId()
{
    QVector<Student> students = Student::readFromFile();

    if (students.isEmpty()) return 1;

    int maxId = 0;

    for (const Student& s : students)
    {
        if (s.StudentId > maxId)
        {
            maxId = s.StudentId;
        }
    }

    return maxId + 1;
}