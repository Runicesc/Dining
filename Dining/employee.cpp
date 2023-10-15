#include <iostream>
#include<filesystem>
#include<fstream>

#include"employee.h"


using std::cout;
using std::endl;
using std::cin;

void employee::saveData() {
	std::ofstream out("employee.dat", std::ios::binary | std::ios::app);
	if (out) {
		std::string data = name + " " + gender + " " + std::to_string(count) + " " + std::to_string(salary) + "\n";
		out.write(data.c_str(), data.length());
		out.close();
		std::cout << "Data saved." << std::endl;
	}
}
std::vector<employee> employee::loadData() {
	std::vector<employee> employees;
	std::ifstream in("employee.dat", std::ios::binary);
	if (in) {
		std::string line;
		while (std::getline(in, line)) {
			std::istringstream iss(line);
			std::string name, gender;
			int count, salary;
			iss >> name >> gender >> count >> salary;
			employee e;
			e.name = name;
			e.gender = gender;
			e.count = count;
			e.salary = salary;
			employees.push_back(e);
		}
		in.close();
	}
	return employees;
}
void employee::addEmployee()
{
	cout << "输入 姓名 性别" << endl;
	std::string name, gender;
	cin >> name >> gender;
	employee e1(name, gender, 0, 2000);
	e1.saveData();
}

void employee::delEmployee()
{
	cout << "输入姓名" << endl;
	std::string name;
	cin >> name;
	std::vector<employee> loadedData = employee::loadData();
	for (auto& e : loadedData) {
		if (e.name == name) {
			continue;
		}
		e.saveDelData();
	}
}

void employee::saveDelData() {
	std::ofstream out("employee.dat", std::ios::binary);
	if (out) 
	{
		std::string data = name + " " + gender + " " + std::to_string(count) + " " + std::to_string(salary) + "\n";
		out.write(data.c_str(), data.length());
		out.close();
		std::cout << "Data saved." << std::endl;
	}
}