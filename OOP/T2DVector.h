#pragma once
#include <fstream>
//class T2DVectorAnalizer;
class T2DVector
{
protected:
	double X, Y;
public:
	//constructors & destructor
	T2DVector();
	T2DVector(double, double);
	~T2DVector();
	//

	//operators
	T2DVector & operator +(const T2DVector &p) const;
	T2DVector &operator -(const T2DVector &p) const;
	T2DVector operator ++(int);
	T2DVector &operator ++();
	T2DVector & operator --();
	T2DVector operator --(int);
	friend std::ostream &operator <<(std::ostream &_out, const T2DVector &_p);
	//friend std::ofstream &operator <<(std::ofstream &_fout, const T2DVector &_p);
	friend std::istream &operator >>(std::istream &_in, T2DVector &_p);
	bool operator ==(const T2DVector &_p) const
	{
		return X == _p.X && Y == _p.Y;
	}
	bool operator !=(const T2DVector &_p) const
	{
		return !(*this == _p);
	}
	//

	//methods
	void menu();
	void Set();
	void GenerateRandomValues();
	void Swap();
	double Length();
	//


	//friend T2DVectorAnalizer;
};

class T2DVectorAnalizer
{
	char op = 's';
public:
	int Sort(T2DVector *, int);
	int SearchMaxLength(T2DVector *, int);
	void ShowData(const T2DVector &, std::fstream &) const;
};

