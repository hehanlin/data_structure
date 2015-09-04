#include <stdio.h>

#define MAXSIZE 5

typedef struct
{
	int front;
	int rear;
	int data[MAXSIZE];	
}queue;

int queueLength(queue *s)
{
	return (s->rear - s->front + MAXSIZE) % MAXSIZE;
}

void enQueue(queue *s, int e)
{
	if (queueLength(s) + 1 == MAXSIZE)return;
	s->data[s->rear] = e;
	s->rear = (s->rear + 1) % (MAXSIZE + 1);
}

void DeQueue(queue *s, int *e)
{
	if (queueLength(s) == 0)return;
	*e = s->data[s->front];
	s->front = (s->front + 1) % (MAXSIZE + 1);
}

int main(void)
{
	queue *s = {0};
	s->rear = 0;

	printf_s("en:");
	for (size_t i = 0; i <= MAXSIZE; i++)
	{
		enQueue(s, i);
	}
	for (size_t i = 0; i <= MAXSIZE; i++)
	{
		printf_s("%3d", s->data[i]);
	}
}