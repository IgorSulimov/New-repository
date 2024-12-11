#include "Vector.hpp"
#include <stdio.h>

int main()
{
	int ar[] = { 1,2,3,10,16,33,44 };
	Vector arry(ar, 7);
	int ar2[] = { 1,2,3,10,16,33,52 };
	Vector arry2(ar2,7);
	cin >> arry;
	cout << arry;
	return 0;
 }