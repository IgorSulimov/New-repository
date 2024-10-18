#include "Tringl.h"
using namespace std;
#include <stdlib.h>
#include <math.h>

Tringle::Tringle(Point a1, Point a2, Point a3, char* name_)
{
	V1.Set_x(a1.Get_x());
	V1.Set_y(a1.Get_y());
	V2.Set_x(a2.Get_x());
	V2.Set_y(a2.Get_y());
	V3.Set_x(a3.Get_x());
	V3.Set_y(a3.Get_y());
	a = sqrt((V1.Get_x() - V2.Get_x()) * (V1.Get_x() - V2.Get_x()) + (V1.Get_y() - V2.Get_y()) * (V1.Get_y() - V2.Get_y()));
	b = sqrt((V2.Get_x() - V3.Get_x()) * (V2.Get_x() - V3.Get_x()) + (V2.Get_y() - V3.Get_y()) * (V2.Get_y() - V3.Get_y()));
	c = sqrt((V1.Get_x() - V3.Get_x()) * (V1.Get_x() - V3.Get_x()) + (V1.Get_y() - V3.Get_y()) * (V1.Get_y() - V3.Get_y()));
	//Set_name(name_);
	printf("KONSTRUKTOR\n");

}
double Tringle::Find_Square()
{
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

double Tringle::Max_Vect()
{
	if (a > b && a > c)
		return a;
	if (b > a && b > c)
		return b;
	if (c > a && c > b)
		return c;
}

void Tringle::Shift_Coord(Point a)
{
	V1.Set_x(V1.Get_x() + a.Get_x());
	V1.Set_y(V1.Get_y() + a.Get_y());

	V2.Set_x(V2.Get_x() + a.Get_x());
	V2.Set_y(V2.Get_y() + a.Get_y());

	V3.Set_x(V3.Get_x() + a.Get_x());
	V3.Set_y(V3.Get_y() + a.Get_y());

	this->a = sqrt((V1.Get_x() - V2.Get_x()) * (V1.Get_x() - V2.Get_x()) + (V1.Get_y() - V2.Get_y()) * (V1.Get_y() - V2.Get_y()));
	this->b = sqrt((V2.Get_x() - V3.Get_x()) * (V2.Get_x() - V3.Get_x()) + (V2.Get_y() - V3.Get_y()) * (V2.Get_y() - V3.Get_y()));
	this->c = sqrt((V1.Get_x() - V3.Get_x()) * (V1.Get_x() - V3.Get_x()) + (V1.Get_y() - V3.Get_y()) * (V1.Get_y() - V3.Get_y()));


}

double Tringle::Sum_Square_Point(Point v1, Point v2, Point v3, Point tr_)
{
	double S = 0;
	this->a = sqrt((tr_.Get_x() - v2.Get_x()) * (tr_.Get_x() - v2.Get_x()) + (tr_.Get_y() - v2.Get_y()) * (tr_.Get_y() - v2.Get_y()));
	this->b = sqrt((v2.Get_x() - v3.Get_x()) * (v2.Get_x() - v3.Get_x()) + (v2.Get_y() - v3.Get_y()) * (v2.Get_y() - v3.Get_y()));
	this->c = sqrt((tr_.Get_x() - v3.Get_x()) * (tr_.Get_x() - v3.Get_x()) + (tr_.Get_y() - v3.Get_y()) * (tr_.Get_y() - v3.Get_y()));
	S = this->Find_Square();
	this->a = sqrt((V1.Get_x() - tr_.Get_x()) * (V1.Get_x() - tr_.Get_x()) + (V1.Get_y() - tr_.Get_y()) * (V1.Get_y() - tr_.Get_y()));
	this->b = sqrt((tr_.Get_x() - v3.Get_x()) * (tr_.Get_x() - v3.Get_x()) + (tr_.Get_y() - v3.Get_y()) * (tr_.Get_y() - v3.Get_y()));
	this->c = sqrt((V1.Get_x() - v3.Get_x()) * (V1.Get_x() - v3.Get_x()) + (V1.Get_y() - v3.Get_y()) * (V1.Get_y() - v3.Get_y()));
	S += this->Find_Square();
	this->a = sqrt((V1.Get_x() - v2.Get_x()) * (V1.Get_x() - v2.Get_x()) + (V1.Get_y() - v2.Get_y()) * (V1.Get_y() - v2.Get_y()));
	this->b = sqrt((v2.Get_x() - tr_.Get_x()) * (v2.Get_x() - tr_.Get_x()) + (v2.Get_y() - tr_.Get_y()) * (v2.Get_y() - tr_.Get_y()));
	this->c = sqrt((V1.Get_x() - tr_.Get_x()) * (V1.Get_x() - tr_.Get_x()) + (V1.Get_y() - tr_.Get_y()) * (V1.Get_y() - tr_.Get_y()));
	S += this->Find_Square();
	return S;
}

bool Tringle::Tringle_In(Tringle tring)
{
	double S = this->Find_Square();
	double S_tmp;
	Point tr1 = tring.V1;
	Point tr2 = tring.V2;
	Point tr3 = tring.V3;
	// Провека каждой точки (tr1)
	S_tmp = tring.Sum_Square_Point(V1, V2, V3, tr1);

	if (round(S_tmp) == round(S))
	{
		// Проверкав точки (tr2)
		S_tmp = 0;
		S_tmp = tring.Sum_Square_Point(V1, V2, V3, tr2);

		if (round(S_tmp) == round(S))
		{
			// Проверка точки tr3
			S_tmp = 0;
			S_tmp = tring.Sum_Square_Point(V1, V2, V3, tr3);

			if (round(S_tmp) == round(S))
			{// Возврат Векторов
				tring.a = sqrt((tr1.Get_x() - tr2.Get_x()) * (tr1.Get_x() - tr2.Get_x()) + (tr1.Get_y() - tr2.Get_y()) * (tr1.Get_y() - tr2.Get_y()));
				tring.b = sqrt((tr2.Get_x() - tr3.Get_x()) * (tr2.Get_x() - tr3.Get_x()) + (tr2.Get_y() - tr3.Get_y()) * (tr2.Get_y() - tr3.Get_y()));
				tring.c = sqrt((tr1.Get_x() - tr3.Get_x()) * (tr1.Get_x() - tr3.Get_x()) + (tr1.Get_y() - tr3.Get_y()) * (tr1.Get_y() - tr3.Get_y()));

				return true;
			}
		}
	}
	tring.a = sqrt((tr1.Get_x() - tr2.Get_x()) * (tr1.Get_x() - tr2.Get_x()) + (tr1.Get_y() - tr2.Get_y()) * (tr1.Get_y() - tr2.Get_y()));
	tring.b = sqrt((tr2.Get_x() - tr3.Get_x()) * (tr2.Get_x() - tr3.Get_x()) + (tr2.Get_y() - tr3.Get_y()) * (tr2.Get_y() - tr3.Get_y()));
	tring.c = sqrt((tr1.Get_x() - tr3.Get_x()) * (tr1.Get_x() - tr3.Get_x()) + (tr1.Get_y() - tr3.Get_y()) * (tr1.Get_y() - tr3.Get_y()));

	return false;
}

int Tringle::operator>(Tringle& other)
{
	if (this->Find_Square() > other.Find_Square())
		return 1;
	else
		return 0;
}
