#include <stdio.h>
#include <stdbool.h>
#include <iostream>
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
	fclose(f1);
	return 0;
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
	int sum2 = 0;
	for (int line_sum = 0; line_sum < 1; line_sum++)
	{
		for (int column_sum = 0; column_sum < size; column_sum++)
		{
			tmp_sum += matrix[line_sum][column_sum];
		}
	}
	const int sum_each_line = tmp_sum;

   // check Line and Column
	for (int line = 0; line < size; line++)
	{
		for (int column = 0; column < size; column++)
		{
			sum += matrix[line][column];
			sum2 += matrix[column][line];
		}
		if (sum == sum_each_line && sum2 == sum_each_line)
		{
			sum = 0; 
			sum2 = 0;
		}
		else
			return false;
	}


	//check left diagonal 
	for (int line = 0,column2 = size - 1; line < size; line++,column2--)
	{
		int column = line;
		sum += matrix[line][column];
		sum2 += matrix[line][column2];
	}
	if (sum == sum_each_line && sum2 == sum_each_line)
	{
		sum = 0;
		sum2 = 0;
	}
	else
		return false;



	return true;

}

int Read_File(char* name_file, int size)
{
	FILE* f1;
	fopen_s(&f1, name_file, "r");
	fscanf_s(f1,"%d", &size);
	fclose(f1);
	return size;
}

int Write_File(char* name_file, int size)
{
	int elements;
	FILE* f1;
	fopen_s(&f1, name_file, "w");
	printf("Print SIZE\n");
	scanf_s("%d", &size);
	fprintf(f1, "%d\n", size);
	int tmp_size = size * size;
	printf("Print %d Elements\n", size * size);
	for (; tmp_size > 0; tmp_size--)
	{
		scanf_s("%d", &elements);
		fprintf(f1, "%d\n", elements);
	}
	fclose(f1);
	return size;
}
