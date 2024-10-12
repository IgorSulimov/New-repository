#pragma once
#include "Sotrudnik.h"
using namespace std;

class Base
{
private:
	Sotrudnik* base;
	size_t current_size;
	size_t max_size;
public:
	Base()
	{
		current_size = 0;
		max_size = 100;
		base = new Sotrudnik[max_size];
	}
	Base(int size_)
	{
		current_size = size_;
		max_size = 100;
		base = new Sotrudnik[max_size];
	}
	~Base()
	{
		delete[] base;
	}

	int Change_Size()
	{
		Sotrudnik* arr = new Sotrudnik[max_size += 100];
		if (!arr)
			return -1;

		for (int i = 0; i < current_size; i++)
		{
			arr[i] = base[i];
		}
		base = arr;
		return 0;

	}
	void Add_emp(Sotrudnik emp);
	void Add_Sort_emp(Sotrudnik emp);
	bool Del_El(char* name);
	int Creat_Base_F(char* file_name);
	void Print_Base();
	char* Change_Surname(char* name, char inic[5]);
	void Change_Salary(char* name, float sel);
	char* Change_Inic(char* name, char inic[5]);
	int Copy_Base_F(char* file_name);

};
void Main_Menu();
void Main_Change_Data();
