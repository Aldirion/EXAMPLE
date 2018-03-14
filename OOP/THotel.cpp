#define _CRT_SECURE_NO_WARNINGS
#define KEY "hotels"
#include "THotel.h"
#include <InteractiveConsole.h>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
//#include <stdio.h>
using namespace std;



THotel::THotel()
{
}

void THotel::information()
{
	cout<< setw(10) << "NAME" << setw(10) << "CITY" << setw(10) << "STARS"
		<< setw(10) << "VIP" << setw(10) << "FAMILY" << setw(10) << "DUAL"
		<< setw(10) << "SINGLE\n";
}

void THotel::menu(THotel *obj, int c)
{
A:
	system("cls");
	char ** menu_1 = new char*[3] {"Список всех отелей в городе", "Количество конкретных номеров > X", "Количество всех номеров > X"};
	int a = menu_interface(menu_1, 3);
	switch (a)
	{
	case 1:
	{
	B:
		system("cls");
		char** city = new char*[5] {"New York", "Chickago", "Dallas", "London", "Вернуться к выбору действия" };
		int a = menu_interface(city, 5);
		switch (a)
		{
		case 1:
		{
			THotel::city_sort(obj, c, " New York ");
			goto B;
			break;
		}
		case 2:
		{
			THotel::city_sort(obj, c, " Chickago ");
			goto B;
			break;
		}
		case 3:
		{
			THotel::city_sort(obj, c, " Dallas   ");
			goto B;
			break;
		}
		case 4:
		{
			THotel::city_sort(obj, c, " London   ");
			goto B;
			break;
		}
		case 5:
		{
			system("cls");
			cout << "Одну секунду";
			Sleep(1000);
			goto A;
			break;
		}
		case -1:
		{
			system("cls");
			cout << "Одну секунду";
			Sleep(1000);
			break;
		}
		default:
		{
			system("cls");
			cout << "Что-то пошло не так, попробуйте ещё раз";
			Sleep(1000);
			goto B;
			break;
		}
		}
		goto A;
		break;
	}
	case 2:
	{
		THotel::chamber_c(obj, c);
		goto A;
		break;
	}
	case 3:
	{
		THotel::quantity_c(obj, c);
		goto A;
		break;
	}
	case -1:
		break;
	default:
	{
		cout << "Что-то пошло не так, попробуйте ещё раз.";
		Sleep(1000);
		goto A;
		break;
	}
	}
}

void THotel::chamber_c(THotel *obj, int c)
{
A:
	system("cls");
	char **type = new char*[5]{ "VIP","FAMILY","DUAL","SINGLE","Вернуться к выбору действия" };
	int a = menu_interface(type, 5), X = 0;
	system("cls");
	cout << "Введите необходимое количество комнат:\n\n>>> ";
	cin >> X;
	switch (a)
	{
	case 1:
	{
		system("cls");
		THotel::information();
		for (int i = 0; i < c; i++)
			if ((obj + i)->count.VIP > X)
				THotel::output(obj + i);
		system("pause");
		break;
	}
	case 2:
	{
		system("cls");
		THotel::information();
		for (int i = 0; i < c; i++)
			if ((obj + i)->count.family > X)
				THotel::output(obj + i);
		system("pause");
		break;
	}
	case 3:
	{
		system("cls");
		THotel::information();
		for (int i = 0; i < c; i++)
			if ((obj + i)->count.dual > X)
				THotel::output(obj + i);
		system("pause");
		break;
	}
	case 4:
	{
		system("cls");
		THotel::information();
		for (int i = 0; i < c; i++)
			if ((obj + i)->count.single > X)
				THotel::output(obj + i);
		system("pause");
		break;
	}
	case -1:
	{
		system("cls");
		THotel::information();
		cout << "Одну секунду";
		Sleep(1000);
		break;
	}
	}
}

void THotel::quantity_c(THotel *obj, int c)
{
	system("cls");
	cout << "Введите необходимое количество комнат, или -1, чтобы вернуться к выбору действия;\n\n>>> ";
	int X = 0;
	cin >> X;
	if (X != -1)
	{
		THotel::information();
		for (int i = 0; i < c; i++)
			if ((obj + i)->count.VIP + (obj + i)->count.family + (obj + i)->count.dual + (obj + i)->count.single > X)
				THotel::output(obj + i);
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Одну секунду";
		Sleep(1000);
	}
}

void THotel::output(THotel *obj)
{
	cout
		<< setw(10) << (obj)->name << setw(10) << (obj)->city << setw(10)
		<< (obj)->stars << setw(10) << (obj)->count.VIP << setw(10)
		<< (obj)->count.family << setw(10) << (obj)->count.dual << setw(10)
		<< (obj)->count.single << "\n";
}

void THotel::init(THotel *obj, int c, fstream &fin)
{
	int i = 0;
	system("cls");
	THotel::information();
	while (!fin.eof() && i<c)
	{
		char* line = new char[80];
		fin.getline(line, 79);
		strtok(line, "|");
		(obj + i)->name = line;
		line = strtok(NULL, "|");
		(obj + i)->city = line;
		line = strtok(NULL, "|");
		(obj + i)->stars = atoi(line);
		line = strtok(NULL, "|");
		(obj + i)->count.VIP = atoi(line);
		line = strtok(NULL, "|");
		(obj + i)->count.family = atoi(line);
		line = strtok(NULL, "|");
		(obj + i)->count.dual = atoi(line);
		line = strtok(NULL, "|");
		(obj + i)->count.single = atoi(line);
		output(obj + i);
		i++;
	}
	system("pause");
	THotel::menu(obj, c);
}

void THotel::city_sort(THotel *obj, int c, string city)
{
	THotel temp;
	int x = 0, y = 0;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < c - 1; i++)
		{
			if ((obj + i)->city == city)
			{
				if ((x = (obj + i)->stars) < (y = (obj + i + 1)->stars))
				{
					temp = *(obj + i);
					*(obj + i) = *(obj + i + 1);
					*(obj + i + 1) = temp;
					exit = false;
				}
			}
		}
	}
	system("cls");

	THotel::information();
	for (int i = 0; i < c; i++)
		if ((obj + i)->city == city)
			output(obj + i);
	system("pause");
}

void THotel::HList_Def()
{
	cout.fill(' ');
	char *filename = new char[40];
A:
	system("cls");
	system("dir");
	cout << "Введите имя файла, или -1, чтобы вернуться в главное меню:\n";
	cout << "\n\n>>> ";
	cin >> filename;
	fstream fin(filename, ios::in);
	if (fin)
	{
		system("cls");
		char *keys = new char[30];
		fin.getline(keys, 30);
		strtok(keys, " ");
		if (!strcmp(keys, KEY))
		{
			keys = strtok(NULL, "\n\0");
			int c = atoi(keys);
			THotel *hotels = new THotel[c];
			init(hotels, c, fin);
		}
		else
		{
			system("cls");
			cout << "Что-то пошло не так, попробуйте ещё раз";
			Sleep(1000);
			goto A;
		}
	}
	else if (atoi(filename) == -1)
	{
		system("cls");
		cout << "Для продолжения нажмите UP/DOWN";
		//Sleep(1000);
	}
	else
	{
		system("cls");
		cout << "Что-то пошло не так, попробуйте ещё раз\n";
		Sleep(1000);
		goto A;
	}

}

THotel::~THotel()
{
}