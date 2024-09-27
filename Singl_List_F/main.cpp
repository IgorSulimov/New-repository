#include "SinglList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// Дана Непустая последовательность слов, разделенных одним и более пробелом, за последним словом стоит точка.
// Длина слова не превышает m символов.
// Описать функцию которая организует слова в упорядоченный по алфавиту список 
// при этом для каждого слова указывается число его вхождений в эту последовательность
int main()
{
	char data[] = "d:/Word.txt";
	SList* list;
	list = Order_F(data);
	Print_List(list);
}
