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


//β�巨����������������ͷ�ڵ��׵�ַ���ڵ����
void createLinkList(Node *phead, int n)
{
	if (n <= 0)
	{
		return;
	}

	Node *pnew = NULL;
	Node *ptail = NULL;
	ptail = phead;
	int i;

	for (i = 1; i < n; i++)
	{
		pnew = (Node*)malloc(sizeof(Node));
		pnew->data = rand() % 9 + 1;
		ptail->next = pnew;
		ptail = pnew;
	}
	ptail->next = NULL;
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
	for (size_t i = 0; i < n; i++)
	{
		printf_s("%3d", q->data);
		q = q->next;
	}
	return(0);
}