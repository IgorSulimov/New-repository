#include "Function_Sotrudnik.h"
#include "Base.h"
#include "Sotrudnik.h"
using namespace std;
int Base::Creat_Base_F(char* file_name)
{
	FILE* f = fopen(file_name, "r");
	if (!f)
		return -1;
	int year;
	float salary_;
	char fio[31];
	char inc[5];
	char dat[11];
	int fl;
	while (fscanf(f, "%s%s%d%f%s", fio, inc, &year, &salary_, dat) == 5)
	{
		strcat(fio, " ");
		strcat(fio, inc);
		base[current_size].SetName(fio);
		base[current_size].Setyear(year);
		base[current_size].Setsalary(salary_);
		base[current_size].SetData(dat);
		current_size++;
		if (current_size >= max_size)
		{
			fl = Change_Size();
			if (fl != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}

void Base::Print_Base()
{
	for (int i = 0; i < current_size; i++)
	{
		printf("%5s %2d %5.2f %-10s\n", base[i].GetName(), base[i].Getyear(), base[i].Getsalary(), base[i].GetData());
	}
}

bool Base::Del_El(char* name_)
{
	int n1 = 0;
	bool fl = false;
	Sotrudnik* new_arr = new Sotrudnik[current_size];
	for (size_t i = 0, j = 0; i < current_size;)
	{
		if (base[i].Sif(name_))
		{
			fl = true;
			i++;
		}
		else
			new_arr[j++] = base[i++];
	}
	if (fl)
	{
		delete[] base;
		current_size--;
		base = new Sotrudnik[current_size];
		for (size_t i = 0; i < current_size; i++)
		{
			base[i] = new_arr[i];
		}
	}
	return fl;
}

void Base::Add_emp(Sotrudnik emp)
{

	if (current_size == max_size)
	{
		Change_Size();
	}
	base[current_size++] = emp;
}
