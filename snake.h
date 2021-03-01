#pragma once
#include <conio.h>
#include"food.h"
#include <vector>
#include "unit.h"
#include"control.h"
typedef enum Dir
{
	KUP, KDOWN, KLEFT, KRIGHT
};
class snake
{
public:
	static int speed;
	int m_HeadX;
	int m_HeadY;
	int m_Len;
	int m_Speed;
	Dir m_Dir;
	vector<unit> m_Body;
public:
	snake(int x = 40, int y = 10, int len = 8, int speed = 500, Dir dir = KRIGHT, char pic = '#');
	~snake();
	void showSnake();
	void eraseSnake();
	void listen_key_borad();
	bool eatFood(food* Food);
	bool ifDeath();
	bool ifDeathself();
	void move();
	void addSpeed();
};