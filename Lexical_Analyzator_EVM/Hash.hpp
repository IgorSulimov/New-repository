using namespace std;
#include <iostream>
struct EL_TS
{
	int label; // значение метки
	int ind_TL; // номер в таблице лексем
	int next; // альтератива
};
class Hash
{
	int n_max; // максимальная размерность таблицы
	int n_os; // текущая размерность
	int NTS = 101; // первая свободная запись в таблице строк
	EL_TS* t;

	int Hash_function(int key)
	{
		return (key % n_os) + 1;
	}
public:
	int Get_NTS()
	{
		return NTS;
	}
	Hash(int n1 = 200, int os = 100)
	{
		n_max = n1;
		n_os = os;
		NTS = os + 1;
		t = new EL_TS[n_max];
		for (int i = 0; i < n_max; i++)
		{
			t[i].label = t[i].ind_TL = -1;
			t[i].next = -1;
		}

	}
	Hash(Hash& other)
	{
		n_max = other.n_max;
		n_os = other.n_os;
		NTS = other.NTS;

		for (int i = 0; i < n_max; i++)
		{
			t[i].next = other.t[i].next;
			t[i].label = other.t[i].label;
			t[i].ind_TL = other.t[i].ind_TL;
		}
	}
	int find(int key)
	{
		int i = Hash_function(key);
		if (t[i].label == key)
			return i;
		while (t[i].next != -1)
		{
			i = t[i].next;
			if (t[i].label == key)
				return i;
		}
		return -1;
	}
	void add_el(int key)
	{
		int i = Hash_function(key);
		int fl = 0;
		if (t[i].label == -1)
		{
			t[i].label = key;
			t[i].ind_TL = i;
			t[i].next = 0;
		}
		else
		{
			int del_ch = t[0].next;
			int i_next = t[i].next;
			while (t[i_next].label != -1)
			{
				i = i_next;
				i_next = t[i].next;
			}
			if (del_ch == 0)
			{
				i_next = NTS;
				t[i_next].ind_TL = NTS;
				t[i].next = i_next;
			}
			else
			{
				i_next = del_ch;
				t[i].next = del_ch;
				if (t[del_ch].next != 0)
				{
					t[0].next = t[del_ch].next;
				}
				else
				{
					t[0].next = 0;
				}
				fl = 1;
			}
			if (fl == 0)
			{
				NTS++;
			}
			t[i_next].label = key;
			t[i_next].next = 0;
		}
	}
	void remove_el(int key)
	{
		//i = который дуаляем i_prev - перед i
		int i = Hash_function(key);
		if (t[i].label == key)
		{
			if ((t[i].next != 0) || (t[i].next == 0 && t[i].ind_TL >= 101))
			{
				if (t[0].next == 0)
				{
					t[0].next = t[i].next;
				}
				else
				{
					//добавляем ind_TL в удаляемые индексы
					int g = t[0].next;
					while (t[g].next != 0)
					{
						g = t[g].next;
					}
					t[g].next = t[i].next;
				}
				int i_next = t[i].next;
				t[i].label = t[i_next].label;
				t[i].next = t[i_next].next;
				t[i_next].next = 0;
			}
			else
			{
				t[i].label = -1;
				t[i].ind_TL = -1;
				t[i].next = 0;
			}
		}
		else
		{
			int i_prev;
			while (t[i].label != key)
			{
				i_prev = i;
				i = t[i].next;

			}
			if (t[0].next == 0)
			{
				t[0].next = t[i].next;
			}
			else
			{
				//добавляем ind_TL в удаляемые индексы
				int g = t[0].next;
				while (t[g].next != 0)
				{
					g = t[g].next;
				}
				t[g].next = t[i].ind_TL;
			}
			t[i_prev].next = t[i].next;
			t[i].next = 0;


		}
	}
	void print_Hash()
	{
		int i = 0;
		while (i < 101)
		{
			if (t[i].label != -1)
			{
				int g = i;
				int fl = 1;
				while (fl)
				{
					if (t[g].next != 0)
					{
						cout << "(" << t[g].label << "," << t[g].ind_TL << ")" << "->";
						g = t[g].next;
					}
					else
					{
						cout << "(" << t[g].label << "," << t[g].ind_TL << ")" << endl;
						fl = 0;
						i++;
					}
				}
				fl = 1;
			}
			else
				i++;
		}
		cout << "\n\n";
		cout << "t[0]:";
		int j = 0;
		while (t[j].next != 0)
		{
			if (t[j].next != 0)
			{
				cout << "(" << t[j].next << ")" << "->";
				j = t[j].next;
			}
		}
		cout << "(" << t[j].next << ")" << endl;
	}

};