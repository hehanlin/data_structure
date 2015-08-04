#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "time.h"

typedef int elementtype;
typedef struct Node
{
	elementtype data;
	struct Node *next;
}Node;


//ͷ�巨����������������ͷ�ڵ��׵�ַ���ڵ����
void createLinkList(Node *phead,int n) 
{
	if (n <= 0)
	{
		return(0);
	}

	Node *p;
	int i;
	srand(time(0));

	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand()%9 + 1;
		p->next = phead->next;
		phead->next = p;
	}
}

int main()
{
	Node *phead = NULL;
	phead = (Node*)malloc(sizeof(Node));
	phead->data = rand() % 9 + 1;
	phead->next = NULL;
	printf_s("please input number of LinkList node:");
	int n;
	scanf_s("%d", &n);
	createLinkList(phead, n);

	//������������
	Node *q = phead;
	while (q->next != NULL)
	{
		printf_s("%3d", q->data);
		q = q->next;
	}
	return(0);
}