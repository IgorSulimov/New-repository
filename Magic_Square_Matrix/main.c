#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <stdbool.h>
int main()
{
	char* name = "d:/1.txt";
	int elements;
	int size;
	FILE* f1;
	fopen_s(&f1, name, "w");
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

	int** matrix = calloc(size, sizeof(int));
	for (unsigned i = 0; i < size; i++)
		matrix[i] = calloc(size, sizeof(int));


	Creat_Matrix(name, matrix);
	printf("\nMatrix:\n\n");
	Print_Matrix(matrix, size);
	if (("%d", Magick_Matrix(matrix, size)))
	{
		printf("\nMagick Square: True\n");
	}
	else
		printf("\nMagick Square: False\n");

//matrix values and its size: 3|| 4 9 2 3 5 7 8 1 6
}
