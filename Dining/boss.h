#pragma once

#include <string>

class boss
{
public:
	boss();
	~boss();
	void changePassword(std::string pwd);
	std::string getPassword();
private:
	std::string password{ "123456" };
};