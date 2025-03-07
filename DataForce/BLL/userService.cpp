#include "userService.h"
#include <QDebug>

bool UserService::validateUser(const QString& username, const QString& password) 
{
    QVector<User> users = User::readFromFile();

    for (const User& user : users) 
    {
        if (user.Username == username && user.Password == password)
        {
            CurrentUser::userId = user.UserId;
            CurrentUser::username = user.Username;
            CurrentUser::role = user.Role;
            CurrentUser::className = user.Class;

            if (user.Role == "student")
            {
                CurrentUser::studentId = StudentService::getStudentByUserId(user.UserId).StudentId;
            }
            else if (user.Role == "teacher")
            {
                CurrentUser::teacherId = TeacherService::getTeacherByUserId(user.UserId).TeacherId;
            }

            return true;
        }
    }

    return false;
}


User UserService::getUserById(int userId)
{
    QVector<User> users = User::readFromFile();

    for (User& user : users)
    {
        if (user.UserId == userId)
        {
            return user;
        }
    }
}
