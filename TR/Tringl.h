#pragma once
using namespace std;
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#pragma warning(disable:4996)
class Point
{
	int x;
	int y;
public:
	Point(int x_ = 0, int y_ = 0)
	{
		x = x_;
		y = y_;
	}
	int Get_x()
	{
		return x;
	}
	int Get_y()
	{
		return y;
	}
	void Set_x(int x_)
	{
		x = x_;
	}
	void Set_y(int y_)
	{
		y = y_;
	}
};

class Tringle
{
	Point V1;
	Point V2;
	Point V3;
	double a;
	double b;
	double c;
	char* name;

public:
	void Set_name(char* name_)
	{
		strcpy(name, name_);
	}
	char* Get_name()
	{
		return name;
	}
	Tringle(Point a1, Point a2, Point a3, char* name_);
	Tringle()
	{
		V1 = Point(0, 0);
		V2 = Point(0, 0);
		V3 = Point(0, 0);
		a = 0;
		b = 0;
		c = 0;

		name = new char[20];
	}

	double Find_Square();
	double Max_Vect();
	void Shift_Coord(Point a);
	double Sum_Square_Point(Point v1, Point v2, Point v3, Point tr_);
	bool Tringle_In(Tringle tring);
	int operator >(Tringle& other);
	void Print_Tring();
	void Creat_Trin();
	Tringle& operator=(const Tringle other_);
};
void Inc_Size(Tringle* Trin, int size);
void Menu_Tring();
void Menu_Tring_Func();
