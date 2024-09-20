#include "SinglList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main()
{
	char data[] = "d:/Word.txt";
	SList* list = creat_node();
	list = Push_F(list, data);
	Print_List(&list);
	Pop_Top(&list);
	printf("\n\n");
	Print_List(&list);
}