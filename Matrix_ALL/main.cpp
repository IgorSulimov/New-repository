#include "locale.h"
#include "Matrix.hpp"
#include <iostream>
#include "Sq_Matrix.hpp"
#pragma warning(disable : 4996)
int main() {
    setlocale(LC_ALL, "RUS");
    SquareMatrix a(3);
    cin >> a;
    cout << a;
    SquareMatrix b(3);
    cin >> b;
    cout << b;
    Matrix c = a + b;
    printf("\nCумма матриц:\n");
    cout << c;
    printf("\n\n");
    Matrix d = a * b;
    printf("\nПроизведение матриц:\n");
    cout << d;
    printf("\n\n");
    Matrix e = a - b;
    printf("\nРазность матриц:\n");
    cout << e;
    printf("\n\n");
    SquareMatrix g = a;
    g.Transpon();
    printf("Транспонирование матрицы\n");
    cout << g;
    printf("\n\n");
    SquareMatrix h = a^3;
    printf("Матрица в 3 степени\n");
    cout << h;
    printf("\n\n");

    printf("Максимальные диагонали\n");
    Vector bb;
    bb = Maxfromdiag(a);
    cout << bb;
    printf("\n\n");

    printf("След\n");
    Vector cc(3);
    cc = tracematrix(a, 3);
    cout << cc;

    return 0;

