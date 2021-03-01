#include<Windows.h>
#include "pch.h"
#include "unit.h"

const int unit::KWIDTH = 70;
const int unit::KHEIGHT = 20;
const int unit::KUP = 1;
const int unit::KLEFT = 2;

unit::unit(int x,int y,char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD coor;
	//coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // 关闭标准输出设备句柄
	///*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	//m_coor = coor;
}


unit::~unit()
{

}
void unit::hide() {

	HANDLE han = GetStdHandle(STD_OUTPUT_HANDLE);
	//也可以设置为-11，STD_OUTPUT_HANDLE是一个定值
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	//dwSize的作用是什么？？
	//1-100
	SetConsoleCursorInfo(han, &cursor);




}
void unit::gotoxy(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
	//HANDLE hOut;
	//COORD pos = { x,y };
	//int i;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleCursorPosition(hOut, pos);
	unit::hide();
}

void unit::show()
{
	//todo;
	//todo goto();
	gotoxy(m_x, m_y);
	cout << m_pic;
}

void unit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}

//COORD unit::getWindowInfo()
//{
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coor;
//	coor=GetLargestConsoleWindowSize(hOut);
//	CloseHandle(hOut); // 关闭标准输出设备句柄
//	/*const int KWIDTH = coor.X;
//	const int KHEIGHT = coor.Y;*/
//	m_coor = coor;
//}




