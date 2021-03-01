#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class unit
{
public:
	int m_x;
	int m_y;
	char m_pic;

	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KUP;
	static const int KLEFT;

public:
	unit(int x=0,int y=0, char  pic ='#');
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);
	static void hide();
	/*COORD getWindowInfo();*/
};

