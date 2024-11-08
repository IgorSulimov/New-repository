#include "Tringl.h"
#include <stdio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int fl = 1;
	Tringle* Trin = new Tringle[1];
	int counter = 0;
	while (fl != 0)
	{
		Menu_Tring();
		int n;
		scanf("%d", &n);
		int fl = n;
		switch (fl)
		{
		case 1:
		{
			for (int i = 0; i != counter; ++i)
			{
				Trin[i].Print_Tring();
			}
			break;
		}
		case 2:
		{
			Inc_Size(Trin, counter);
			Trin[counter].Creat_Trin();
			counter++;
			break;
		}
		case 3:
		{
			Menu_Tring_Func();
			int fl3;
			scanf("%d", &fl3);
			try{
				if ((fl3 == 2 || fl3 == 3) && counter <= 1)
					throw 1;
			}
			catch (int x)
			{
				cout << "Недостаточно треугольников" << endl;
				fl3 = 0;
			}
			switch (fl3)
			{
			case 1:
			{
				printf("Введите имя треугольника:\n");
				char nam[40];
				scanf("%s", nam);
				printf("Введите на сколько хотите сдвинуть\n");
				int x, y;
				scanf("%d%d", &x, &y);
				Point a(x, y);
				char* nam_T;
				for (int i = 0; i < counter + 1; i++)
				{
					if (strcmp(Trin[i].Get_name(), nam) == 0)
					{
						Trin[i].Shift_Coord(a);
						i = counter + 1;
					}
				}
				break;
			}
			case 2:
			{
				printf("Введите имя 1 треугольника\n");
				char nam1[40];
				scanf("%s", nam1);
				printf("Введите имя 2 треугольника\n");
				char nam2[40];
				scanf("%s", nam2);
				int i = 0, j = 0, fl1 = 1, fl2 = 1;
				for (i, j; (fl1 && fl2);)
				{
					if (strcmp(Trin[i].Get_name(), nam1) != 0)
					{
						i++;
						fl1 = 0;
					}
					if (strcmp(Trin[j].Get_name(), nam2) != 0)
					{
						j++;
						fl2 = 0;
					}
				}
				if (Trin[i] > Trin[j])
					printf("Треугольник %s > чем треугольник %s\n", nam1, nam2);
				else
					printf("Треугольник %s > чем треугольник %s\n", nam2, nam1);
				break;
			}
			case 3:
			{
				printf("Введите имя 1 треугольника\n");
				char nam1[40];
				scanf("%s", nam1);
				printf("Введите имя 2 треугольника\n");
				char nam2[40];
				scanf("%s", nam2);
				int i = 0, j = 0, fl1 = 1, fl2 = 1;
				for (i, j; (fl1 && fl2);)
				{
					if (strcmp(Trin[i].Get_name(), nam1) != 0)
					{
						i++;
						fl1 = 0;
					}
					if (strcmp(Trin[j].Get_name(), nam2) != 0)
					{
						j++;
						fl2 = 0;
					}
				}
				if (Trin[i].Tringle_In(Trin[j]))
					printf("Треугольник %s Входит в треугольник %s\n", nam2, nam1);
				else
					printf("Треугольник %s НЕ входит в треугольник %s\n", nam2, nam1);
				break;
			}
			break;
			}
			break;
		}
		break;
		}
	}
}
