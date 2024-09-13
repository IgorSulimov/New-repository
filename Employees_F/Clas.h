#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#pragma warning(disable:4996)


class Sotrudnik
{
private:
	char* name;
	int year;
	float sell;
	char data[11];
public:
	//Konstructor
	Sotrudnik()
	{
		name = new char[31];
		year = 0;
		sell = 0.0;
		data[0] = '\0';
	}

	Sotrudnik(int n)
	{
		name = new char[n];
		year = 0;
		sell = 0.0;
		data[0] = '\0';
	}

	//Distructor
	~Sotrudnik()
	{
		delete[] name;
	}
	// Set Class

	void SetName(char* s)
	{
		strcpy(name, s);
	}
	void Setyear(int year1)
	{
		year = year1;
	}
	void SetSell(float sel)
	{
		sell = sel;
	}
	void SetData(char* dat)
	{
		strcpy(data, dat);
	}



	char* GetName()
	{
		return name;
	}
	int Getyear()
	{
		return year;
	}
	float GetSell()
	{
		return sell;
	}
	char* GetData()
	{
		return data;
	}

	void Printf()
	{
		printf("%s %d %5.2f %s\n", name, year, sell, data);
	}

	void Vvod()
	{
		char inic[5];
		scanf("%s %s %d %f %s", name, inic, &year, &sell, data);
		strcat(name, " ");
		strcat(name, inic);
	}

};


