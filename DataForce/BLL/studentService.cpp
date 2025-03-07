#include "studentService.h"

QVector<Student> StudentService::getAllStudents()
{
    return Student::readFromFile();
}

QVector<Student> StudentService::getStudentsByClass(QString className)
{
    QVector<Student> students = Student::readFromFile();
    QVector<Student> filteredStudents;

    for (Student& s : students)
    {
        QString studentClassName = UserService::getUserById(s.UserId).Class;

        if (studentClassName == className)
        {
            filteredStudents.push_back(s);
        }
    }

    return filteredStudents;
}

void StudentService::addStudent(const Student& student) 
{
    QVector<Student> students = Student::readFromFile();
    students.push_back(student);
    Student::writeToFile(students);
}

void StudentService::updateStudent(int StudentId, const Student& student)
{
    QVector<Student> students = Student::readFromFile();

    for (Student& s : students)
    {
        if (s.StudentId == StudentId) 
        {
            s = student;
            break;
        }
    }
    Student::writeToFile(students);
}

void StudentService::removeStudent(int StudentId) {
    QVector<Student> students = Student::readFromFile();

    students.erase(std::remove_if(students.begin(), students.end(),
        [StudentId](const Student& s) { return s.StudentId == StudentId; }),
        students.end());

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

int StudentService::getStudentIdByFirstName(QString firstName)
{
    QVector<Student> students = Student::readFromFile();

    for (Student& student : students)
    {
        if (student.FirstName == firstName)
        {
            return student.StudentId;
        }
    }
}