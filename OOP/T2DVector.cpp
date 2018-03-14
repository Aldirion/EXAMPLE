#define _CRT_SECURE_NO_WARNINGS
#include "T2DVector.h"
#include <math.h>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <string>
#include <InteractiveConsole.h>


using namespace std;

extern bool sorted = false;//позволяет облегчить поиск максимальной длины вектора

#define size_1 2
#define size_2 4

char ** menu_1 = new char*[size_1] {"Ввести значения с клавиатуры", "Сгенерировать случайные значения"};
char ** menu_2 = new char*[size_2] {"Отсортировать по длине", "Найти вектор максимальной длины", "Вывести массив", "Перезапустить"};

//operator
T2DVector T2DVector::operator --(int)
{
	T2DVector tmp(*this);
	--(*this);
	return tmp;
}
T2DVector &T2DVector::operator +(const T2DVector &p) const
{
	return T2DVector(X + p.X, Y + p.Y);
}
T2DVector &T2DVector::operator -(const T2DVector &p) const
{

	return T2DVector(X - p.X, Y - p.Y);
}
T2DVector T2DVector::operator ++(int)
{
	T2DVector tmp(*this);
	++(*this);
	return tmp;
}
T2DVector &T2DVector::operator ++()
{
	X++;
	Y++;
	return *this;
}
T2DVector &T2DVector::operator --()
{
	X--;
	Y--;
	return *this;
}
ostream &operator <<(ostream &_out, const T2DVector &_p)
{
	_out << " (" << _p.X << ", " << _p.Y << ")\n";
	return _out;
}

istream &operator >>(istream &_in, T2DVector &_p)
{
	_in >> _p.X >> _p.Y;
	return _in;
}
//operator

//methods T2DVector
void T2DVector::GenerateRandomValues()
{
	this->X = rand() % 100 - 50;
	this->Y = rand() % 100 - 50;
}
void T2DVector::Set()
{
	system("cls");
	cout << "Введите значения для X и Y\n";
	cin >> *this;
}
void T2DVector::menu() {
A:
	fstream fout("log.txt", ios::app);
	//	time_t t;
	system("cls");
	ShowCursor(true);
	cout << "Введите количество элементов массива или 0, чтобы вернуться в главное меню, или -1, чтобы начать заново с очисткой лога.:\n\n\n>>> ";
	int n;
	cin >> n;
	if (n > 0)
	{
		system("cls");
		srand(time(NULL));
		T2DVector *Arr = new T2DVector[n];
		T2DVectorAnalizer obj;
		//		time(&t);
		//		cout << "Time: "   << "Action: initializating of array\n\n";
		//		fout << "\nTime: "   << "Action: initializating of array\n\n";

	B:
		system("cls");
		int choice = menu_interface(menu_1, size_1);
		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
			{
				(Arr + i)->Set();
			}
			system("cls");
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ". ";
				obj.ShowData(*(Arr + i), fout);
			}
			sorted = false;
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			for (int i = 0; i < n; i++)
			{
				(Arr + i)->GenerateRandomValues();
				cout << i + 1 << ". ";
				obj.ShowData(*(Arr + i), fout);
			}
			sorted = false;
			system("pause");
			break;
		}
		default:
		{
			cout << "Что-то пошло не так ;( Попробуйте ещё раз.\n";
			Sleep(1000);
			goto B;
		}
		}
	C:
		system("cls");
		//cout << "What do you want to do?\n\n1. Sort by length;\n2. Search vector with maximal length;\n3. Show array;\n4. Restart;\n0. Return to main menu;\n\n\n>>> ";
		int ch = menu_interface(menu_2, size_2);
		//cin >> ch;
		switch (ch)
		{
		case 1:
		{
			system("cls");
			int err = 0;
			cout << "\nTime: " << "Действие: Сортировка массива\n\n";
			fout << "\nTime: " << "Действие: Сортировка массива\n\n";
			err = obj.Sort(Arr, n);
			if (err == 1)
			{
				system("cls");
				cout << "\nTime: " << "Сортировка произведена, отсортированный массив:\n\n";
				fout << "\nTime: " << "Сортировка произведена, отсортированный массив:\n\n";
				for (int i = 0; i < n; i++)
				{
					cout << i + 1 << ". ";
					obj.ShowData(*(Arr + i), fout);
				}
				sorted = true;
				//fout.close();
			}
			else
			{
				system("cls");
				cout << "Слишком мало элементов для сортировки.\n";
				Sleep(1000);
				goto A;
			}
			system("pause");
			goto C;
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nTime: " << time() << "Действие: Поиск вектора максимальной длины\n\n";
			fout << "\nTime: " << time() << "Действие: Поиск вектора максимальной длины\n\n";
			int ind(0);
			sorted ? (ind = n - 1) : (ind = obj.SearchMaxLength(Arr, n));
			cout << ind + 1 << ". Максимальная длина:" << (Arr + ind)->Length() << "\n";
			fout << ind + 1 << ". Максимальная длина:" << (Arr + ind)->Length() << "\n";
			obj.ShowData(*(Arr + ind), fout);
			system("pause");
			goto C;
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nTime: " << time() << "Действие: Вывести массив\n\n";
			fout << "\nTime: " << time() << "Действие: Вывести массив\n\n";
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ". ";
				fout << i + 1 << ". ";
				obj.ShowData(*(Arr + i), fout);
			}
			system("pause");
			goto C;
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Одну секунду.\n";
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
			cout << "Что-то пошло не так;( Попробуйте ещё раз";
			Sleep(1000);
			goto C;
			break;
		}
		}
	}
	else if (n == 0)
	{
		system("cls");
		cout << "Для продолжения нажмите UP/DOWN";
	}
	else if (n == -1)
	{
		system("cls");
		cout << "Подтвердите действие: перезапуск лога(Y/N)\n";
		char confirmation;
		cin >> confirmation;
		switch (confirmation)
		{
		case 'y':
		case 'Y':
		{
			cout << "Одну секунду";
			Sleep(1000);
			fout.close();
			fout.open("log.txt", ios::out);
			fout.close();
			system("cls");
			goto A;
			break;
		}
		case 'n':
		case 'N':
		{
			cout << "Одну секунду";
			Sleep(1000);
			system("cls");
			goto A;
			break;
		}
		}
	}
	else
	{
		system("cls");
		cout << "Количество не может быть отрицательным";
		Sleep(1000);
		goto A;
	}
}
void T2DVector::Swap()
{
	T2DVector temp = *(this);
	*(this) = *(this + 1);
	*(this + 1) = temp;
}
double T2DVector::Length()
{
	return sqrt(pow(this->X, 2) + pow(this->Y, 2));
}
//
//constructors & destructor
T2DVector::T2DVector(double _x, double _y) :X(_x), Y(_y)
{

}
T2DVector::T2DVector()
{
}
T2DVector::~T2DVector()
{
}
//

//methods T2DVectorAnalizer
int T2DVectorAnalizer::Sort(T2DVector *obj, int c)
{
	if (c > 1)
	{
		bool exit = false;
		while (!exit)
		{
			exit = true;
			for (int i = 0; i < c - 1; i++)
			{

				if ((obj + i)->Length() >(obj + i + 1)->Length())
				{
					(obj + i)->Swap();
					exit = false;
				}
			}
		}
		return 1;
	}
	else
		return -1;
}
int T2DVectorAnalizer::SearchMaxLength(T2DVector *obj, int c)
{
	double max_length = 0;
	int index = 0;
	for (int i = 0; i < c; i++)
	{
		if ((obj + i)->Length()> max_length)
		{
			max_length = (obj + i)->Length();
			index = i;
		}
	}
	return index;
}
void T2DVectorAnalizer::ShowData(const T2DVector &obj, fstream &fout) const
{
	//fstream fout("log.txt", ios::app);
	cout << obj;
	fout << obj;
	//fout.close();
}
//