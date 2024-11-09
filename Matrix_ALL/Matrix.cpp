#include <iostream>
#include <math.h>
#include "Matrix.hpp"

Matrix::Matrix(int row_, int column_)
{
    row = row_;
    column = column_;
    matrix = new double* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new double[column];
        for (int j = 0; j < column; j++)
            matrix[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& other_)
{
    row = other_.row;
    column = other_.column;

    matrix = new double* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new double[column];
        for (int j = 0; j < column; j++)
            matrix[i][j] = other_.matrix[i][j];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
}

Matrix& Matrix::operator=(const Matrix& other_)
{
    if (this == &other_) return *this;
    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
    row = other_.row;
    column = other_.column;
    matrix = new double* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new double[column];
        for (int j = 0; j < column; j++)
            matrix[i][j] = other_.matrix[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other_) const
{
    if (row != other_.row || column != other_.column)
        throw 2;
    Matrix result(row, column);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            result.matrix[i][j] = matrix[i][j] + other_.matrix[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix& other_) const
{
    if (row != other_.row || column != other_.column)
        throw 2;
    Matrix result(row, column);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            result.matrix[i][j] = matrix[i][j] - other_.matrix[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix& other_) const
{
    if (column != other_.row)
        throw 3;
    Matrix result(row, other_.column);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < other_.column; j++)
            for (int k = 0; k < column; k++)
                result.matrix[i][j] += matrix[i][k] * other_.matrix[k][j];
    return result;
}

double* Matrix::operator[](int i)
{
    if (i >= row || i >= column || i < 0)
        exit(1);

    return matrix[i];
}

Matrix Matrix::Transpose() const
{
    Matrix result(column, row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            result.matrix[j][i] = matrix[i][j];
    return result;
}

bool Matrix::operator==(const Matrix& other_) const
{
    if (row != other_.row || column != other_.column)
        return false;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (matrix[i][j] != other_.matrix[i][j])
                return false;

    return true;
}

bool Matrix::operator!=(const Matrix& other_) const
{
    return !(*this == other_);
}

void Matrix::Set_Element(int row_, int column_, double value_)
{
    if (row_ < 0 || row_ >= row || column_ < 0 || column_ >= column)
        throw 1;
    matrix[row_][column_] = value_;
}

double Matrix::Get_Element(int row_, int column_) const
{
    if (row_ < 0 || row_ >= row || column_ < 0 || column_ >= column)
        throw 1;
    return matrix[row_][column_];
}

void Matrix::Input()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++) {
            printf("Введите элемент [%d][%d]: ", i, j);
            if (!scanf("%lf", &matrix[i][j])) return;
        }
}


void Matrix::Output() const
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            printf("%lf ", matrix[i][j]);
        printf("\n");
    }
}

int Matrix::Get_Row()
{
    return row;
}

int Matrix::Get_Col()
{
    return column;
}


ostream& operator<<(ostream& stream, Matrix& mat)
{
    stream << "Матрица:";
    if (mat.Get_Row() == 0 && mat.Get_Col() == 0)
        stream << " Пустая";
    for (int i = 0; i < mat.Get_Row(); i++)
    {
        stream << "\n";
        for (int j = 0; j < mat.Get_Col(); j++)
        {
            stream << mat.Get_Element(i, j) << "|";
        }
    }
    return stream;
}

istream& operator >>(istream& in, Matrix& mat)
{
    for (int i = 0; i < mat.Get_Row(); i++)
    {
        for (int j = 0; j < mat.Get_Col(); j++)
        {
            in >> (mat[i][j]);
        }
    }
    return in;
}

