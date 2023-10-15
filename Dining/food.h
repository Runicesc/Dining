#pragma once

#include<string>
#include<vector>

class food
{
public:
	food() = default;
	food(std::string, int p);
	~food();
	void saveData();
	static std::vector<food> loadData();
	std::string name;
	static void addFood();
	static void delFood();
	void saveTheData();
	int price{ 0 };
};