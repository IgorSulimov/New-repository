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
	Point(int x_=0, int y_=0)
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
	static int counter;
	//void Set_name(char* name_)
	//{
	//	strcpy(name, name_);
	//}
	char* Get_name()
	{
		return name;
	}
	Tringle(Point a1, Point a2, Point a3, char* name_);
	double Find_Square();
	double Max_Vect();
	void Shift_Coord(Point a);
	double Sum_Square_Point(Point v1, Point v2, Point v3, Point tr_);
	bool Tringle_In(Tringle tring);
	int operator >(Tringle& other);
};