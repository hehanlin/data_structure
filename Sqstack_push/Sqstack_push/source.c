#include <stdio.h>

#define MAXSIZE 5

typedef int SElemType;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}Sqstack;

void push(Sqstack *s,SElemType e)
{
	if (s->top == MAXSIZE-1)
	{
		return;
	}
	s->top++;
	s->data[s->top] = e;
}

void pop(Sqstack *s,SElemType *e)
{
	if (s->top == -1)
	{
		return;
	}
	*e = s->data[s->top];
	s->top--;
}

int main(void)
{
	Sqstack s;
	s.top = -1;
	for (size_t i = 0; i < MAXSIZE; i++)
	{
		push(&s, i);
	}
	for (size_t i = 0; i < MAXSIZE; i++)
	{
		printf_s("%3d", s.data[i]);
	}

	//pop
	printf_s("\npop:");
	SElemType e = 0;
	pop(&s, &e);
	for (size_t i = 0; i <= s.top; i++)
	{
		printf_s("%3d", s.data[i]);
	}
	printf_s("\npop num:%3d", e);
	return(0);
}