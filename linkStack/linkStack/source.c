#include <stdio.h>
#include <malloc.h>

typedef int SElemType;

typedef struct node
{
	SElemType data;
	struct node *next;
}node;

typedef struct
{
	node* top;
	int num;
}LinkStack;

void push(LinkStack *s, SElemType e)
{
	node *p = (node*)malloc(sizeof(node));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->num++;
}

void pop(LinkStack *s, SElemType *e)
{
	if (!(s->top) || NULL == (s->top))return;
	*e = (s->top)->data;
	node *p = (s->top)->next;
	free(s->top);
	s->top = p;
	s->num--;
}
int main(void)
{
	SElemType e = 0;
	LinkStack s;
	s.top = NULL;
	s.num = 0;
	
	printf_s("push:");
	for (size_t i = 0; i < 10; i++)
	{
		push(&s, i);
	}

	printf_s("pop:");
	for (size_t i = 0; i < 11; i++)
	{
		pop(&s, &e);
	}
	printf_s("%3d", e);
}