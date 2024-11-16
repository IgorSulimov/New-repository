#include "Tringle.hpp"
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
	Set_name(name_);
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
	if (a > b && a > c || a >= b && a > c || a > b && a >= c || a == b && a == c)
		return a;
	if (b > a && b > c || b >= a && b > c || b > a && b >= c || b == a && b == c)
		return b;
	if (c > a && c > b || c >= a && c > b || c > a && c >= b || c == a && c == b)
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

int Tringle::operator >(Tringle& other)
{
	if (this->Find_Square() > other.Find_Square())
		return 1;
	else
		return 0;
}

void Tringle::Print_Tring()
{
	printf("Имя треугольника:\n");
	printf("%s\n", name);
	printf("Точки:\n");
	printf("(%d,%d)||(%d,%d)||(%d,%d)\n", V1.Get_x(), V1.Get_y(), V2.Get_x(), V2.Get_y(), V3.Get_x(), V3.Get_y());
	printf("Вектора:\n");
	printf("a =%5.2f, b =%5.2f, c =%5.2f\n", a, b, c);
	printf("Площадь треугольника:\n");
	printf("%5.2f\n", this->Find_Square());
	printf("\n\n\n");
}

void Tringle::Creat_Trin()
{

	int x1, y1, x2, y2, x3, y3;
	char nam[40];
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	Point a1(x1, y1), a2(x2, y2), a3(x3, y3);
	V1.Set_x(a1.Get_x());
	V1.Set_y(a1.Get_y());
	V2.Set_x(a2.Get_x());
	V2.Set_y(a2.Get_y());
	V3.Set_x(a3.Get_x());
	V3.Set_y(a3.Get_y());
	a = sqrt((V1.Get_x() - V2.Get_x()) * (V1.Get_x() - V2.Get_x()) + (V1.Get_y() - V2.Get_y()) * (V1.Get_y() - V2.Get_y()));
	b = sqrt((V2.Get_x() - V3.Get_x()) * (V2.Get_x() - V3.Get_x()) + (V2.Get_y() - V3.Get_y()) * (V2.Get_y() - V3.Get_y()));
	c = sqrt((V1.Get_x() - V3.Get_x()) * (V1.Get_x() - V3.Get_x()) + (V1.Get_y() - V3.Get_y()) * (V1.Get_y() - V3.Get_y()));
	count++;
	Set_name(nam);
}

Tringle& Tringle::operator=(const Tringle other_)
{
	if (this == &other_)
		return *this;
	V1 = (other_.V1);
	V2 = (other_.V2);
	V3 = (other_.V3);
	a = (other_.a);
	b = (other_.b);
	c = (other_.c);
	Set_name(other_.name);

	return *this;
}

void Inc_Size(Tringle* Trin, int size_)
{
	Tringle* tmp_ = new Tringle[size_ + 1];
	for (int i = 0; i < size_; i++)
	{
		tmp_[i] = Trin[i];
	}
	delete[] Trin;
	Trin = new Tringle[size_ + 1];
	for (int i = 0; i < size_; i++)
	{
		Trin[i] = tmp_[i];
	}
}
ostream& operator<<(ostream& stream, Tringle& Trin)
{
	double Sq = Trin.Find_Square();
	stream << "Имя треугольника\n";
	stream << Trin.Get_name() << endl;
	stream << "Точки:\n";
	stream << "(" << Trin.V1.Get_x() << "," << Trin.V1.Get_y() << ")";
	stream << "(" << Trin.V2.Get_x() << "," << Trin.V2.Get_y() << ")";
	stream << "(" << Trin.V3.Get_x() << "," << Trin.V3.Get_y() << ")" << endl;
	stream << "Вектора:\n";
	stream << "a=" << Trin.Get_a() << endl;
	stream << "b=" << Trin.Get_b() << endl;
	stream << "c=" << Trin.Get_c() << endl;
	stream << "Площадь:\n";
	stream << Sq << endl;
	return stream;
}
void Menu_Tring()
{
	printf("1.Вывести все треугольники\n");
	printf("2.Создать треугольник\n");
	printf("3.Функции с треугольниками\n");
}

void Menu_Tring_Func()
{
	printf("1.Перемещение треугольника\n");
	printf("2.Сравнение треугольников >\n");
	printf("3.Включение треугольника 1 в треугольник 2\n");
}
