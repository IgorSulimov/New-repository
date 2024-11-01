#include "locale.h"
#include "Matrix.hpp"
#include <iostream>
#include "Sq_Matrix.hpp"
#pragma warning(disable : 4996)
int main() {
    setlocale(LC_ALL, "RUS");
    SquareMatrix a(3);
    printf("Введите матрицу а:\n");
    Vector vect;
    a.Input();
    vect = Maxfromdiag(a);
    vect.Print_elem();
    //printf("Введите матрицу b:\n");
    //b.Input();
    //try
    //{
    //    a.Set_Element(6, 5, 100);
    //    Matrix c = a + b;
    //    printf("сумма матрицы:\n");
    //    c.Output();
    //}
    //catch (int x)

    //{
    //    switch (x)
    //    {
    //    case 1:
    //        printf("Выход за границы матрицы\n");
    //        break;
    //    case 2:
    //        printf("Не савпадают размеры матрицы\n");
    //        break;
    //    }
    //}
    return 0;
}


