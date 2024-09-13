#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Clas.h"
#pragma warning(disable:4996)
using namespace std;

int Sozd_F(char* file_name, int& k, Sotrudnik* a)
{
	int year;
	float oklad;
	char fio[31];
	char inc[5];
	char dat[11];
	FILE* f = fopen(file_name, "r");
	if (!f)
		return -1;
	k = 0;
	while (fscanf(f, "%s%s%d%f%s", fio, inc, &year, &oklad, dat) == 5 && k < 100)
	{
		strcat(fio, " ");
		strcat(fio, inc);
		a[k].SetName(fio);
		a[k].Setyear(year);
		a[k].SetSell(oklad);
		a[k].SetData(dat);
		k++;
	}
	if (k >= 100)
		return -2;
	return 0;
}

float FirstRec(Sotrudnik* arr_, int size, int& k, char** Fio_25, int year_)
{
	k = 0;
	float salary = 0;
	int year_emp = 0;
	char* dat;
	for (int i = 0; i < size; i++)
	{
		dat = arr_[i].GetData();
		year_emp = (dat[6] - 48) * 1000 + (dat[7] - 48) * 100 + (dat[8] - 48) * 10 + (dat[9] - 48);
		if (year_ - year_emp > 25)
		{
			strcpy(Fio_25[k], arr_[i].GetName());
			k++;

			salary += arr_[i].GetSell();
		}
	}
	if (k != 0)
		salary /= k;

	return salary;
}