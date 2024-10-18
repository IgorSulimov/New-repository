#include "Tringl.h"
#include <stdio.h>
int main()
{
	char name[] = "Tring";
	//Point a1(1,0);
	//Point a2(2,3);
	//Point a3(4,0);
	//Tringle a(a1,a2,a3,name);
	//double b = a.Find_Square();
	//printf("%1.2lf\n",b);
	Point c1(0, 0);
	Point c2(2, 2);
	Point c3(4, 1);
	Tringle c(c1, c2, c3, name);
	double k = c.Find_Square();
	printf("%1.2lf\n", k);

	Point p1(0, 0);
	Point p2(4, 6);
	Point p3(6, 0);
	Tringle p(p1, p2, p3, name);
	printf("%1.2lf\n", p.Find_Square());

	if (p.Tringle_In(c))
		printf("¬ходит\n");
	else
		printf("NO\n");
}