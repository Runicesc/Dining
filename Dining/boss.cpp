#include<fstream>
#include<filesystem>
#include <iostream>

#include"boss.h"
#include "employee.h"
#include "runApp.h"
#include"food.h"

using std::cout;
using std::endl;

boss::boss()
{
	std::ifstream in{ "boss.dat", std::ios::binary };
	if (!in.is_open())
	{
		std::cout << "disopened";
	}
	std::stringstream ss;
	ss << in.rdbuf();
	in.close();
	password = ss.str();
	newpwd:system("cls");
	cout << "***********************************" << endl;
	cout << "*******  餐厅管理系统系统  ********" << endl;
	cout << "******      请输入密码：    *******" << endl;
	cout << "***********************************" << endl;
	std::string pwd;
	std::cin >> pwd;
	while (pwd != password)
	{
		if (pwd == "-999")
		{
			system("cls");
			runApp run;
		}
		cout << "密码错误,请重新输入" << endl;
		std::cin >> pwd;
	}
manage:system("cls");
	cout << "***********************************" << endl;
	cout << "*******      请选择功能     *******" << endl;
	cout << "*******      1.员工管理     *******" << endl;
	cout << "*******      2.菜单管理     *******" << endl;
	cout << "*******      3.密码修改     *******" << endl;
	cout << "***********************************" << endl;
	int s{ 0 };
	std::cin >> s;
	switch (s)
	{
	case 0:
	{
		system("cls");
		runApp run;
		break;
	}
	case 1:
	{
		system("cls");
		employee Employee;
		std::vector<employee> loadedData = employee::loadData();
		for (const auto& e : loadedData)
		{
			std::cout << "Name: " << e.name << ", Gender: " << e.gender << ", Count: " << e.count << ", Salary: " << e.salary << std::endl;
		}
		int j{ 0 };
		cout << "选择功能：1.增加员工 2.删除员工，按0返回" << endl;
		std::cin >> j;
		switch (j)
		{
		case 0:
		{
			system("cls");
			runApp run;
			break;
		}
		case 1:
		{
			employee::addEmployee();
			goto manage;
			break;
		}
		case 2:
		{
			employee::delEmployee();
			goto manage;
			break;
		}
		}
		break;
	}
	case 2:
	{
	loop:system("cls");
		cout << "查看菜单" << endl;
		std::vector<food> loadedFoods = food::loadData();
		for (const auto& f : loadedFoods)
		{
			std::cout << "Name: " << f.name << ", Price: " << f.price << std::endl;
		}
		int t{ 0 };
		cout << "1.增加菜品2.删除菜品,按0退出" << endl;
		std::cin >> t;
		switch (t)
		{
		case 0:
		{
			system("cls");
			runApp run;
			break;
		}
		case 1:
		{
			food::addFood();
			goto loop;
			break;
		}
		case 2:
		{
			food::delFood();
			goto loop;
			break;
		}
		}
		break;
	}
	case 3:
	{
		cout << "请输入新密码：" << endl;
		string npwd;
		std::cin >> npwd;
		changePassword(npwd);
		goto newpwd;
	}
	}
}

boss::~boss()
{
	std::ofstream out{ "boss.dat",std::ios::binary | std::ios::out };
	if (!out.is_open())
	{
		std::cout << "disopened";
	}
	out.write(password.c_str(), password.length());
	//std::cout << "saved";
	out.close();
}

void boss::changePassword(std::string pwd)
{
	std::ofstream out("boss.dat", std::ios::binary);
	if (out)
	{
		out.write(pwd.c_str(), pwd.length());
		out.close();
		std::cout << "Data saved." << std::endl;
	}
}

std::string boss::getPassword()
{
	std::cout << password << std::endl;
	return password;
}