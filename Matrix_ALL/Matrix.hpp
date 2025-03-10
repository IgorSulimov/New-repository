#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

class Matrix
{
protected:
    int row;
    int column;
    double** matrix;

public:
    Matrix(int row_ = 2, int column_ = 3);
    Matrix(const Matrix& other_);
    ~Matrix();
    Matrix& operator=(const Matrix& other_);
    Matrix operator+(const Matrix& other_) const;
    Matrix operator-(const Matrix& other_) const;
    Matrix operator*(const Matrix& other_) const;
    double* operator[](int i);

    Matrix Transpose() const;
    bool operator==(const Matrix& other_) const;
    bool operator!=(const Matrix& other_) const;
    void Set_Element(int row_, int column_, double value_);
    double Get_Element(int row_, int column_) const;
    void Input();
    void Output() const;
    int Get_Row();
    int Get_Col();
    friend ostream& operator <<(ostream& stream, Matrix& mat);
    friend istream& operator >>(istream& stream, Matrix& mat);
    friend ifstream& operator>>(ifstream& in_, Matrix& matrix_);
    Matrix operator*(int data_) const;
};
ostream& operator <<(ostream& stream, Matrix& mat);
istream& operator >>(istream& stream, Matrix& mat);
ifstream& operator>>(ifstream& in_, Matrix& matrix_);
