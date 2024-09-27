#pragma once

typedef struct SinglList
{
	char data[100];
	int repeat;
	struct SinglList* next;
	size_t size;
}SList;

SList* creat_node();
SList* creat_node(char* data_);

void Push_Top(SList** List,char* data_);

void Push_Back(SList** List, char* data_);

void Push_Place(SList** List, char* data_, int place,int rep);

SList* Order_F(char* name_file);


char* Pop_Back(SList** List);
char* Pop_Top(SList** List);
void Pop_Word(SList** List, char* data_);


void Print_List(SList* List);

void Push_Word(SList** List, char* data_);

