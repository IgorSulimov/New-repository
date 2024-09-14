#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <stdbool.h>
int main()
{
	char name[] = "1.txt";
	int elements;
	int size;
	FILE* f1;
	fopen_s(&f1, name, "w");
	if (!f1)
		return -1;
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

	int** matrix = new int* [size];
	for (unsigned i = 0; i < size; i++)
		matrix[i] = new int [size];


	Creat_Matrix(name, matrix);
	printf("\nMatrix:\n\n");
	Print_Matrix(matrix, size);
	if (("%d", Magick_Matrix(matrix, size)))
	{
		printf("\nMagick Square: True\n");
	}
	else
		printf("\nMagick Square: False\n");

	delete(matrix);
	return 0;
	//matrix values and its size: 3|| 4 9 2 3 5 7 8 1 6
}

