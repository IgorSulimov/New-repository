#pragma once
#include <string.h>
#include <iostream>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;
class Function
{
protected:
	float x;
	char name[120];
public:
	virtual void Calculate() = 0;
	virtual char* Get_name() = 0;
};

// y = ax + b 
class Line : public Function
{
private:
	float a;
	float b;
public:
	Line()
	{
		strcpy(name, "ax+b");
	}
	char* Get_name()
	{
		return name;
	}
	void Calculate()
	{
		cin >> a >> b;
		cin >> x;
		cout << a * x + b;
	}
};

// e^x
class Exp : public Function
{
public:
	Exp()
	{
		strcpy(name, "e^x");
	}
	char* Get_name()
	{
		return name;
	}
	void Calculate()
	{
		cin >> x;
		cout << expT(x);
	}
};


double expT(double x)
{
	int number_memb = 100;
	double res = 1.0;
	double tmp = 1.0;

	for (int i = 1; i < number_memb; ++i) {
		tmp = tmp * x / i;
		res = res + tmp;
	}

	return res;
}