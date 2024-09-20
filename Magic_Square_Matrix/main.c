#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <stdbool.h>
int main()
{
	int** matrix = 0;
	int size = 0;
	char format;
	char name[20] = "d:/Matrix.txt";
	printf("Choose what to do with the file:\nWrite to file 'w'\nRead from file 'r'\n");
	scanf_s("%c", &format);
	if (format == 'r')
		size = Read_File(name, size);
	if (format == 'w')
		size = Write_File(name, size);


	matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}

	Creat_Matrix(name, matrix);
	printf("\nMatrix:\n\n");
	Print_Matrix(matrix, size);
	if (("%d", Magick_Matrix(matrix, size)))
	{
		printf("\nMagick Square: True\n");
	}
	else
		printf("\nMagick Square: False\n");
}
