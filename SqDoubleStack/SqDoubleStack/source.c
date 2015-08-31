#include <stdio.h>

#define MAXSIZE 10

typedef int SElemType;

typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

void push1(SqDoubleStack *s, SElemType e)
{
	if (s->top1 == s->top2 - 1)
	{
		return;
	}
	s->data[++s->top1] = e;
}

void push2(SqDoubleStack *s, SElemType e)
{
	if (s->top2 == s->top1 + 1)
	{
		return;
	}
	s->data[--s->top2] = e;
}

void pop1(SqDoubleStack *s, SElemType *e)
{
	if (s->top1 == -1)
	{
		return;
	}
	*e = s->data[s->top1--];
}

void pop2(SqDoubleStack *s, SElemType *e)
{
	if (s->top2 == MAXSIZE)
	{
		return;
	}
	*e = s->data[s->top2++];
}

int main(void)
{
	SqDoubleStack s;
	s.top1 = -1;
	s.top2 = MAXSIZE;
	//push to 1
	printf_s("push to 1:");
	for (size_t i = 0; i < 7; i++)
	{
		push1(&s, i);
	}
	printf_s("num in all:\n");
	for (size_t i = 0; i < MAXSIZE; i++)
	{
		printf_s("%3d", s.data[i]);
	}
	//push to 2
	printf_s("\npush to 2:");
	for (size_t i = 0; i < 3; i++)
	{
		push2(&s, i);
	}
	printf_s("num in all:\n");
	for (size_t i = 0; i < MAXSIZE; i++)
	{
		printf_s("%3d", s.data[i]);
	}

	//pop from 1
	SElemType e = 0;
	pop1(&s, &e);
	printf_s("\nnum in 1:\n");
	for (size_t i = 0; i <= s.top1; i++)
	{
		printf_s("%3d", s.data[i]);
	}
	//pop from 1
	pop2(&s, &e);
	printf_s("\nnum in 2:\n");
	for (size_t i = 9; i >= s.top2; i--)
	{
		printf_s("%3d", s.data[i]);
	}
	//each all
	printf_s("\nnum in all:\n");
	for (size_t i = 0; i < MAXSIZE; i++)
	{
		printf_s("%3d", s.data[i]);
	}

	return(0);
}