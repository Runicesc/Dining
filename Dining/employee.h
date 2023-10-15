#pragma once

#include<string>
#include<vector>

using std::string;

class employee
{
public:
	string name;
	string gender;
	int count{ 0 };
	int salary{ 2000 };
	void saveData();
	static std::vector<employee> loadData();
	void static addEmployee();
	void static delEmployee();
	void saveDelData();
};