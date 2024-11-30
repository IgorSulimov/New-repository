#include "Function.hpp"
#include "Menu.hpp"
int main()
{
    setlocale(LC_ALL, ".1251");
    int size = 0;
    Line line;
    Function* selected;
    Exp e;
    pow_3 p;
    Function* arr[] = { &line,&e,&p };
    size = sizeof(arr) / sizeof(Function*);
    Menu menu(arr, size);

    while (selected = menu.Select())
    {
        selected->Calculate();
    }
    return 0;
}
