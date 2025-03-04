#include "userService.h"
#include <QDebug>

bool UserService::validateUser(const QString& username, const QString& password) 
{
    QVector<User> users = User::readFromFile();

    for (const User& user : users) 
    {
        if (user.Username == username && user.Password == password) 
        {
            qDebug() << "Mangal";

            return true;
        }
    }

    return false;
}
