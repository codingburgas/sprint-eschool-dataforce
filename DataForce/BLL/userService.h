#pragma once

#include "../DAL/user.h"
#include "currentUser.h"
#include "teacherService.h"
#include "studentService.h"

class UserService
{
public:
	static bool validateUser(const QString& username, const QString& password);
	static User getUserById(int userId);
};