#include "GraphObject.h"
#include <Windows.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include <InteractiveConsole.h>

using namespace std;
//menu
void GraphObjectMenu()
{
S:
	system("cls");
	char **create = new char*[2]{ "����������� ������","������ ����������� ��������" };
	int choice = menu_interface(create, 2);
	switch (choice)
	{
	case 1:
	{
	A:
		system("cls");
		GraphObject * obj;
		char** figure = new char*[3]{ "����������","�������","�����������" };
		int type = menu_interface(figure, 3);
		system("cls");
		switch (type)
		{
		case 1:
		{
			obj = &Circle();
			obj->Set();
			obj->calc();
			system("pause");
			goto A;
			break;
		}
		case 2:
		{
			obj = &Square();
			obj->Set();
			obj->calc();
			system("pause");
			goto A;
			break;
		}
		case 3:
		{
			obj = &Triangle();
			obj->Set();
			obj->calc();
			system("pause");
			goto A;
			break;
		}
		case -1:
		{
			goto S;
		}
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "������� ���������� ��������� ������� ����������� ��������\n\n\n>>> ";
		int n;
		cin >> n;
		system("cls");
		GraphObjectSeries **obj = new GraphObjectSeries*[n];
		for (int i = 0; i < n; i++)
		{
			int type = 0;
			type = 1 + rand() % 3;
			switch (type)
			{
			case 1:
			{
				obj[i] = &Square();
				obj[i]->Set();
				obj[i]->calc();
				break;
			}
			case 2:
			{
				obj[i] = &Circle();
				obj[i]->Set();
				obj[i]->calc();
				break;
			}
			case 3:
			{
				obj[i] = &Triangle();
				obj[i]->Set();
				obj[i]->calc();
				break;
			}
			}
		}
		char **out = new char*[2]{ "�������, ������� ������� ��������� � ��������� (X,Y)","�������, �������� ������� ��������� � ���������(X,Y)" };
		int tout = menu_interface(out, 2);
		if (tout > 0 && tout < 3)
		{
			system("cls");
			cout << "������� ��������������� X, Y\n\n\n>>> ";
			int X(0), Y(0);
			cin >> X >> Y;
			system("cls");
			for (int i = 0; i < n; i++)
			{
				if (obj[i]->output(i, tout, X, Y) == 1)
					cout << obj[i]->Get() << "\n";
			}
			system("pause");
		}
		goto S;
		break;
	}
	case -1:
	{
		break;
	}
	}
}
//
//actions

void GraphObjectSeries::calc()
{
	area = Area();
	perimeter = Perimeter();
}
bool GraphObjectSeries::output(int ind, int type, int _x, int _y)
{
	switch (type)
	{
	case 1:
	{

		if (area > _x && area < _y)
		{
			cout << ind + 1 << ". ������� = " << area;
			return 1;
		}
		else return 0;
	}
	case 2:
	{
		if (perimeter > _x && perimeter < _y)
		{
			cout << ind + 1 << ". �������� = " << area;
			return 1;
		}
		else return 0;
	}
	}
}
void GraphObject::calc()
{
A:
	system("cls");
	char** calculate = new char*[2]{ "��������","�������" };
	int type=menu_interface(calculate, 2);
	switch (type)
	{
	case 1:
	{
		system("cls");
		cout << "����������� �������� = " << Perimeter() << "\n";
		break;
	}
	case 2:
	{
		system("cls");
		cout << "����������� ������� = " << Area() << "\n";
		break;
	}
	case -1:
	{
		break;
	}
	default:
	{
		system("cls");
		cout << "���-�� ����� �� ���;( ���������� ��� ���";
		Sleep(1000);
		goto A;
	}
	}
}
double Square::Perimeter()
{
	return abs(side * 4);
}
double Square::Area()
{
	return pow(side, 2);
}
double Circle::Perimeter()
{
	return abs(radius*3.14);
}
double Circle::Area()
{
	return 3.14*pow(radius, 2);
}
double Triangle::Perimeter()
{
	return A + B + C;
}
double Triangle::Area()
{
	return 1. / 2 * A * H;
}
//
//sets
void Square::Set()
{
	system("cls");
	cout << "������� ����� ������� �������� >>> ";
	cin >> side;
}
int Square::Get()
{
	cout << "\t�������: ������� = ";
	return side;
}
void Circle::Set()
{
	system("cls");
	cout << "������� ������ >>> ";
	cin >> radius;
}
int Circle::Get()
{
	cout << "\t����: ������ = ";
	return radius;
}
void Triangle::Set()
{
	system("cls");
	cout << "������� �������� ��� A, B, C, H:\n\n\n>>> ";
	cin >> A >> B >> C >> H;
}
int Triangle::Get()
{
	cout << "\t�����������: A=" << A << " B=" << B << " C=" << C << " H=";
	return H;
}
//

//Series