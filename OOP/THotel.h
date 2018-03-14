#pragma once
#include <fstream>
#include <iostream>
#include <string>

class THotel
{
private:
	char *name = new char[30];
	char *city = new char[20];
	int stars;
	struct {
		int VIP;
		int family;
		int dual;
		int single;
	}count;
public:
	THotel();
	void init(THotel * obj, int c, std::fstream &fin);
	void HList_Def();
	void menu(THotel *obj, int c);
	void THotel::city_sort(THotel *obj, int c, std::string city);
	void THotel::chamber_c(THotel *obj, int c);
	void THotel::quantity_c(THotel *obj, int c);
	void THotel::output(THotel *obj);
	void THotel::information();
	~THotel();
};