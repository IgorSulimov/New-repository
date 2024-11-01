#include "Sq_Matrix.hpp"
#include "Matrix.hpp"

SquareMatrix::SquareMatrix(int size) : Matrix(size, size) {}
SquareMatrix::SquareMatrix(const SquareMatrix& other) : Matrix(other) {};



void SquareMatrix::Transpon()
{
	double temp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < i; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& other)
{
	if (this == &other) return *this;
	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
	row = other.row;
	column = other.column;
	matrix = new double* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[column];
		for (int j = 0; j < column; j++)
			matrix[i][j] = other.matrix[i][j];
	}
	return *this;
}

SquareMatrix SquareMatrix::pow(int n)
{
	SquareMatrix temp(row);
	for (int i = 0; i < row; i++)
	{
		temp.matrix[i][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		temp = temp * (*this);
	}
	return temp;
}

SquareMatrix SquareMatrix::operator*(SquareMatrix other)
{
	if (column != other.row)
		throw 3;
	SquareMatrix result(other.column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < other.column; j++)
			for (int k = 0; k < column; k++)
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
	return result;
}

SquareMatrix SquareMatrix::operator^(int n)
{
	if (column != row)
		throw 3;
	SquareMatrix result(column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			for (int k = 0; k < column; k++)
				result.matrix[i][j] += matrix[i][k] * matrix[k][j];
	return result;
}

Vector Maxfromdiag(SquareMatrix matrix) 
{
	int n = matrix.Get_Row();
	int size_vec = 2*n-1;
	Vector vec(size_vec);
	double max_left;
	double max_right;
	int left_vect = 0;
	int right_vect = size_vec-1;
	int n_ = n - 1;

	for (int i = n_; i != 0; i--)
	{
		max_left = 0;
		max_right = 0;

		for (int row_ = i, colum_ = 0; (row_ <= n_) && ( colum_ <= n_);)
		{
			if (matrix[row_][colum_] > max_left)
				max_left = matrix[row_][colum_];
			if (matrix[colum_][row_] > max_right)
				max_right = matrix[colum_][row_];
			row_++;
			colum_++;
		}
		vec.Set_elem(left_vect, max_left);
		left_vect++;
		vec.Set_elem(right_vect, max_right);
		right_vect--;
	}
	max_left = 0;
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i] > max_left)
			max_left = matrix[i][i];
	}
	vec.Set_elem(left_vect, max_left);

	return vec;

}