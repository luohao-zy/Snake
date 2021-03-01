#pragma once
#include <Windows.h>
#include <mmsystem.h>//背景音乐的头文件
#pragma comment(lib, "WINMM.LIB")//背景音乐的头文件
#include<dsound.h>//背景音乐的头文件
#include"food.h"
#include"pch.h"
#include"snake.h"
#include"unit.h"
#include<fstream>
class control
{
public:
	COORD m_coor;             //一个字符在控制台屏幕上的坐标
	static  int LEVEL;
	static  int SCORE;
public:
	control();
	~control();
	void drawGameArea();
	void drawGameInfo();
	void showMenu();
	int controlSnake();
	void snakeMusic();
};

