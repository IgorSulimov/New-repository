#include "Tringl.h"
#include <stdio.h>
int main()
{
	setlocale(LC_ALL, ".1251");
	int fl = 1;
	Tringle* Trin = new Tringle[1];
	while (fl != 0)
	{
		int n;
		scanf("%d", &n);
		int fl = n;
		switch (fl)
		{
		case 1:
		{
			for (int i = 0; i < Trin->counter; ++i)
			{
				Trin[i].Print_Tring();
			}
			break;
		}
		break;
		}		
		//printf("1.Вывести все треугольники\n");
		//printf("2.Создать треугольник\n");
		//printf("3.Функции с треугольниками\n");
	}
}