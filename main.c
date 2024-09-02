#include <stdio.h>
#include "Struct.h"
int main()
{
	Stack* stack_ = NULL;
	stack_ = Push_stack(stack_, 33);
	stack_ = Push_stack(stack_, 22);
	stack_ = Push_stack(stack_, 1);
	stack_ = Push_stack(stack_, 123);
	stack_ = Push_stack(stack_, 15);
	Show_elements_stack(stack_);
	stack_ = Pop_Stack(stack_);
	printf("\n\n\n");
	Show_elements_stack(stack_);
}
