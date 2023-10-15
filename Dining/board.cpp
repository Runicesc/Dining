#include<stdlib.h>
#include<fstream>
#include<filesystem>
#include <iostream>

#include "board.h"
#include "runApp.h"
#include "food.h"
#include "menu.h"
#include"employee.h"

using std::cout;
using std::endl;
using std::cin;

board::board()
{
	system("cls");
	cout << "***********************************" << endl;
	cout << "*******  餐厅管理系统系统  ********" << endl;
	cout << "******      选择服务员     *******" << endl;
	cout << "***********************************" << endl;
	cout << "请选择要执行的功能,按0退出" << endl;
	int select{ -999 };
	cin >> select;
	switch (select)
	{
	case 0:
	{
		system("cls");
		runApp RunApp;
		break;
	}
	case 1:
	{
		system("cls");
		int no{ 0 };
		cout << "***********************************" << endl;
		cout << "*********  请选择服务员  **********" << endl;
		employee Employee;
		std::vector<employee> loadedData = employee::loadData();
		int i{ 1 };
		for (const auto& e : loadedData)
		{
			std::cout << i++ << "Name: " << e.name << ", Gender: " << e.gender << std::endl;
		}
		cout << "***********************************" << endl;
		cout << "请选择服务员" << endl;
		cin >> no;
		switch (no)
		{
		case 0:
		{
			system("cls");
			runApp run;
			break;
		}
		case 1:
		{
			std::ofstream out("employee.dat", std::ios::binary | std::ios::trunc);
			loadedData[0].count++;
			loadedData[0].salary += 50;
			if (out) {
				for (const auto& e : loadedData) {
					out << e.name << " " << e.gender << " " << e.count << " " << e.salary << std::endl;
				}
				out.close();
			}
			break;
		}
		case 2:
		{
			std::ofstream out("employee.dat", std::ios::binary | std::ios::trunc);
			loadedData[1].count++;
			loadedData[1].salary += 50;
			if (out) {
				for (const auto& e : loadedData) {
					out << e.name << " " << e.gender << " " << e.count << " " << e.salary << std::endl;
				}
				out.close();
			}
			break;
		}
		case 3:
		{
			std::ofstream out("employee.dat", std::ios::binary | std::ios::trunc);
			loadedData[2].count++;
			loadedData[2].salary += 50;
			if (out) {
				for (const auto& e : loadedData) {
					out << e.name << " " << e.gender << " " << e.count << " " << e.salary << std::endl;
				}
				out.close();
			}
			break;
		}
		case 4:
		{
			std::ofstream out("employee.dat", std::ios::binary | std::ios::trunc);
			loadedData[3].count++;
			loadedData[3].salary += 50;
			if (out) {
				for (const auto& e : loadedData) {
					out << e.name << " " << e.gender << " " << e.count << " " << e.salary << std::endl;
				}
				out.close();
			}
			break;
		}
		case 5:
		{
			std::ofstream out("employee.dat", std::ios::binary | std::ios::trunc);
			loadedData[4].count++;
			loadedData[4].salary += 50;
			if (out) {
				for (const auto& e : loadedData) {
					out << e.name << " " << e.gender << " " << e.count << " " << e.salary << std::endl;
				}
				out.close();
			}
			break;
		}
		case 6:
		{
			std::ofstream out("employee.dat", std::ios::binary | std::ios::trunc);
			loadedData[5].count++;
			loadedData[5].salary += 50;
			if (out) {
				for (const auto& e : loadedData) {
					out << e.name << " " << e.gender << " " << e.count << " " << e.salary << std::endl;
				}
				out.close();
			}
			break;
		}
		}
		//开始点菜
		system("cls");
		cout << "***********************************" << endl;
		cout << "**********     菜单     ***********" << endl;

		//显示菜单内容
		std::vector<food> loadedFoods = food::loadData();
		for (const auto& f : loadedFoods)
		{
			std::cout << "Name: " << f.name << ", Price: " << f.price << std::endl;
		}
		int money{ 0 };
		std::vector<menu>Menu;
	loop:cout << "请点菜：  ,按0结束" << endl;
		int fn{ -1 };
		cin >> fn;
		menu m;
		if (fn != 0)
		{
			cout << "请选择份数：" << endl;
			int count{ 0 };
			cin >> count;
			m.name = loadedFoods[static_cast<std::vector<food, std::allocator<food>>::size_type>(fn) - 1].name;
			m.count = count;
			Menu.push_back(m);
			money += loadedFoods[static_cast<std::vector<food, std::allocator<food>>::size_type>(fn) - 1].price * count;
			goto loop;
		}
		cout << "您的账单总额为:" << money << endl;
		cout << "你的账单为:" << endl;
		for (const auto& x:Menu)
		{
			cout << x.name << "  " << x.count << "  " << std::endl;
		}
	}
	}
}

board::~board()
{
}