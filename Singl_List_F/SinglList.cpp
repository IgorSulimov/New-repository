#include "SinglList.h"
#include <iostream>
#pragma warning(disable:4996)

SList* creat_node()
{
	SList* element = new SList[sizeof(SList)];
	element->next = NULL;
	element->repeat = 1;
	element->size = 0;
	return element;
}

SList* creat_node(char* data_)
{
	SList* element = new SList[sizeof(SList)];
	element->next = NULL;
	element->repeat = 1;
	return element;
}

void Push_Top(SList** List, char* data_)
{
	SList* element = creat_node();
	strcpy(element->data, data_);

	if ((*List)->size == 0)
	{
		element->size = (*List)->size;
		*List = element;
	}
	else
	{
		element->size = (*List)->size;
		element->next = *List;
		*List = element;
	}
	(*List)->size++;
}

void Push_Back(SList** List, char* data_)
{
	SList* element = creat_node(data_);
	if ((*List)->size > 0)
	{
		SList* tmp = *List;
		while ((tmp)->next != NULL)
		{
			tmp = (tmp)->next;
		}
		(tmp)->next = element;
	}
	else
	{
		element->size = (*List)->size;
		(*List) = element;
	}
	(*List)->size++;
}

void Push_Place(SList** List, char* data_, int place,int rep)
{
	SList* element = creat_node();
	strcpy(element->data, data_);
	element->repeat = rep;
	SList* tmp = *List;
	SList* prev = creat_node();
	int fl = 1;
	if (fl == 1) {
		if (place == 0)
		{
			Push_Top(List, data_);
		}
		else
		{
			prev->next = tmp;
			for (; place; place--)
			{
				tmp = tmp->next;
				prev = prev->next;
			}
			prev->next = element;
			element->next = tmp;
			(*List)->size++;
		}
	}
}
char* Pop_Back(SList** List)
{
	char* delet_element;
	SList* tmp = *List;
	if ((*List)->size > 1)
	{
		SList* prev = creat_node();
		prev->next = tmp;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			prev = prev->next;
		}
		delet_element = tmp->data;
		free(tmp);
		prev->next = NULL;
		(*List)->size--;
	}
	else
	{
		SList* tmp = *List;
		delet_element = (tmp)->data;
		free(tmp);
		*List = creat_node();
	}
	return delet_element;
}

char* Pop_Top(SList** List)
{
	char* delet_element;
	if ((*List)->size > 1)
	{
		SList* tmp = creat_node();
		tmp->next = *List;
		*List = (*List)->next;
		tmp = tmp->next;
		delet_element = tmp->data;
		free(tmp);
		(*List)->size--;
	}
	else
	{
		SList* tmp = *List;
		delet_element = (tmp)->data;
		free(tmp);
		*List = creat_node();
	}
	return delet_element;
}


void Print_List(SList** List)
{
	SList* tmp = *List;
	if (List != NULL)
	{
		if (tmp->data != NULL)
		{
			while (tmp != NULL)
			{
				printf("%s %d\n", tmp->data,tmp->repeat);
				tmp = tmp->next;
			}
		}
	}
	else
	{
		printf("list is empty");
	}
}

void Toshka(SList** List)
{
	SList* tmp = *List;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	char toshka[100] = ".";
	strcat(tmp->data,toshka);
}

SList* Push_F(SList* List, char* name_file)
 {
	char word[200];
	FILE* f;
	fopen_s(&f, name_file, "r");
	if (!f)
		return NULL;
	while (fscanf(f, "%s", word) != -1)
	{
		SList* tmp = List;
		int place = 0;
		int rep = 1;
		int fl = 1;
		if ((List)->size == 0)
		{
			Push_Top(&List, word);
			fl = 0;
		}
			while (fl == 1)
			{


				if (strcmp(tmp->data, word) == 0 && fl == 1)
				{
					while (strcmp(tmp->data, word) == 0 && tmp->next != NULL)
					{
						place++;
						rep++;
						tmp = tmp->next;
					}
					if (tmp->next == NULL)
					{
						if (strcmp(tmp->data, word) == -1 && fl == 1)
						{
							place++;
							Push_Place(&List, word, place, rep);
							fl = 0;
						}
						if (strcmp(tmp->data, word) == 1 && fl == 1)
						{
							Push_Place(&List, word, place, rep);
							fl = 0;
						}
						if (strcmp(tmp->data, word) == 0 && fl == 1)
						{
							place++;
							rep++;
							Push_Place(&List, word, place, rep);
							fl = 0;
						}
					}
					if (fl == 1) 
					{
						Push_Place(&List, word, place, rep);
						fl = 0;
					}
				}


				if (strcmp(tmp->data, word) == -1 && fl == 1)
				{
					while (strcmp(tmp->data, word) == -1 && tmp->next != NULL)
					{
						place++;
						tmp = tmp->next;
					}
					if (tmp->next == NULL)
					{
						if (strcmp(tmp->data, word) == -1 && fl == 1)
						{
							place++;
							Push_Place(&List, word, place, rep);
							fl = 0;
						}
						if (strcmp(tmp->data, word) == 1 && fl == 1)
						{
							Push_Place(&List, word, place, rep);
							fl = 0;
						}
						if(strcmp(tmp->data,word) == 0 && fl == 1)
						{
							place++;
							rep++;
							Push_Place(&List, word, place, rep);
							fl = 0;
						}
					}
				}


				if (strcmp(tmp->data, word) == 1 && fl == 1)
				{
					Push_Place(&List, word, place,rep);
					fl = 0;
				}
			}
			if (fl == 1)
				Push_Place(&List, word, place,rep);
	}
	Toshka(&List);
	return List;
}