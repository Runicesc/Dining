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
	cout << "*******  ��������ϵͳϵͳ  ********" << endl;
	cout << "******      ���������룺    *******" << endl;
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
		cout << "�������,����������" << endl;
		std::cin >> pwd;
	}
manage:system("cls");
	cout << "***********************************" << endl;
	cout << "*******      ��ѡ����     *******" << endl;
	cout << "*******      1.Ա������     *******" << endl;
	cout << "*******      2.�˵�����     *******" << endl;
	cout << "*******      3.�����޸�     *******" << endl;
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
		cout << "ѡ���ܣ�1.����Ա�� 2.ɾ��Ա������0����" << endl;
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
		cout << "�鿴�˵�" << endl;
		std::vector<food> loadedFoods = food::loadData();
		for (const auto& f : loadedFoods)
		{
			std::cout << "Name: " << f.name << ", Price: " << f.price << std::endl;
		}
		int t{ 0 };
		cout << "1.���Ӳ�Ʒ2.ɾ����Ʒ,��0�˳�" << endl;
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
		cout << "�����������룺" << endl;
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