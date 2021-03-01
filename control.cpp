#include <Windows.h>
#include <mmsystem.h>//背景音乐的头文件
#pragma comment(lib, "WINMM.LIB")//背景音乐的头文件
#include<dsound.h>//背景音乐的头文件
#include"food.h"
#include"pch.h"
#include"snake.h"
#include"unit.h"
#include <iostream>


using namespace std;

 int control::LEVEL=1;
 int control::SCORE=0;
control::control()
{
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//m_coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // 关闭标准输出设备句柄
	///*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	///*m_coor = coor;*/
	/*RECT rect;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetClientRect(hOut, &rect);	*/
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;
}

control::~control()
{
}

void control::snakeMusic() {
	mciSendString(TEXT("open C:/01.wma alias mysong"), NULL, 0, NULL);//背景音乐
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//背景音乐
}
int control::controlSnake() {
	snakeMusic();
	
	snake* mySnake = new snake;
	food* myFood = new food;

	this->drawGameArea();
	this->drawGameInfo();
	this->showMenu();
	unit::gotoxy(unit::KLEFT + 25, unit::KUP + 11);
	cout << "请按任意键 游戏开始!!!" << endl;
	_getch();
	unit::gotoxy(unit::KLEFT + 25, unit::KUP + 11);
	cout << "                       " << endl;
//	system("cls");

	myFood->CreatPos();
	myFood->show();
	Sleep(200);
	this->drawGameArea();
	this->drawGameInfo();
	this->showMenu();
	
	mySnake->showSnake();
	Sleep(200);
	mySnake->eraseSnake();

	while (true)
	{
		mySnake->move();
		if (mySnake->ifDeathself() == 1 || mySnake->ifDeath() == 1) {
			system("cls");
			
			this->drawGameArea();
			this->drawGameInfo();
			this->showMenu();
			unit::gotoxy(unit::KLEFT + 30, unit::KUP + 11);
			cout << "游戏结束" << endl;
			unit::gotoxy(unit::KLEFT + 30, unit::KUP +3+unit::KHEIGHT);

			return 0;
			
		}
		mySnake->eatFood(myFood);
	}
}

void control::showMenu(){
	unit::gotoxy(unit::KLEFT + 90, unit::KUP + 1);
	cout << "游戏规则";
	unit::gotoxy(unit::KLEFT + 80, unit::KUP + 3);
	cout << "方向控制: W S A D 上下左右";
	unit::gotoxy(unit::KLEFT + 80, unit::KUP + 5);
	cout << "游戏暂停: 空格键";
	unit::gotoxy(unit::KLEFT + 80, unit::KUP + 7);
	cout << "每吃一个食物后 分数+10";
	unit::gotoxy(unit::KLEFT + 80, unit::KUP + 9);
	cout << "分数每增加五十后 关卡+1";
	unit::gotoxy(unit::KLEFT + 80, unit::KUP + 11);
	cout << "关卡加一后蛇身移动 速度+1";
	unit::gotoxy(unit::KLEFT + 80, unit::KUP + 13);
	cout << "蛇头碰到墙壁和自身后 游戏结束";
}

void control::drawGameArea()
{
	//todo
	/*for (int i = unit::KLEFT; i <=  m_coor.X - 2*unit::KLEFT; i++)
	{
		unit::gotoxy(i, unit::KUP);
		cout << "-";
		unit::gotoxy(i, unit::KUP+2);
		cout << "-";
		unit::gotoxy(i, m_coor.Y - 2*unit::KUP);
		cout << "-";
	}

	for (int i = unit::KUP+1; i <= m_coor.Y -1- 2 * unit::KUP; i++)
	{
		unit::gotoxy(unit::KLEFT, i);
		cout << "|";
		unit::gotoxy(m_coor.X - 2 * unit::KLEFT, i);
		cout << "|";
	}*/
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)
	{
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()
{
	//todo
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);

	cout << "游戏名称：贪吃蛇";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);

	cout << "编写者：***";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);

	cout << "当前得分 "<<control::SCORE;

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);

	cout << "当前关卡 "<<control::LEVEL;

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}
