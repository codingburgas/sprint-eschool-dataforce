#include "user.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QVector<User> User::readFromFile()
{
    QVector<User> users = {};
    QFile file("../DAL/data/users.txt");

    if (file.open(QIODevice::ReadOnly)) 
    {
        QTextStream in(&file);
        in.readLine(); // Skip header line

        while (!in.atEnd()) 
        {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 5) 
            {
                User user;
                user.UserId = fields[0].toInt();
                user.Username = fields[1];
                user.Password = fields[2];
                user.Role = fields[3];
                user.Class = fields[4];

                users.push_back(user);
            }
        }
        file.close();
    }
    else 
    {
        qDebug() << "Failed to open the file for reading!";
    }
    
    return users;
}

void User::writeToFile(const QVector<User>& users)
{
    QFile file("../DAL/data/users.txt");

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "UserId,Username,Password,Role,Class\n";

        for (const User& user : users) {
            out << user.UserId << ","
                << user.Username << ","
                << user.Password << ","
                << user.Role << ","
                << user.Class << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "Failed to open the file for writing!";
    }
}
