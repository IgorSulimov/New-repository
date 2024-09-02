#include "Struct.h"
#include <stdlib.h>
#include <stdio.h>

Stack* Push_stack(Stack* stack_, int data)
{
	Stack* element = malloc(sizeof(Stack));
	element->data = data;
	element->next = NULL;
	if (stack_ == NULL)
	{
		stack_ = element;
	}
	else
	{
		element->next = stack_;
		stack_ = element;
	}

	return element;
}
void Show_elements_stack(Stack* stack_)
{
	Stack* element = stack_;
	while (element)
	{
		printf("%d||", element->data);
		element = element->next;
	}
}

Stack* Pop_Stack(Stack* stack_)
{
	if (stack_ == NULL)
		return;
	Stack* tmp = stack_;
	int data = tmp->data;
	stack_ = stack_->next;
	free(tmp);
	return stack_;
}