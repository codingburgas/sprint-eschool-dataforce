#pragma once

#include "../DAL/user.h"
#include "currentUser.h"
#include "teacherService.h"
#include "studentService.h"
#include <QRandomGenerator>

class UserService
{
public:
	static bool validateUser(const QString& username, const QString& password);
	static User getUserById(int userId);
	static void addUser(User user);
	static int getNextUserId();
	static QString generateRandomPassword();
	static void logout();
};