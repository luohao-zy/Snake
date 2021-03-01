#include "pch.h"
#include "food.h"


food::food()
{

}

food::~food()
{

}

void food::CreatPos()
{
	//todo;
	//m_x = randromNum();
	//m_y = randromNum();
	srand((int)time(0));
	m_x = KLEFT+1+rand() % (KWIDTH-2);
	m_y = KUP+3+rand() % (KHEIGHT -2);
}