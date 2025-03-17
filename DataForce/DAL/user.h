#pragma once
#include <QString>
#include <QVector>

class User 
{

public:
    int UserId;
    QString Username;
    QString Password;
    QString Role;

    static QVector<User> readFromFile();
    static void writeToFile(const QVector<User>& users);
};
