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
	int size_vec = 2 * n - 1;
	Vector vec(size_vec);
	double max_left;
	double max_right;
	int left_vect = 0;
	int right_vect = size_vec - 1;
	int n_ = n - 1;

	for (int i = n_; i != 0; i--)
	{
		max_left = 0;
		max_right = 0;

		for (int row_ = i, colum_ = 0; (row_ <= n_) && (colum_ <= n_);)
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
double SquareMatrix::trace()
{
	int size = Get_Row();
	double res = 0;
	for (int i = 0; i < size; i++)
	{
		res += matrix[i][i];
	}
	return res;
}

Vector tracematrix(SquareMatrix& matrix, int n)
{
	if (n <= 0)
	{
		throw 5;
	}
	double trace = 0;
	Vector result(n);
	SquareMatrix duplicate = matrix;
	for (int i = 0; i < n; i++)
	{
		result[i] = duplicate.trace();
		duplicate = duplicate * matrix;
	}
	return result;
}
//- - | - 0 | - + | 0 - | 0 + | + -| + 0 | + +
SquareMatrix& SquareMatrix::Arithmetic_mean()
{
	SquareMatrix tmp;
	tmp.row = row;
	tmp.column = column;
	tmp.matrix = new double* [row];
	for (int i = 0; i < row; i++) {
		tmp.matrix[i] = new double[column];
		for (int j = 0; j < column; j++)
			tmp.matrix[i][j] = matrix[i][j];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = Arif(tmp, i, j);
		}
	}
	return *this;
}
double SquareMatrix::Arif(SquareMatrix& mat, int r, int c)
{
	double sum = 0;
	int i = r, j = c;
	int count = 0;
	if (((i - 1) >= 0 && (j - 1) >= 0))
	{
		sum += mat.matrix[i - 1][j - 1];
		count++;
	}
	if (((i - 1) >= 0))
	{
		sum += mat.matrix[i - 1][j];
		count++;
	}
	if (((i - 1) >= 0 && j + 1 <= mat.column-1))
	{
		sum += mat.matrix[i - 1][j + 1];
		count++;
	}
	if
	 (((j - 1) >= 0))
	{
		sum += mat.matrix[i][j - 1];
		count++;
	}
	if(j + 1 <= mat.column-1)
	{
		sum += mat.matrix[i][j + 1];
		count++;
	}
	if(((i + 1) <= mat.row-1 && j - 1 >= 0))
	{
		sum += mat.matrix[i + 1][j - 1];
		count++;
	}
	if((i + 1) <= mat.row-1)
	{
		sum += mat.matrix[i + 1][j];
		count++;
	}
	if(((i + 1) <= mat.row-1 && j + 1 <= mat.column-1))
	{
		sum += mat.matrix[i + 1][j + 1];
		count++;
	}
	return (sum/count);
}
