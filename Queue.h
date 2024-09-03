#pragma once


typedef struct Queue
{
	int data;
	struct Queue* next;
	struct Queue* back;

}Queue;

void Push_Queue(Queue** stack_, int data);
void Show_elements_queue(Queue* stack_);
int Pop_Queue(Queue** queue_);

