#pragma once

#include "../DAL/user.h"

class UserService
{
public:
	static bool validateUser(const QString& username, const QString& password);
};