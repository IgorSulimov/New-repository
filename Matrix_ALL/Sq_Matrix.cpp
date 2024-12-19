#include "Sq_Matrix.hpp"
#include "Matrix.hpp"
#include <iomanip>

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
	try
	{
		if (column != other.row)
			throw exception("Столбцы первой матрицы не равны строкам второй матрицы");

		SquareMatrix result(other.column);

		for (int i = 0; i < row; i++)
			for (int j = 0; j < other.column; j++)
				for (int k = 0; k < column; k++)
					result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
		return result;
	}
	catch (const exception &ex)
	{
		cout << ex.what();
		exit(1);
	}
}
SquareMatrix SquareMatrix::Pow11(int power_)
	{
		try
		{
			if (column != row)
				throw exception("Столбцы и строки матрицы должны быть равны");
			SquareMatrix result = *this;

			for (int i = 2; i <= power_; ++i)
				result = result * *this;

			return result;
		}
		catch (const exception& ex)
		{
			cout << ex.what();
			exit(1);
		}
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

	Vector tracematrix(SquareMatrix & matrix, int n)
	{
		try
		{
			if (n <= 0)
				throw exception("Степень не может быть <= 0");
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
		catch (const exception& ex)
		{
			cout << ex.what();
			exit(1);
		}
	}
	//- - | - 0 | - + | 0 - | 0 + | + -| + 0 | + +
	SquareMatrix& SquareMatrix::Arithmetic_mean()
	{
		SquareMatrix tmp;
		for (int i = 0; i < tmp.row; i++)
			delete[] tmp.matrix[i];
		delete[] tmp.matrix;
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
	double SquareMatrix::Arif(SquareMatrix & mat, int r, int c)
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
		if (((i - 1) >= 0 && j + 1 <= mat.column - 1))
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
		if (j + 1 <= mat.column - 1)
		{
			sum += mat.matrix[i][j + 1];
			count++;
		}
		if (((i + 1) <= mat.row - 1 && j - 1 >= 0))
		{
			sum += mat.matrix[i + 1][j - 1];
			count++;
		}
		if ((i + 1) <= mat.row - 1)
		{
			sum += mat.matrix[i + 1][j];
			count++;
		}
		if (((i + 1) <= mat.row - 1 && j + 1 <= mat.column - 1))
		{
			sum += mat.matrix[i + 1][j + 1];
			count++;
		}
		return (sum / count);
	}
	ostream& operator<<(ostream& stream, SquareMatrix& mat)
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
	istream& operator >>(istream& in, SquareMatrix& mat)
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
	ifstream& operator>>(ifstream& in_, SquareMatrix& mat)
	{
		try
		{
			if (!in_.is_open())
				throw exception("Ошибка открытия файла");

			for (int i = 0; i < mat.row; i++)
				delete[] mat.matrix[i];
			delete[] mat.matrix;

			in_ >> mat.row;

			if (mat.row < 0)
				throw exception("Количество строк введено неверно");

			in_ >> mat.column;

			if (mat.column < 0)
				throw exception("Количество столбцов введено неверно");

			mat.matrix = new double* [mat.row];
			for (int i = 0; i < mat.row; i++) {
				mat.matrix[i] = new double[mat.column];
			}

			for (int i = 0; i < mat.row; ++i)
			{
				for (int j = 0; j < mat.column; ++j)
				{
					if (!(in_ >> mat.matrix[i][j]))
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
