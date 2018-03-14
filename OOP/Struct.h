#pragma once
#include <fstream>
#include <iostream>
struct Product
{
	char* date = new char[9];
	char* type = new char[20];
	char* name = new char[30];
	int count;
};

void lab_1_20_start();

void fill();

void struct_input(Product *p, int count, std::fstream& fin);

void struct_sort(Product *p, int count);

void struct_output(Product *p, int c);
