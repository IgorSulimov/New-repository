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
		pObj = new Function*[size_ + 1];
		for (int i = 0; i < size_; i++)
		{
			pObj[i] = arr_[i];
		}
		pObj[size_] = nullptr;
		size_menu = size_ + 1;
	}
	Function* Select() const {
		int nItem = size_menu;
		cout << "\nSelect one of the following function:\n";
		for (int i = 0; i < nItem; ++i) {
			cout << i + 1 << ". "; // номер пункта меню на единицу 
			// больше, чем индекс массива pObj 
			if (pObj[i]) cout << pObj[i]->Get_name() << endl;
			else cout << "Exit" << endl;
		}
		int item = SelectItem(nItem);
		return pObj[item - 1];
	}
	int SelectItem(int nItem) const 
	{
		cout << "---------------------------- \n";
		int item;
		while (true) {
			cin >> item;
			if ((item > 0) && (item <= nItem) && (cin.peek() == '\n')) {
				cin.get();break;
			}
			else {
				cout << "Error (must be number from 1 to ";
				cout << nItem << "): " << endl;
				cin.clear();
				while (cin.get() != '\n') {};
				return item;

			}
		}
		return item;
	}
};
