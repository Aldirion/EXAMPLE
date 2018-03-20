#define _CRT_SECURE_NO_WARNINGS
#include "Templates.h"
#include <iostream>
#include <fstream>
#include <InteractiveConsole.h>
#include <cmath>
#include <iomanip>
using namespace std;


//CONSTANTS

const char* _int = "int.txt";
const char* _float = "float.txt";
const char* _double = "double.txt";
const char* _char = "char.txt";

char ** M_1 = new char*[4]{ "INT", "FLOAT", "DOUBLE", "CHAR" };
char ** M_2 = new char*[3]{ "Сгенерировать случайные значения", "Ввести значения с клавиатуры", "Взять значения из файла" };
char ** M_3 = new char*[6]{ "Сгенерировать случайные значения", "Ввести значения с клавиатуры", "Взять значения из файла", "Изменить значение элемента", "Выполнить действия над матрицей", "Вывести матрицу" };
char ** M_3_1 = new char*[2]{ "Сгенерировать случайное значение для элемента", "Ввести значение для элемента с клавиатуры" };
char ** M_4 = new char*[2]{ "Сдвинуть циклически", "Найти количество минимальных в окружении" };
char ** M_4_1 = new char*[2]{ "Сдвинуть строку", "Сдвинуть столбец" };

//

//VARIABLES
extern char *type_name = new char[80];
extern int _qinp = 0;
extern int _qset = 0;
//

//DEFINATIONS_________________________________________________________________________________________________________________________________________________________________________________


template<class T> class Templates;
//OPERATOR____________________________________________________________________________________________________________________________________________________________________________________

template<class T>
ostream &operator << (ostream &_out, const Templates<T> &_p)
{
	setprecision(9);
	for (int i = 0; i < _p.row; i++)
	{
		for (int j = 0; j < _p.col; j++)
		{
			_out << setw(10) << _p.matrix[i][j];
		}
		_out << "\n";
	}
	return _out;
}

template<class T>
istream &operator >> (istream &_in, Templates<T> &_p)
{
	for (int i = 0; i < _p.row; i++)
	{
		for (int j = 0; j < _p.col; j++)
		{
			_in >> _p.matrix[i][j];
		}
	}
	return _in;
}
//____________________________________________________________________________________________________________________________________________________________________________________________


template <class T>
class Templates
{
protected:
	int col, row;
	T **matrix;
		
public:
	friend ostream &operator << <>(std::ostream &_out, const Templates<T> &_p);
	friend istream &operator >> <>(std::istream &_in, Templates<T> &_p);
	void _inp(Templates<T> &_p);
	void _action(Templates<T> &_p);
	void GenerateRandomValues();
	void SetRandomValue(int, int);
	void Swap(char, int);
	int QuantityOfMin();
	Templates(int = 10, int = 10);
	~Templates();
};
//____________________________________________________________________________________________________________________________________________________________________________________________


//MENU

void template_start()
{
	
S:
	system("cls");
	cout << "Введите последовательно: количество строк и столбцов\n\n\n>>> ";
	int _row(0), _col(0);
	cin >> _row >> _col;
	system("cls");
	int ch = menu_interface(M_1, 4);
	switch (ch)
	{
	case 1:
	{
		Templates<int> obj(_row, _col);
		obj._inp(obj);
		obj.~Templates();
		goto S;
		break;
	}
	case 2:
	{
		Templates<float> obj(_row, _col);
		obj._inp(obj);
		obj.~Templates();
		goto S;
		break;
	}
	case 3:
	{
		Templates<double> obj(_row, _col);
		obj._inp(obj);
		obj.~Templates();
		goto S;
		break;
	}
	case 4:
	{
		Templates<char> obj(_row, _col);
		obj._inp(obj);
		obj.~Templates();
		goto S;
		break;
	}
	case -1:
	{
		_qinp = 0;
		break;
	}
	}
}
template<class T>
void Templates<T>::_inp(Templates<T> &_p)
{
S:
	system("cls");
	int ch(0);
	_qinp > 0 ? ch = menu_interface(M_3, 6) : ch = menu_interface(M_2, 3);
	switch (ch)
	{
	case 1:
	{
		_p.GenerateRandomValues();
		_qinp++;
		goto S;
		break;
	}
	case 2:
	{
		cin >> _p;
		_qinp++;
		goto S;
		break;
	}
	case 3:
	{
		cout << "Эта функция пока недоступна.";
		goto S;
	}
	case 4:
	{
		system("cls");
		int _ch = menu_interface(M_3_1, 2);
		system("cls");
		cout << "Введите индексы элемента через пробел: строка столбец, соответственно \n\n\n>>> ";
		int _col(0), _row(0);
		cin >> _row >> _col;
		system("cls");
		switch (_ch)
		{
		case 1:
		{
			_p.SetRandomValue( _row, _col);
			goto S;
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Элемент: " << matrix[_row][_col] << " заменить на >>> ";
			T change;
			cin >> change;
			_p.matrix[_row][_col] = change;
			goto S;
			break;
		}
		case -1:
		{
			break;
		}
		}
		_qset++;
		break;
	}
	case 5:
	{
		system("cls");
		_p._action(_p);
		goto S;
		break;
	}
	case 6:
	{
		system("cls");
		cout << "Матрица типа " << type_name << ":\n\n" << _p;
		system("pause");
		goto S;
		break;
	}
	case -1:
	{
		_qinp = 0;
		break;
	}
	}
}

template<class T>
void Templates<T>::_action(Templates<T> &_p)
{
S:
	system("cls");
	int _ch = menu_interface(M_4, 2);
	switch (_ch)
	{
	case 1:
	{
		A:
		system("cls");
		int __ch = menu_interface(M_4_1, 2);
		system("cls");
		cout << "Текущая матрица:\n\n" << *this;
		switch (__ch)
		{
		case 1:
		{
			cout << "Введите индекс строки(1.."<<row<<"):\n\n>>> ";
			int _ind(0);
			cin >> _ind;
			Swap('r', _ind-1);
			cout << "\n\nНовая матрица:\n\n" << *this;
			system("pause");
			goto A;
			break;
		}
		case 2:
		{
			cout << "\Введите индекс столбца(1.." << col << "):\n\n>>> ";
			int _ind(0);
			cin >> _ind;
			Swap('c', _ind-1);
			cout << "\n\nНовая матрица:\n\n" << *this;
			system("pause");
			goto A;
			break;
		}
		case -1:
		{
			break;
		}
		}
		goto S;
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Количество минимумов в матрице: " << QuantityOfMin();
		system("pause");
		goto S;
		break;
	}
	case -1:
	{
		break;
	}
	}
}

//CONSTRUCTOR
template<class T>
Templates<T>::Templates(int _row, int _col)
{
	system("cls");
	//cout << typeid(T).name();
	strcpy(type_name, typeid(T).name());
	fstream out("log.txt", ios::app);
	col = _col > 0 ? _col : 10;
	row = _row > 0 ? _row : 10;
	cout << _time() << "\nТИП ДАННЫХ:" << type_name << "КОЛИЧЕСТВО СТОЛБЦОВ = " << col << " КОЛИЧЕСТВО СТРОК = " << row << "\n\n";
	out << _time() << "\nТИП ДАННЫХ:" << type_name << "КОЛИЧЕСТВО СТОЛБЦОВ = " << col << " КОЛИЧЕСТВО СТРОК = " << row << "\n\n";
	matrix = new T*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new T[col];
	}
	if (matrix != NULL)
	{
		cout << "\nВыделение памяти прошло успешно.\n\n";
		out << "\nВыделение памяти прошло успешно.\n\n";
	}
	out.close();
}
//\DESTRUCTOR
//DESTRUCTOR
template<class T>
Templates<T>::~Templates()
{
	if(matrix)
	{
		fstream out("log.txt", ios::app);
		for (int i = 0; i < row; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = NULL;
		cout << _time() << "Высвобождение памяти прошло успешно\n\n";
		out << _time() << "Высвобождение памяти прошло успешно\n\n";
		out.close();
	}
}
//\DESTRUCTOR




//METHODS
template<class T>
void Templates<T>::GenerateRandomValues()
{
	if(!strcmp(type_name, "int"))
		for(int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = rand() % 100 - 50;
			}
	else if (!strcmp(type_name, "double") || !strcmp(type_name, "float"))
		for(int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				int a = rand() % 100 - 50;
				int b = rand() % 1000;
				setprecision(9);
				if (!strcmp(type_name, "double"))
					matrix[i][j] = (T)(a + b / pow(10, floor(log10(b)) + 1));
				else
					matrix[i][j] = (T)(a + b / pow(10, floor(log10(b)) + 1));
			}
	else if (!strcmp(type_name, "char"))
		for(int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] =  rand() % 26 + 97;
			}
}
template<class T>
void Templates<T>::SetRandomValue(int row, int col)
{
	if (!strcmp(type_name, "int"))
		matrix[row][col] = rand() % 100 - 50;
	else if (!strcmp(type_name, "double") || !strcmp(type_name, "float"))
	{
		int a = rand() % 100 - 50;
		int b = rand() % 100 - 50;
		if (!strcmp(type_name, "double"))
			matrix[row][col] = (T)(a + b / pow(10,floor(log10(b)) + 1));
		else
			matrix[row][col] = (T)(a + b / pow(10,floor(log10(b)) + 1));
	}
	else if (!strcmp(type_name, "char"))
		matrix[row][col] = rand() % 26 + 97;
}
template<class T>
void Templates<T>::Swap(char ch, int ind)
{
	switch (ch)
	{
	case 'c':
	{
		/*if (!strcmp(type_name, "int"))
		{*/
			T t = matrix[0][ind];
			for (int i = 0; i < row - 1; i++)
				matrix[i][ind] = matrix[i + 1][ind];
			matrix[row - 1][ind] = t;
		//}
		/*else if (!strcmp(type_name, "double") || !strcmp(type_name, "float"))
		{
			int t = matrix[0][ind];
			for (int i = 0; i < row - 1; i++)
				matrix[i][ind] = matrix[i + 1][ind];
			matrix[row - 1][ind] = t;
		}
		else if (!strcmp(type_name, "char"))
		{
			int t = matrix[0][ind];
			for (int i = 0; i < row - 1; i++)
				matrix[i][ind] = matrix[i + 1][ind];
			matrix[row - 1][ind] = t;
		}*/
		break;
	}
	case 'r':
	{
			T t = matrix[ind][0];
			for (int i = 0; i < col - 1; i++)
				matrix[ind][i] = matrix[ind][i+1];
			matrix[ind][col - 1] = t;
		break;
	}
	}
}
template<class T>
int Templates<T>::QuantityOfMin()
{
	int q(0), r(0), c(0) , min_ind(0);
	T _min(0);
	bool _exit = false;
	for (r ; r<row ; r++)
		for (c; c < col; c++)
		{
			_exit = false;
			_min = matrix[r][c];
			if (!_exit)
			for (int i = 0; i < row; i++)
				if (matrix[i][c] < _min)
				{
					_exit = true;
					break;
				}
			if (!_exit)
			for (int i = 0; i < col; i++)
				if (matrix[r][i] < _min)
				{
					_exit = true;
					break;
				}
			if (_exit)
			{
				q++;
				continue;
			}
		}
	return q;
}