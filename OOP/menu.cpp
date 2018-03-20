#include <Windows.h>
#include <InteractiveConsole.h>
#include <conio.h>
#include <iostream>
#include <string>
#include "menu.h"
#include "Struct.h"
#include "THotel.h"
#include "T2DVector.h"
#include "GraphObject.h"
#include "Templates.h"

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
		start.~THotel();
		break;
	}
	case 3:
	{
		show_cursor(true);
		system("cls");
		T2DVector start;
		start.menu();
		start.~T2DVector();
		break;
	}
	case 4:
	{
		show_cursor(true);
		GraphObjectMenu();
		break;
	}
	case 5:
	{
		template_start();
		break;
	}
	case 6:
	{
		system("cls");
		cout << "Эта функция пока недоступна\n";
		Sleep(1000);
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