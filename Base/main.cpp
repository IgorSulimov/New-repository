#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Sotrudnik.h"
#include "Function_Sotrudnik.h"
#include "Base.h"
#include <locale.h>
using namespace std;
#pragma warning(disable:4996)
const int maxn = 100;

int main()
{
	char name_file[] = "Sotrudnik.txt";
	setlocale(LC_ALL, ".1251");
	Base baze;
	Base baz;
	int fl = 1;
	baze.Creat_Base_F(name_file);
	baze.Print_Base();
	baz =baze;
	printf("\n\n\n\n");
	baz.Print_Base();
	printf("\n\n\n\n");
	/*delete[] baze;
	baz->Print_Base();*/
	//while (fl != 0)
	//{
	//	Main_Menu();

	//	int n;
	//	scanf_s("%d", &n);
	//	fl = n;
	//	switch (fl)
	//	{
	//	case 1:
	//	{
	//		baze->Creat_Base_F(name_file);
	//		break;
	//	}
	//	case 2:
	//	{
	//		baze->Print_Base();
	//		break;
	//	}
	//	case 3:
	//	{
	//		Main_Change_Data();
	//		int k;
	//		scanf_s("%d", &k);
	//		switch (k)
	//		{
	//		case 1:
	//		{
	//			Sotrudnik emp;
	//			emp.Vvod();
	//			baze->Add_Sort_emp(emp);
	//			break;
	//		}
	//		case 2:
	//		{
	//			char ini[5];
	//			char del_name[40];
	//			printf("Введите имя и инициалы сотрудника которые нужно удалить\n");
	//			scanf("%s%s", del_name, ini);
	//			strcat(del_name, " ");
	//			strcat(del_name, ini);
	//			baze->Del_El(del_name);
	//			break;
	//		}
	//		case 3:
	//		{
	//			char n_ini[5];
	//			char ini[5];
	//			char ch_name[40];
	//			printf("Введите Имя и инициалы сторудника в котором нужно изменить инициалы\n");
	//			scanf("%s%s", ch_name, ini);
	//			strcat(ch_name, " ");
	//			strcat(ch_name, ini);
	//			printf("Введите Новые инициалы\n");
	//			scanf("%s", n_ini);
	//			baze->Change_Surname(ch_name, n_ini);
	//			break;
	//		}
	//		case 4:
	//		{
	//			float n_oklad;
	//			char ini[5];
	//			char ch_name[40];
	//			printf("Введите Имя и инициалы сторудника в котором нужно изменить оклад\n");
	//			scanf("%s%s", ch_name, ini);
	//			strcat(ch_name, " ");
	//			strcat(ch_name, ini);
	//			printf("Введите новый оклад сотрудника\n");
	//			scanf("%f", &n_oklad);
	//			baze->Change_Salary(ch_name, n_oklad);
	//			break;
	//		}
	//		case 5:
	//		{
	//			char* n_name;
	//			char n_ini[5];
	//			float n_oklad;
	//			char ini[5];
	//			char ch_name[40];
	//			printf("Введите Имя и инициалы сторудника в котором нужно изменить инициалы и оклад\n");
	//			scanf("%s%s", ch_name, ini);
	//			strcat(ch_name, " ");
	//			strcat(ch_name, ini);
	//			printf("Введите Новые инициалы\n");
	//			scanf("%s", n_ini);
	//			n_name = baze->Change_Surname(ch_name, n_ini);
	//			printf("Введите новый оклад сотрудника\n");
	//			scanf("%f", &n_oklad);
	//			baze->Change_Salary(n_name, n_oklad);
	//			break;
	//		}
	//		}
	//		break;
	//	}
	//	case 4:
	//	{
	//		baze->Copy_Base_F(name_file);
	//		break;
	//	}

	//	}
	//}
}

