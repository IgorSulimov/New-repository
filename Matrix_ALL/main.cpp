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
    SquareMatrix a(2);
    cin >> a;
    cout << a;
    Vector bb(4);
    bb = tracematrix(a, 4);
    cout << bb;
    //Matrix b(2,2);
    //cin >> b;
    //cout << b;
    //printf("Sum\n");
    //Matrix sum = a + b;
    //cout << sum;
    //printf("Sub\n");
    //Matrix sub = a - b;
    //cout << sub;
    //printf("Mult\n");
    //Matrix mult = a * b;
    //cout << mult;
    //printf("Транеспонирование матрицы а");
    //Matrix Tr = a.Transpose();
    //cout << Tr;
    return 0;
}


