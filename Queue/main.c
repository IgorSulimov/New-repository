#include <stdio.h>
#include "Queue.h"
int main()
{
	Queue* que = NULL;
	Push_Queue(&que, 33);
	Push_Queue(&que, 11);
	Push_Queue(&que, 22);
	Show_elements_queue(que);
	Pop_Queue(&que);
	printf("\n");
	Show_elements_queue(que);
	Pop_Queue(&que);
	printf("\n");
	Show_elements_queue(que);
}
