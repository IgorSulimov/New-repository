#include <stdio.h>
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Print_Arr(int* arr, int size) 
{
    for (int i = 0; i < size; i++)
    {
        printf("%d|", arr[i]);
    }
    printf("\n");
}