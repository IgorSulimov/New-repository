#pragma once
#include "Sotrudnik.h"

class Base
{
private:
	Sotrudnik* arr;
	size_t current_size;
	size_t size;
public:
	Base()
	{
		arr[current_size];
		current_size = 1;
		size = 100;
	}
	Base(int size_)
	{
		arr[current_size];
		current_size = size_;
		size = 100;
	}
	~Base()
	{
		delete[] arr;
	}

	//bool Del_El(const char* name)
	//{
	//	int n1 = 0;
	//	bool fl = false;
	//	Sotrudnik new_arr[size];
	//	for (size_t i = 0; i < current_size;)
	//	{
	//		if (arr[i].Sif(name_))
	//			fl = true;
	//		else
	//			new_arr[i++] = arr[i];
	//	}
	//	if (fl)
	//	{
	//		delete[] arr;
	//		current_size--;
	//		arr = new Sotrudnik[size];
	//		for (size_t i = 0; i < current_size; i++)
	//		{
	//			arr[i] = new_arr[i];
	//		}
	//	}
	//	return fl;
	//}

};