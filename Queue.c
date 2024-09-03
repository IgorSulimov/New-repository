#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

void Push_Queue(Queue** queue_, int data)
{
	Queue* element = malloc(sizeof(Queue));
	element->data = data;
	element->next = NULL;
	if (*queue_ == NULL)
	{
		*queue_ = element;
		(*queue_)->back = element;
	}
	else
	{
		element->next = (*queue_)->back;
		(*queue_)->back = element;
	}
}
void Show_elements_queue(Queue* queue_)
{
 	Queue* element = queue_->back;
	while (element)
	{
		printf("%d||", element->data);
		element = element->next;
	}
}

int Pop_Queue(Queue** queue_)
{
	if (queue_ == NULL)
		return;
	Queue* tmp = (*queue_)->back;
	int data = tmp->data;
	(*queue_)->back = tmp->next;
	free(tmp);
	return data;
}