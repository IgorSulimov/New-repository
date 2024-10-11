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

char* Base::Change_Surname(char* name, char inic[5])
{
	int i = 0;
	for (i; strcmp(base[i].GetName(), name) != 0;i++)
	{ }

	if (strcmp(base[i].GetName(), name) == 0)
	{
		base[i].SetName(Change_Inic(name, inic));
		return base[i].GetName();
	}
}

char* Base::Change_Inic(char* name, char inic[5])
{
	int i = 0;
	char new_char[50];
	strcpy(new_char, name);
	for (i; name[i] != ' '; i++)
	{ }
	i++;
	for (int j = 0; inic[j]; j++, i++)
	{
		new_char[i] = inic[j];
	}
	new_char[i] = '\0';
	return new_char;
}

void Base::Copy_Base_F(char* file_name)
{
	FILE* f;
	fopen_s(&f, file_name, "w");

	for (size_t i = 0; i < current_size; ++i)
		fprintf_s(f,"%s %d %f %s\n",base[i].GetName(), base[i].Getyear(), base[i].Getsalary(), base[i].GetData());
}

void Base::Change_Salary(char* name, float sal)
{
	int i = 0;
	for (i; strcmp(base[i].GetName(), name) != 0; i++)
	{ }
	base[i].Setsalary(sal);
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

void Base::Add_Sort_emp(Sotrudnik emp)
{
	int fl = 1;
	if (current_size >= max_size)
	{
		Change_Size();
	}
	Sotrudnik* new_arr = new Sotrudnik[max_size];
	int i = 0, j = 0;
	for(i,j; i < current_size;)
	{
		if (strcmp(base[i].GetName(), emp.GetName()) == 1)
		{
			if (fl)
			{
				new_arr[j] = emp;
				j++;
				fl = 0;
			}
			else
			{
				new_arr[j] = base[i];
				i++;
				j++;
			}
		}
		else
		{
			new_arr[j] = base[i];
			j++;
			i++;
		}
	}
	if (fl)
	{
		new_arr[j] = emp;
	}
	delete[] base;

	base = new_arr;
	current_size++;
}

void Main_Menu()
{
	printf("1.������� ���� �� �����\n");
	printf("2.������� ����\n");
	printf("3.�������� ������ � ����\n");
	printf("4.���������� ������ � ����\n");
	printf("0.�����\n");
}
void Main_Change_Data()
{
	printf("1.�������� ������� � ����\n");
	printf("2.������� ������� �� ����\n");
	printf("3.�������� ������� ����������\n");
	printf("4.�������� ����� ����������\n");
	printf("5.�������� ����� � ������� ���������\n");
	printf("0.������\n");
}
void Main_Add_El()
{
	printf("���:\n");
	printf("�������:\n");
	printf("���������� ���:\n");
	printf("�����:\n");
	printf("���� ��������:\n");
}