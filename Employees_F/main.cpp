#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Clas.h"
#include "Function_Class.h"

using namespace std;
#pragma warning(disable:4996)
const int maxn = 100;
int main()
{
	int y = 0;
	printf("Enter year\n");
	scanf_s("%d", &y);
	Sotrudnik arr[maxn];
	int size_arr = 0;
	char name_file[] = "d:/Sotrudnik.txt";
	//FILE* f;
	//fopen_s(&f,name_file, "w");
	//if (!f)
	//	return -1;
	//fprintf(f, "%s %s %d %.1f %s\n", "Pavel", "M.K", 31, 2000.0, "21.03.2005");
	//fprintf(f, "%s %s %d %.1f %s", "DD", "M.K", 22, 3000.0, "09.05.2000");
	//fclose(f);
	int ReadingFile;
	ReadingFile = Sozd_F(name_file,size_arr,arr);
	if (ReadingFile == 0)
	{
		char** Fio_25 = new char* [31];
		for (int i = 0; i < 31; i++)
			Fio_25[i] = new char[100];

		int size_Fio = 0;
		float salary = FirstRec(arr, size_arr, size_Fio, Fio_25, y);
		if (size_Fio)
		{
			printf("People with more than 25 years of experience, counting from:\n");
			for (int i = 0; i < size_Fio; i++)
			{
				printf("%s\n", Fio_25[i]);
			}
			printf("\nSalary: %.2f", salary);
		}
		else
		{
			printf("There are no people who have 25 years of experience(\n");
		}
	}
}