#include "studentManager.h"

std::vector<Student> StudentManager::getAllStudents() 
{
    return Student::readFromFile("students.txt");
}

void StudentManager::addStudent(const Student& student) {
    std::vector<Student> students = Student::readFromFile("students.txt");
    students.push_back(student);
    Student::writeToFile("students.txt", students);
}

void StudentManager::updateStudent(int studentID, const Student& student) {
    std::vector<Student> students = Student::readFromFile("students.txt");
    for (auto& s : students) {
        if (s.StudentID == studentID) {
            s = student;
            break;
        }
    }
    Student::writeToFile("students.txt", students);
}

void StudentManager::removeStudent(int studentID) {
    std::vector<Student> students = Student::readFromFile("students.txt");
    students.erase(std::remove_if(students.begin(), students.end(),
        [studentID](const Student& s) { return s.StudentID == studentID; }),
        students.end());
    Student::writeToFile("students.txt", students);
}
