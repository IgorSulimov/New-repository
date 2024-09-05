#include <stdio.h>
#include <stdbool.h>
int Creat_Matrix(char* name_file, int** matrix)
{
	int size;
	FILE* f1;
	fopen_s(&f1, name_file, "r");
	if (!f1)
		return -1;
	fscanf_s(f1, "%d", &size);

	for (int line = 0; line < size; line++)
	{
		for (int column = 0; column < size; column++)
		{
			fscanf_s(f1, "%d", &matrix[line][column]);
		}
	}
	return 0;
	fclose(f1);
}

void Print_Matrix(int** matrix, size_t size_matrix)
{
	for (int line = 0; line < size_matrix; line++)
	{
		for (int column = 0; column < size_matrix; column++)
		{
			printf("%d|", matrix[line][column]);
		}
		printf("\n");
	}

}

bool Magick_Matrix(int** matrix, int size)
{
	//SUM EACH LINES
	int sum = 0;
	int tmp_sum = 0;
	for (int line_sum = 0; line_sum < 1; line_sum++)
	{
		for (int column_sum = 0; column_sum < size; column_sum++)
		{
			tmp_sum += matrix[line_sum][column_sum];
		}
	}
	const int sum_each_line = tmp_sum;


	//check line (from left to right)
	for (int line = 0; line < size; line++)
	{
		for (int column = 0; column < size; column++)
		{
			sum += matrix[line][column];
		}
		if (sum == sum_each_line) 
			sum = 0;
		else
			return false;
	}

	//check column (top down)
	for (int line = 0; line < size; line++)
	{
		for (int column = 0; column < size; column++)
		{
			sum += matrix[column][line];
		}
		if (sum == sum_each_line)
			sum = 0;
		else
			return false;
	}

	//check left diagonal (from top left to bottom right)
	for (int line = 0; line < size; line++)
	{
		int column = line;
		sum += matrix[line][column];
	}
	if (sum != sum_each_line)
		return false;
	else
		sum = 0;

	//check right diagonal (from top right to bottom left)
	for (int line = size-1; line >= 0; line--)
	{
		int column = line;
		sum += matrix[line][column];
	}
	if (sum != sum_each_line)
		return false;


	return true;

}