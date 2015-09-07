#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 5

typedef struct
{
	int front;
	int rear;
	int data[MAXSIZE];	
}queue;

queue initQueue()
{
	queue s;
	s.front = s.rear = 0;
	return(s);
}

int queueLength(queue *s)
{
	return (s->rear - s->front + MAXSIZE) % MAXSIZE;
}

int enQueue(queue *s, int e)
{
	if (queueLength(s) + 1 == MAXSIZE)return(0);
	s->data[s->rear] = e;
	s->rear = (s->rear + 1) % MAXSIZE;
	return(1);
}

int DeQueue(queue *s, int *e)
{
	if (queueLength(s) == 0)return(0);
	*e = s->data[s->front];
	s->front = (s->front + 1) % MAXSIZE;
	return(1);
}

int main(void)
{
	queue s = initQueue();
	int e = 0;
	printf_s("en:");
	int j = 0;
	while (enQueue(&s, j))
	{
		j++;
	}
	for (size_t i = 0; i < (MAXSIZE-1); i++)
	{
		printf_s("%3d", s.data[i]);
	}

	printf_s("\nde:");
	DeQueue(&s, &e);
	printf_s("%3d", e);

	printf_s("\nen:");
	enQueue(&s, 8);
	printf_s("%3d%3d", s.front, s.rear);
	printf_s("%3d%3d", s.data[s.front], s.data[4]);

	printf_s("\nde all:");
	while (DeQueue(&s, &e))
		printf_s("%3d", e);
	printf_s("end:");
	printf_s("%3d%3d", s.front, s.rear);
	return(0);
}