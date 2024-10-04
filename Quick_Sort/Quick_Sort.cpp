#include <stdio.h>
#include "Function.h"

 int Quick_Sort_Right(int* arr, int left, int right) {
    int index_arr[100]; // массив для хранения индексов подмассивов
    int top = -1; // Указатель на верхушку index_arr

    // Сначала помещаем index_arr в  начальные индексы
    index_arr[++top] = left;
    index_arr[++top] = right;
    int d = 0;
    while (top >= 0) {
        d++;
        // Извлекаем верхние элементы
        right = index_arr[top--];
        left = index_arr[top--];

        int pivot = arr[right]; //pivot (последний)
        int i = (left - 1); // Индекс меньшего элемента


        for (int j = left; j < right; j++)
        {
            if (arr[j] < pivot) 
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[right]); // Ставим pivot на своё место
        int pivotIndex = i + 1; // Индекс pivot элемента

        // Если есть элементы слева от опорного
        if (pivotIndex - 1 > left) 
        {
            index_arr[++top] = left; // Левый подмассив
            index_arr[++top] = pivotIndex - 1;
        }

        // Если есть элементы справа от опорного
        if (pivotIndex + 1 < right) 
        {
            index_arr[++top] = pivotIndex + 1; // Правый подмассив
            index_arr[++top] = right;
        }
    }
    return d;
}

 void Quick_Sort_Recur(int* arr, int left, int right)
 {
     if (right < left)
         return;
     int p = arr[(left+right) / 2];
     int i = left;
     int j = right;
     while (i <= j)
     {
         while (arr[i] < p) i++;
         while (arr[j] > p) j--;
         if (i <= j)
         {
             swap(&arr[i], &arr[j]);
             i++;
             j--;
         }
     }
     Quick_Sort_Recur(arr, left, j);
     Quick_Sort_Recur(arr, i, right);
 }




int Quick_Sort_Midl(int arr[], int n)
{
     int stack[100];
     int top = -1;  

     stack[++top] = 0;
     stack[++top] = n - 1;

     int d = 0;
     while (top >= 0) {
         d++;
         int right = stack[top--];
         int left = stack[top--];

         if (left < right) {

             int mid = left + (right - left) / 2;
             int pivot = arr[mid];
             int i = left;
             int j = right;

             // Разделяем массив
             while (i <= j) {
                 while (arr[i] < pivot) {
                     i++;
                 }
                 while (arr[j] > pivot) {
                     j--;
                 }
                 if (i <= j) {
                     swap(&arr[i], &arr[j]);
                     i++;
                     j--;
                 }
             }

             // Помещаем индексы подмассивов в стек
             if (left < j) {
                 stack[++top] = left;       // Левый подмассив
                 stack[++top] = j;
             }
             if (i < right) {
                 stack[++top] = i;         // Правый подмассив
                 stack[++top] = right;
             }
         }
     }
         return d;
 }