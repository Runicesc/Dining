#include<Windows.h>

#include"runApp.h"
#include"board.h"
#include "boss.h"

using std::cout;
using std::endl;
using std::cin;

runApp::runApp()
{
	system("title #��������ϵͳϵͳ#");
	cout << "***********************************" << endl;
	cout << "*******  ��������ϵͳϵͳ  ********" << endl;
	cout << "******      1.���ϵͳ      *******" << endl;
	cout << "******      2.����ϵͳ      *******" << endl;
	cout << "***********************************" << endl;
	cout << "��ѡ��Ҫִ�еĹ��ܣ�,��0�˳�" << endl;
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