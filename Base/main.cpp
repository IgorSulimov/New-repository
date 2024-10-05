#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Sotrudnik.h"
#include "Function_Sotrudnik.h"
#include "Base.h"

using namespace std;
#pragma warning(disable:4996)
const int maxn = 100;
int main()
{
	Sotrudnik Bob;
	char d[] = "Bob K.P.";
	Base arr;
	int size_arr = 0;
	char name_file[] = "Sotrudnik.txt";
	arr.Creat_Base_F(name_file);
	Bob.Vvod();
	arr.Add_emp(Bob);
	printf("\n\n\n");
	arr.Print_Base();


}
