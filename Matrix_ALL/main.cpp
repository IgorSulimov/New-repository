#include "locale.h"
#include "Matrix.hpp"
#include <iostream>
#include "Sq_Matrix.hpp"
#pragma warning(disable : 4996)
int main() {
    setlocale(LC_ALL, "RUS");
    SquareMatrix a(3);
    printf("������� ������� �:\n");
    Vector vect;
    a.Input();
    vect = Maxfromdiag(a);
    vect.Print_elem();
    //printf("������� ������� b:\n");
    //b.Input();
    //try
    //{
    //    a.Set_Element(6, 5, 100);
    //    Matrix c = a + b;
    //    printf("����� �������:\n");
    //    c.Output();
    //}
    //catch (int x)

    //{
    //    switch (x)
    //    {
    //    case 1:
    //        printf("����� �� ������� �������\n");
    //        break;
    //    case 2:
    //        printf("�� ��������� ������� �������\n");
    //        break;
    //    }
    //}
    return 0;
}


