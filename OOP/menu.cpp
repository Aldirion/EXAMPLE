#include <Windows.h>
#include <InteractiveConsole.h>
#include <conio.h>
#include "menu.h"
#include "Struct.h"
#include "THotel.h"
#include "T2DVector.h"
#include "GraphObject.h"
#include <iostream>
#include <string>
using namespace std;

//#define DOWN 80
//#define UP 72
#define menu_size 6

extern bool exit_m;
char ** Menu = new char*[menu_size] { "Динамический массив структур", "Классы в C++", "Перегрузка операторов и дружественные функции", "Наследование", "Шаблоны", "Исключения" };

menu::menu()
{
	exit_m = false;
	while (!exit_m)
	{
		set_color(White, Black);
		system("cls");
		menu::m_interface();
	}
	menu::~menu();
}

void menu::m_interface()
{
	/*
	bool exit = false;
	int i = 0;
	int action = 0;
	A:
	show_cursor(false);
	set_color(Black, LightGray);
	cout << Menu[0] << endl;
	set_color(White, Black);
	for (int i = 1; i < menu_size; i++)
	cout << Menu[i] << endl;
	B:
	action = _getch();
	//cout << action << "\t" << VK_RETURN;
	switch (action)
	{
	case DOWN:
	{
	if (i < menu_size-1)
	{
	show_cursor(false);
	set_color(White, Black);
	system("cls");
	i++;
	for (int j = 0; j < menu_size; j++)
	{
	if (j != i)
	{
	set_color(White, Black);
	cout << Menu[j] << "\n";
	}
	else
	{
	set_color(Black, LightGray);
	cout << Menu[j] << "\n";
	}
	}
	}
	goto B;
	break;
	}
	case UP:
	{
	show_cursor(false);
	if (i > 0)
	{
	set_color(White, Black);
	system("cls");

	--i;
	for (int j = 0; j < menu_size; j++)
	{
	if (j != i)
	{
	set_color(White, Black);
	cout << Menu[j] << endl;
	}
	else
	{
	set_color(Black, LightGray);
	cout << Menu[j] << endl;
	}
	}
	}
	goto B;
	break;
	}
	case VK_ESCAPE:
	{
	set_color(White, Black);
	menu::pre_destructor();
	exit_m = true;
	break;
	}
	case VK_RETURN:
	{
	set_color(White, Black);
	menu::choose(i+1);
	}
	default:
	{
	goto B;
	}
	}
	if (exit_m == false)
	goto A;*/
	choose(menu_interface(Menu, menu_size));
}

void menu::pre_destructor()
{
	system("cls");
	cout << "That`s end! Thank you for using this application. (c)Mikhail Sokolov 2018\n";
}

void menu::choose(int chs)
{
	switch (chs)
	{

	case 1:
	{
		show_cursor(true);
		system("cls");
		lab_1_20_start();
		break;
	}
	case 2:
	{
		show_cursor(true);
		system("cls");
		THotel start;
		start.HList_Def();
		break;
	}
	case 3:
	{
		show_cursor(true);
		system("cls");
		T2DVector start;
		start.menu();
		break;
	}
	case 4:
	{
		show_cursor(true);
		GraphObjectMenu();
		break;
	}
	case 5:
	case 6:
	{
		system("cls");
		cout << "Эта функция пока недоступна. Нажмите UP, чтобы продолжить.\n";
		break;
	}
	case -1:
	{
		menu::pre_destructor();
		exit_m = true;
		break;
	}
	default:
	{
		system("cls");
		cout << "Что-то пошло не так;(\n";
		Sleep(1000);
	}
	}
}
menu::~menu()
{
}