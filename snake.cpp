#include<conio.h>
#include "pch.h"
#include "snake.h"
#include"food.h"
#include"unit.h"
#include"control.h"


int snake::speed=200;

snake::snake(int x, int y, int len, int speed, Dir dir, char pic)
{
	m_HeadX = x;
	m_HeadY = y;
	m_Len = len;
	m_Speed = speed;
	m_Dir = dir;

	for (int i = 0; i < m_Len; i++)
	{
		unit myUnit(0, 0, pic);
		m_Body.push_back(myUnit);
		
		switch (dir)
		{
		case KUP:
			//m_Body[i].m_x = m_HeadX;
			//m_Body[i].m_y = m_HeadY - i;
			break;
		case KDOWN:
			//m_Body[i].m_x = m_HeadX;
			//m_Body[i].m_y = m_HeadY + i;
			break;
		case KLEFT:
			//m_Body[i].m_x = m_HeadX + i;
			//m_Body[i].m_y = m_HeadY;
			break;
		case KRIGHT:
			
			m_Body[i].m_x = m_HeadX - i;
			m_Body[i].m_y = m_HeadY;
			break;
		default:
			break;
		}
	}
}


snake::~snake()
{

}

void snake::showSnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].show();
	}
}

void snake::eraseSnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].erase();
	}
}
bool snake::ifDeathself() {
	for (int i = 1; i < m_Len; i++) {
		if (this->m_Body[0].m_x == this->m_Body[i].m_x && this->m_Body[0].m_y == this->m_Body[i].m_y) {
			
			return 1;
		}
		
	}
	return 0;
}
bool snake::ifDeath() {
	//const int unit::KWIDTH = 70;
	//const int unit::KHEIGHT = 20;
	//const int unit::KUP = 1;
	//const int unit::KLEFT = 2;
	//m_x = KLEFT + 1 + rand() % (KWIDTH - 2);
	//m_y = KUP + 3 + rand() % (KHEIGHT - 2);
	if (this->m_Body[0].m_x == KLEFT || this->m_Body[0].m_x ==unit:: KWIDTH + KLEFT-2 || this->m_Body[0].m_y == KUP + 3 || this->m_Body[0].m_y == unit::KHEIGHT + KUP+2 ) {
		return true;
	}
	else {
		return false;
	}
}
bool snake::eatFood(food* Food) {
	if (Food->m_x == this->m_Body[0].m_x && Food->m_y == this->m_Body[0].m_y) {
		this->m_Len += 1;
		Food->CreatPos();
		Food->show();
		control::SCORE += 10;
		unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);

		cout << "当前得分 " << control::SCORE;

		//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

		//cout << m_iScore;
		if (control::SCORE % 50 == 0) {
			control::LEVEL += 1;
			this->snake::addSpeed();
		}
		unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);

		cout << "当前关卡 " << control::LEVEL;

		return 1;
		//unit myUnit(0, 0, '$');
		//m_Body.push_back(myUnit);
	}
	else {
		m_Body.erase(m_Body.end() - 1);
		return 0;
	}

}


void snake::listen_key_borad()
{
	char ch;

	if (_kbhit())                    //kbhit 非阻塞函数 
	{
		ch = _getch();    //使用 getch 函数获取键盘输入 
		
		if (ch == 72) {
			ch = 'w';
		}
		if (ch == 80) {
			ch = 's';
		}
		if (ch == 75) {
			ch = 'a';
		}
		if (ch == 77) {
			ch = 'd';
		}
		



		switch (ch)
		{
		case ' ':_getch(); break;
		case 'w':
		case 'W':
		case '\72':
			if (this->m_Dir == KDOWN)
				break;
			this->m_Dir = KUP;
			break;
		case 's':
		case 'S':
			if (this->m_Dir == KUP)
				break;
			this->m_Dir = KDOWN;
			break;
		case 'a':
		case 'A':
			if (this->m_Dir == KRIGHT)
				break;
			this->m_Dir = KLEFT;
			break;
		case 'd':
		case 'D':
			if (this->m_Dir == KLEFT)
				break;
			this->m_Dir = KRIGHT;
			break;
		}
	}
}

void snake::addSpeed() {
	snake::speed -= 20;
}

void snake::move()
{
	//实现蛇身的移动 body move
	listen_key_borad();
	/*for (int i = m_Len - 1; i > 0; i--)
	{
		m_Body[i].m_x = m_Body[i - 1].m_x;
		m_Body[i].m_y = m_Body[i - 1].m_y;
	}*/
	//实现蛇头的移动  head move
	//char dir_1;
	//dir_1 = getchar();
	vector<unit> head = m_Body;
	switch (m_Dir)
	{
	case KUP:
		head[0].m_y--;
		//m_Body[0].m_y--;
		break;
	case KDOWN:
		head[0].m_y++;
		//m_Body[0].m_y++;
		break;
	case KLEFT:
		head[0].m_x--;
		//m_Body[0].m_x--;
		break;
	case KRIGHT:
		head[0].m_x++;
		//m_Body[0].m_x++;
		break;
	default:
		break;
	}
	
	m_Body.insert(m_Body.begin(), head[0]);
	showSnake();
	Sleep(speed);
	eraseSnake();
}