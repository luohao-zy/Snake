#pragma once
#include <Windows.h>
#include <mmsystem.h>//�������ֵ�ͷ�ļ�
#pragma comment(lib, "WINMM.LIB")//�������ֵ�ͷ�ļ�
#include<dsound.h>//�������ֵ�ͷ�ļ�
#include"food.h"
#include"pch.h"
#include"snake.h"
#include"unit.h"
#include<fstream>
class control
{
public:
	COORD m_coor;             //һ���ַ��ڿ���̨��Ļ�ϵ�����
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

