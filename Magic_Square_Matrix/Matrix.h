#pragma once
#include <stdbool.h>
int Creat_Matrix(char* name_file, int** matrix);
void Print_Matrix(int** matrix, size_t size_matrix);

bool Magick_Matrix(int** matrix, int size);

int Write_File(char* name_file, int size);

int Read_File(char* name_file, int size);
