#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <stdbool.h>
int main()
{
	//matrix values ??and its size: 3|| 4 9 2 3 5 7 8 1 6
	bool t;
	char* name = "d:/1.txt";
	int size;
	FILE* f1;
	fopen_s(&f1, "d:/1.txt", "r");
	if (!f1)
		return -1;
	fscanf_s(f1, "%d", &size);

	int** matrix = calloc(size, sizeof(int));
	for (unsigned i = 0; i < size; i++)
		matrix[i] = calloc(size, sizeof(int));
	fclose(f1);


	Creat_Matrix(name, matrix);
	Print_Matrix(matrix, size);
	printf("\n\n\n");
	printf("%d",Magick_Matrix(matrix, size));
}