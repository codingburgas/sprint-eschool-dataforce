#include "userService.h"

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

void UserService::addUser(User user)
{
    QVector<User> users = User::readFromFile();
    users.push_back(user);
    User::writeToFile(users);
}

int UserService::getNextUserId()
{
    QVector<User> users = User::readFromFile();

    if (users.isEmpty()) return 1;

    int maxId = 0;

    for (const User& u : users)
    {
        if (u.UserId > maxId)
        {
            maxId = u.UserId;
        }
    }

    return maxId + 1;
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

QString UserService::generateRandomPassword()
{
    QString password;

    QChar firstLetter = QChar('A' + QRandomGenerator::global()->bounded(26));
    password.append(firstLetter);

    for (int i = 0; i < 2; i++)
    {
        QChar lowerLetter = QChar('a' + QRandomGenerator::global()->bounded(26));
        password.append(lowerLetter);
    }

    for (int i = 0; i < 5; i++)
    {
        QChar digit = QChar('0' + QRandomGenerator::global()->bounded(10));
        password.append(digit);
    }

    return password;
}

void UserService::logout()
{
    CurrentUser::userId = -1;
    CurrentUser::username = "";
    CurrentUser::teacherId = -1;
    CurrentUser::studentId = -1;
    CurrentUser::role = "";
}