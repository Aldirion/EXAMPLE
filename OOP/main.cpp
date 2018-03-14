#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;


extern bool exit_m = false;
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu Menu;
	system("pause");
	return 0;
}