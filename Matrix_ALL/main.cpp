#include "locale.h"
#include "Matrix.hpp"
#include <iostream>
#include "Sq_Matrix.hpp"
#pragma warning(disable : 4996)

int main() {
    setlocale(LC_ALL, "RUS");
    SquareMatrix a(3);
    ifstream file("Matrix.txt");

    file >> a;
    cout << a;
    SquareMatrix b(3);
    cin >> b;
    cout << b;
    printf("\n Возведение матрицы в степень\n");
    SquareMatrix c;
    c = a.Pow11(4);
    cout << c;
    printf("\n\n");
    printf("\nCумма матриц:\n");
    Matrix n;
    n = a + b;
    cout << n;
    printf("\n\n");
    SquareMatrix d = a * b;
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

    printf("След\n");
    Vector cc(3);
    cc = tracematrix(a, 3);
    cout << cc;
    printf("\n\n");
    printf("\nМаксимальные диагонали\n");
    Vector bb;
    bb = Maxfromdiag(a);
    cout << bb;
    printf("\n\n");
    SquareMatrix p = a.Arithmetic_mean();
    printf("Среднее арифметическое\n");
    cout << a;

    return 0;
