#include "Function.hpp"
#include "Menu.hpp"
int main()
{
    int size = 0;
    Line line;
    Function* selected;
    Exp e;
    Function* arr[] = { &line,&e };
    size = sizeof(arr) / sizeof(Function*);
    Menu menu(arr, size);
    while (selected = menu.Select())
    {
        selected->Calculate();
    }
    return 0;
}
