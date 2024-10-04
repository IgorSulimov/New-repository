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
	float salary;
	char data[11];
public:
	//Konstructor
	Sotrudnik()
	{
		name = new char[31];
		year = 0;
		salary = 0.0;
		data[0] = '\0';
	}

	Sotrudnik(int n)
	{
		name = new char[n];
		year = 0;
		salary = 0.0;
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
	void Setsalary(float sel)
	{
		salary = sel;
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
	float Getsalary()
	{
		return salary;
	}
	char* GetData()
	{
		return data;
	}

	void Printf()
	{
		printf("%s %d %5.2f %s\n", name, year, salary, data);
	}

	void Vvod()
	{
		char inic[5];
		scanf("%s %s %d %f %s", name, inic, &year, &salary, data);
		strcat(name, " ");
		strcat(name, inic);
	}

	Sotrudnik(Sotrudnik& B)
	{
		name = new char[strlen(B.name)+1] ;
		strcpy(name, B.name);
		year = B.year;
		salary = B.salary;
		strcpy(data, B.data);
	}

	Sotrudnik& operator = (Sotrudnik& b)
	{
		if (&b == this) return *this;
		delete[] name;
		name = new char[strlen(b.name) + 1];
		strcpy(name, b.name);
		year = b.year;
		salary = b.salary;
		strcpy(data, b.data);
		return *this;
	}
	bool Sif(char* s)
	{
		return strcmp(name, s) == 0;
	}

};


void Sotrudnik_Detals(Sotrudnik Sot);

