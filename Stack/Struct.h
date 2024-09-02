#pragma once

typedef struct Stack
{
	int data;
	struct Stack* next;
}Stack;

Stack* Push_stack(Stack* stack_, int data);
void Show_elements_stack(Stack* stack_);
int Pop_Stack(Stack** stack_);


