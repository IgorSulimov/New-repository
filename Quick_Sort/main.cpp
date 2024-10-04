#include <stdio.h>
#include "Quick_Sort.h"
#include "Function.h"
#include <time.h>
int main() 
{
    int arr[] = {1,2,15,55,5,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Print_Arr(arr,n);
    Quick_Sort_Right(arr,0,n-1);
    Print_Arr(arr, n);

    Quick_Sort_Midl(arr,n);
    Print_Arr(arr, n);
    return 0;
}