#pragma once
#include "Function.hpp"


class Menu
{
	Function** pObj;
	int size_menu;
public:
	~Menu()
	{
		delete[] pObj;
	}
	Menu(Function** arr_, int size_)
	{
		pObj = new Function * [size_ + 1];
		for (int i = 0; i < size_; i++)
		{
			pObj[i] = arr_[i];
		}
		pObj[size_] = nullptr;
		size_menu = size_ + 1;
	}
	Function* Select() const
	{
		int nItem = size_menu;
		cout << "\nВыберите одну из следующих функций:\n";
		for (int i = 0; i < nItem; ++i)
		{
			cout << i + 1 << ".";
			if (pObj[i]) cout << pObj[i]->Get_name() << endl;
		}
		cout  << "Exit" << endl;
		int item = SelectItem(nItem);
		if (item == -1)
		{
			cout << "\nВыберите одну из следующих функций:\n";
			for (int i = 0; i < nItem; ++i)
			{
				cout << i + 1 << ".";
				if (pObj[i]) cout << pObj[i]->Get_name() << endl;
			}
			cout << "Exit" << endl;
			item = SelectItem(nItem);
		}
		return pObj[item - 1];
	}
	int SelectItem(int nItem) const
	{
		int item;
		while (true)
		{
			cin >> item;
			if ((item > 0) && (item < nItem))
			{
				return item;
			}
			if (item == nItem)
			{
				exit(0);
			}
			else
			{
				cout << "Ошибка (должно быть число от 1 до ";
				cout << nItem << "): " << endl;
				return -1;
			}
		}
	}
};
