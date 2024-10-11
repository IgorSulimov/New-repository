#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Sotrudnik.h"
#include "Function_Sotrudnik.h"
#include "Base.h"
#include <locale.h>
#include <windows.h>
using namespace std;
#pragma warning(disable:4996)
const int maxn = 100;

int main()
{
	char name_file[] = "Sotrudnik.txt";
	setlocale(LC_ALL, ".1251");
	Base* baze = new Base[1] ;
	int fl = 1;
	while (fl != 0)
	{
		Main_Menu();

		int n;
		scanf_s("%d", &n);
		fl = n;
		switch (fl)
		{
		case 1:
		{
			baze->Creat_Base_F(name_file);
			break;
		}
		case 2:
		{
			baze->Print_Base();
			break;
		}
		case 3:
		{
			Main_Change_Data();
			int k;
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
			{
				Sotrudnik emp;
				emp.Vvod();
				baze->Add_Sort_emp(emp);
				break;
			}
			case 2:
			{
				char del_name[40];
				printf("¬ведите им€ сотрудника, которого нужно удалить\n");
				scanf_s("%s",del_name, 40);
				baze->Del_El(del_name);
				break;
			}
			case 3:
			{
				char n_ini[5];
				char ini[5];
				char ch_name[40];
				printf("¬ведите им€ и инициалы сотрудника, которые нужно изменить\n");
				scanf_s("%s", ch_name, 40);
				scanf_s("%s", ini, 5);
				strcpy(ch_name, "");
				strcpy(ch_name, ini);
				printf("¬ведите новые инициалы сотрудника\n");
				scanf_s("%s", n_ini, 5);
				baze->Change_Surname(ch_name, n_ini);
				break;
			}
			case 4:
			{
				float n_oklad = 0.0;
				char ini[5];
				char ch_name[40];
				printf("¬ведите им€ и инициалы сотрудника, оклад которого нужно изменить\n");
				scanf_s("%s", ch_name, 40);
				scanf_s("%s", ini, 5);
				strcpy(ch_name, "");
				strcpy(ch_name, ini);
				printf("¬ведите новый оклад сотрудника");
				scanf("%f", n_oklad);
				baze->Change_Salary(ch_name, n_oklad);
				break;
			}
			case 5:
			{
				char n_ini[5];
				float n_oklad = 0.0;
				char ini[5];
				char ch_name[40];
				printf("¬ведите им€ и инициалы сотрудника, оклад и инициалы которого нужно изменить\n");
				scanf_s("%s", ch_name, 40);
				scanf_s("%s", ini, 5);
				strcpy(ch_name, "");
				strcpy(ch_name, ini);
				printf("¬ведите новые инициалы сотрудника\n");
				scanf_s("%s", n_ini, 5);
				baze->Change_Surname(ch_name, n_ini);
				printf("¬ведите новый оклад сотрудника");
				scanf("%f", n_oklad);
				baze->Change_Salary(baze->Change_Surname(ch_name, n_ini), n_oklad);
				break;
			}
			}
			break;
		}
		case 4:
		{
			char file[50];
			printf("¬ведите название файла, куда скопировать данные с базы\n");
			scanf("%s", file, 50);
			baze->Copy_Base_F(file);
			break;
		}

		}
	}
}