#include<filesystem>
#include<fstream>
#include <iostream>

#include"food.h"

using std::cout;
using std::endl;

food::food(std::string n, int p)
{
	this->name = n;
	this->price = p;
}

food::~food()
{
}

void food::saveData()
{
	std::ofstream out("food.dat", std::ios::binary | std::ios::app);
	if (out) {
		std::string data = name + " " + std::to_string(price) + "\n";
		out.write(data.c_str(), data.length());
		out.close();
		std::cout << "Data saved." << std::endl;
	}
}
std::vector<food> food::loadData()
{
	std::vector<food> foods;
	std::ifstream in("food.dat", std::ios::binary);
	if (in) {
		std::string line;
		while (std::getline(in, line)) {
			std::istringstream iss(line);
			std::string name;
			int price;
			iss >> name >> price;
			food f;
			f.name = name;
			f.price = price;
			foods.push_back(f);
		}
		in.close();
	}
	return foods;
}

void food::addFood()
{
	cout << "输入 菜名 价格" << endl;
	std::string name;
	int p;
	std::cin >> name >> p;
	food f1(name, p);
	f1.saveData();
}

void food::delFood()
{
	cout << "输入菜名" << endl;
	std::string name;
	std::cin >> name;
	std::vector<food> loadedData = food::loadData();
	for (auto& e : loadedData) {
		if (e.name == name) {
			continue;
		}
		e.saveTheData();
	}
}
void food::saveTheData()
{
	std::ofstream out("food.dat", std::ios::binary);
	if (out) {
		std::string data = name + " " + std::to_string(price) + "\n";
		out.write(data.c_str(), data.length());
		out.close();
		std::cout << "Data saved." << std::endl;
	}
}