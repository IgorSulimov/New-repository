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
	Base Copy_baze;
	int fl = 1;
	int sozd_f = 0;
	int fl2 = 1;
	while (fl != 0)
	{
		if (!sozd_f)
		{
			Main_Menu();
			fl2 = 1;
		}
		else 
		{
			Main_Menu2();
			fl2 = 1;
		}
		int n;
		scanf_s("%d", &n);
		fl = n;
		switch (fl)
		{
		case 1:
		{
			if (baze.Print_Base() == -1)
				printf("База пуста\n\n");
			break;
		}
		case 2:
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
				baze.Add_Sort_emp(emp);
				break;
			}
			case 2:
			{
				char ini[5];
				char del_name[40];
				printf("Введите имя и инициалы сотрудника которые нужно удалить\n");
				scanf("%s%s", del_name, ini);
				strcat(del_name, " ");
				strcat(del_name, ini);
				if (baze.Del_El(del_name))
				{
					printf("Элемент: %s был успешно удален\n",del_name);
				}
				else
				{
					printf("Не удалось удалить элемент: %s \n", del_name);
				}
				break;
			}
			case 3:
			{
				char n_ini[5];
				char ini[5];
				char ch_name[40];
				printf("Введите Имя и инициалы сторудника в котором нужно изменить инициалы\n");
				scanf("%s%s", ch_name, ini);
				strcat(ch_name, " ");
				strcat(ch_name, ini);
				printf("Введите Новые инициалы\n");
				scanf("%s", n_ini);
				baze.Change_Surname(ch_name, n_ini);
				break;
			}
			case 4:
			{
				float n_oklad;
				char ini[5];
				char ch_name[40];
				printf("Введите Имя и инициалы сторудника в котором нужно изменить оклад\n");
				scanf("%s%s", ch_name, ini);
				strcat(ch_name, " ");
				strcat(ch_name, ini);
				printf("Введите новый оклад сотрудника\n");
				scanf("%f", &n_oklad);
				baze.Change_Salary(ch_name, n_oklad);
				break;
			}
			case 5:
			{
				char* n_name;
				char n_ini[5];
				float n_oklad;
				char ini[5];
				char ch_name[40];
				printf("Введите Имя и инициалы сторудника в котором нужно изменить инициалы и оклад\n");
				scanf("%s%s", ch_name, ini);
				strcat(ch_name, " ");
				strcat(ch_name, ini);
				printf("Введите Новые инициалы\n");
				scanf("%s", n_ini);
				n_name = baze.Change_Surname(ch_name, n_ini);
				printf("Введите новый оклад сотрудника\n");
				scanf("%f", &n_oklad);
				baze.Change_Salary(n_name, n_oklad);
				break;
			}
			}
			break;
		}
		case 3:
		{
			baze.Copy_Base_F(name_file);
			break;
		}
		case 4:
		{
			Copy_baze = baze;
			break;
		}
		case 5:
		{
			// РАБОТА С КОПИЕЙ БАЗЫ
			while (fl2)
			{
				int k;
				Menu_Copy_Base();
				scanf_s("%d", &k);
				switch (k)
				{
				case 1:
				{
					Copy_baze.Print_Base();
					fl2 = 0;
					break;

				}
				case 2:
				{
					Change_Data_Copy_Base();
					int k;
					scanf_s("%d", &k);
					switch (k)
					{
					case 1:
					{
						Sotrudnik emp;
						emp.Vvod();
						Copy_baze.Add_Sort_emp(emp);
						fl2 = 0;
						break;
					}
					case 2:
					{
						char ini[5];
						char del_name[40];
						printf("Введите имя и инициалы сотрудника которые нужно удалить\n");
						scanf("%s%s", del_name, ini);
						strcat(del_name, " ");
						strcat(del_name, ini);
						Copy_baze.Del_El(del_name);
						fl2 = 0;
						break;
					}
					case 3:
					{
						char n_ini[5];
						char ini[5];
						char ch_name[40];
						printf("Введите Имя и инициалы сторудника в котором нужно изменить инициалы\n");
						scanf("%s%s", ch_name, ini);
						strcat(ch_name, " ");
						strcat(ch_name, ini);
						printf("Введите Новые инициалы\n");
						scanf("%s", n_ini);
						Copy_baze.Change_Surname(ch_name, n_ini);
						fl2 = 0;
						break;
					}
					case 4:
					{
						float n_oklad;
						char ini[5];
						char ch_name[40];
						printf("Введите Имя и инициалы сторудника в котором нужно изменить оклад\n");
						scanf("%s%s", ch_name, ini);
						strcat(ch_name, " ");
						strcat(ch_name, ini);
						printf("Введите новый оклад сотрудника\n");
						scanf("%f", &n_oklad);
						Copy_baze.Change_Salary(ch_name, n_oklad);
						fl2 = 0;
						break;
					}
					case 5:
					{
						char* n_name;
						char n_ini[5];
						float n_oklad;
						char ini[5];
						char ch_name[40];
						printf("Введите Имя и инициалы сторудника в котором нужно изменить инициалы и оклад\n");
						scanf("%s%s", ch_name, ini);
						strcat(ch_name, " ");
						strcat(ch_name, ini);
						printf("Введите Новые инициалы\n");
						scanf("%s", n_ini);
						n_name = Copy_baze.Change_Surname(ch_name, n_ini);
						printf("Введите новый оклад сотрудника\n");
						scanf("%f", &n_oklad);
						Copy_baze.Change_Salary(n_name, n_oklad);
						fl2 = 0;
						break;
					}
					}
				}
				case 3:
				{
					Copy_baze.Copy_Base_F(name_file);
					fl2 = 0;
					break;
				}
				case 0:
					fl2 = 0;
				}
			}
			break;
		}
		case 6:
		{
			int war = baze.Creat_Base_F(name_file);
			if (war == -1)
				printf("Не удалось открыть файл");
			if (war == -2)
				printf("Не удалось увеличить размер базы");
			sozd_f = 1;
			break;
		}
		}
	}
}