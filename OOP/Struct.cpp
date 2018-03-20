#define _CRT_SECURE_NO_WARNINGS
#include "Struct.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#define KEY "products"
using namespace std;

void lab_1_20_start()
{
	fill();
A:
	system("cls");
	char *filename = new char[40];
	system("dir");
	cout << "Введите имя файла или -1, чтобы вернуться в главное меню:\n\n\n>>> ";
	cin >> filename;
	if (atoi(filename) != -1)
	{
		fstream fin(filename, ios::in);
		if (fin)
		{
			char * keys = new char[30];
			system("cls");
			fin.getline(keys, 30);
			keys = strtok(keys, " ");
			if (!strcmp(keys, KEY))
			{
				keys = strtok(NULL, "\n\0");
				Product* product = new Product[atoi(keys)];
				struct_input(product, atoi(keys), fin);
				fin.close();
				struct_sort(product, atoi(keys));
				struct_output(product, atoi(keys));
				system("pause");
				system("cls");
				cout << "Для продолжения нажмите DOWN";
			}
			else
			{
				system("cls");
				cout << "Что-то пошло не так ;(";
				Sleep(1000);
				goto A;
			}
		}
		else
		{
			system("cls");
			cout << "Что-то пошло не так ;(\n";
			Sleep(1000);
			goto A;
		}
	}
	else
	{
		system("cls");
		cout << "Для продолжения нажмите UP/DOWN";
		//Sleep(1000);
		//system("cls");
	}
}

void fill()
{
	cout.fill('#');
}

void struct_input(Product *p, int count, fstream& fin)
{
	int i = 0;
	while (!fin.eof() && i<count)
	{
		char* line = new char[80];
		fin.getline(line, 79);
		strtok(line, "|");
		strcpy((p + i)->date, line);
		line = strtok(NULL, "|");
		strcpy((p + i)->type, line);
		line = strtok(NULL, "|");
		strcpy((p + i)->name, line);
		line = strtok(NULL, "|");
		(p + i)->count = atoi(line);
		cout << setw(10) << (p + i)->date << setw(10) << (p + i)->type << setw(10) << (p + i)->name << setw(10) << (p + i)->count << "\n";
		i++;
	}
}

void struct_sort(Product *p, int count)
{
	Product temp;
	int x = 0, y = 0;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < count - 1; i++)
		{
			if ((x = (p + i)->count) < (y = (p + i + 1)->count))
			{
				temp = *(p + i);
				*(p + i) = *(p + i + 1);
				*(p + i + 1) = temp;
				exit = false;
			}
		}
	}
}

void struct_output(Product *p, int c)
{
	fstream fout("output.txt", ios::out);
	fout << setw(10) << "date" << setw(10) << "type" << setw(10) << "name" << setw(10) << "count\n";
	cout << "\n\n\n";
	for (int i = 0; i < c; i++)
	{
		//вывод на экран
		cout << setw(10) << (p + i)->date << setw(10) << (p + i)->type << setw(10) << (p + i)->name << setw(10) << (p + i)->count << "\n";
		//вывод всей сводки в общий файл
		fout << setw(10) << (p + i)->date << setw(10) << (p + i)->type << setw(10) << (p + i)->name << setw(10) << (p + i)->count << "\n";
	}
	fout.close();
}