#include<Windows.h>

#include"runApp.h"
#include"board.h"
#include "boss.h"

using std::cout;
using std::endl;
using std::cin;

runApp::runApp()
{
	system("title #餐厅管理系统系统#");
	cout << "***********************************" << endl;
	cout << "*******  餐厅管理系统系统  ********" << endl;
	cout << "******      1.点餐系统      *******" << endl;
	cout << "******      2.管理系统      *******" << endl;
	cout << "***********************************" << endl;
	cout << "请选择要执行的功能：,按0退出" << endl;
	int pos{ -999 };
	cin >> pos;
	switch (pos)
	{
	case 0: return;
	case 1:
	{
		board theBoard;
		break;
	}
	case 2:
	{
		boss theBoss;
		break;
	}
	case 3:
	{
		break;
	}
	}
}

runApp::~runApp()
{
}