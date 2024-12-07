#pragma once
#include <string.h>
#include <iostream>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;
double expT(double x)
{
	double e = 0.00000001;
	double res = 1.0;
	double a_n = 1.0;
	for (int i = 1; a_n >= e; i++)
	{
		a_n = x/i * a_n;
		res += a_n;
	}
	return res;
}
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
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "x=";
		cin >> x;
		cout << "y(x)=";
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
		cout << "x=";
		cin >> x;
		cout << "y(x)=";
		cout << expT(x);
	}
};

class pow_3 : public Function
{
public:
	pow_3()
	{
		strcpy(name, "y(x)= x^3");
	}
	char* Get_name()
	{
		return name;
	}
	void Calculate()
	{
		cout << "x=";
		cin >> x;
		cout << "y(x)=";
		cout << (x * x * x);
	}
};
