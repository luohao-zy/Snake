// DemoSnake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include<conio.h>
#include "food.h"
#include "control.h"
#include "snake.h"
#include <iostream>
using namespace std;

int main()
{
 
	control* a = new control;
	a->controlSnake();
	
	delete a;
	return 0;
}
