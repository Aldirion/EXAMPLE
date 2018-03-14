#pragma once
#include <iostream>
#include <Windows.h>
#include <string>


class menu
{
private:
	int chs;
public:
	menu();

	void choose(int);

	void m_interface();

	void pre_destructor();

	~menu();
};