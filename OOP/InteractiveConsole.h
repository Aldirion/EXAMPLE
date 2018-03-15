#pragma once

#ifndef _INTERACTIVECONSOLE_H_
#define _INTERACTIVECONSOLE_H_
#endif

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magneta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagneta = 13, Yellow = 14, White = 15
};


//#define _CRT_NONSTDC_NO_WARNINGS
#include<iostream>
#include<ctime>
#include <Windows.h>
#include <conio.h>
//#include <string>

using namespace std;

#define DOWN 80
#define UP 72
#define _CRT_SECURE_NO_WARNINGS_GLOBALS


void set_color(ConsoleColor txt, ConsoleColor background);
void show_cursor(bool a);
char * time();
int menu_interface(char** Menu, int size);
