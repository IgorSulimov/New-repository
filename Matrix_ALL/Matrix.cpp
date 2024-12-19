#include <iostream>
#include <math.h>
#include "Matrix.hpp"
#include <iomanip>
using namespace std;

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
    try
    {
        if (row != other_.row || column != other_.column)
            throw exception("Матрицы должны быть одного размера");
        Matrix result(row, column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                result.matrix[i][j] = matrix[i][j] + other_.matrix[i][j];
        return result;
    }
    catch (const exception& ex)
    {
        cout << ex.what();
        exit(1);
    }
}

Matrix Matrix::operator-(const Matrix& other_) const
{
    try
    {
        if (row != other_.row || column != other_.column)
            throw exception("Матрицы должны быть одного размера");
        Matrix result(row, column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                result.matrix[i][j] = matrix[i][j] - other_.matrix[i][j];
        return result;
    }
    catch (const exception& ex)
    {
        cout << ex.what();
        exit(1);
    }
}

Matrix Matrix::operator*(const Matrix& other_) const
{
    try
    {
        if (column != other_.row)
            throw exception("Столбцы первой матрицы не равны строкам второй матрицы");
        Matrix result(row, other_.column);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < other_.column; j++)
                for (int k = 0; k < column; k++)
                    result.matrix[i][j] += matrix[i][k] * other_.matrix[k][j];
        return result;
    }
    catch (const exception& ex)
    {
        cout << ex.what();
        exit(1);
    }
}
Matrix Matrix::operator*(int data_) const
{
	Matrix result(row, column);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
			result.matrix[i][j] = matrix[i][j] * data_;
	}

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
istream& operator >>(istream& in, Matrix& mat)
{
    for (int i = 0; i < mat.row; i++)
        delete[] mat.matrix[i];
    delete[] mat.matrix;


    mat.matrix = new double* [mat.row];
    for (int i = 0; i < mat.row; i++) {
        mat.matrix[i] = new double[mat.column];
    }
    double value = 0;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.column; j++)
        {

            in >> value;
            mat[i][j] = value;
        }
    }
    return in;
}

ostream& operator<<(ostream& stream, Matrix& mat)
{
    stream << "\n";
    if (mat.row == 0 && mat.column == 0)
        stream << " Пустая";
    stream << setw(0) << left;
    for (int i = 0; i < mat.row; i++)
    {
        stream << "\n";
        stream << setw(0) << left;
        for (int j = 0; j < mat.column; j++)
        {

            stream << right << setw(6) << mat.matrix[i][j];
            stream.precision(4);
            stream << left << setw(0);
        }
    }
    stream << endl;
    return stream;
}

ifstream& operator>>(ifstream& in_, Matrix& matrix_)
{
    try
    {
        if (!in_.is_open())
            throw exception("Ошибка открытия файла");

        for (int i = 0; i < matrix_.row; i++)
            delete[] matrix_.matrix[i];
        delete[] matrix_.matrix;

        in_ >> matrix_.row;

        if (matrix_.row < 0)
            throw exception("Количество строк введено неверно");

        in_ >> matrix_.column;

        if (matrix_.column < 0)
            throw exception("Количество столбцов введено неверно");

        matrix_.matrix = new double* [matrix_.row];
        for (int i = 0; i < matrix_.row; i++) {
            matrix_.matrix[i] = new double[matrix_.column];
        }

        for (int i = 0; i < matrix_.row; ++i)
        {
            for (int j = 0; j < matrix_.column; ++j)
            {
                if (!(in_ >> matrix_.matrix[i][j]))
                {
                    throw exception("Данные матрицы введены неправильно");
                }
            }
        }

        return in_;
    }
    catch (const exception& ex)
    {
        cout << ex.what();
        exit(1);
    }
}
