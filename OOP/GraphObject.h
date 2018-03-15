#pragma once

void GraphObjectMenu();

class GraphObject
{
protected:
	//char type;//s-square, c-circle, t-trapeze
public:
	void calc();
	//	GraphObject(char type = 's') : type(type) {}
	GraphObject() {}
	virtual void Set() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class GraphObjectSeries
{
protected:
	//	int n;
	double area, perimeter;
public:
	void calc();
	bool output(int, int, int, int);
	//	GraphObject(char type = 's') : type(type) {}
	GraphObjectSeries() {}
	virtual void Set() = 0;
	virtual int Get() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};
class Square : public GraphObject, public GraphObjectSeries
{
protected:
	int side;
public:
	Square(int side = 1) : side(side) {}
	void Set();
	int Get();
	double Perimeter();
	double Area();
	~Square() {}
};
class Circle : public GraphObject, public GraphObjectSeries
{
protected:
	int radius;
public:
	void Set();
	int Get();
	Circle(int radius = 1) : radius(radius) {}
	double Perimeter();
	double Area();
	~Circle() {}
};
class Triangle :public GraphObject, public GraphObjectSeries
{
protected:
	int A, B, C, H;
public:
	void Set();
	int Get();
	Triangle(int _a = 3, int _b = 4, int _c = 5, int _h = 5) :A(_a), B(_b), C(_c), H(_h) {}
	double Perimeter();
	double Area();
	~Triangle() {}
};