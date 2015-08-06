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

//ɾ������Ԫ�ز���������ͷ�ڵ㣬Ҫɾ����Ԫ��λ��(��1��ʼ�㣩
elementtype delete(Node *phead, int n)
{
	//pΪҪɾ���ڵ��ǰһ���ڵ㣬ͨ���ı�ýڵ��next������ʵ��ɾ��
	Node *p = phead;
	//qΪҪɾ���Ľڵ�
	Node *q = NULL;
	int i = 1;
	while (p && i<n-1)
	{
		p = p->next;
		i++;
	}

	if (!p || i>n - 1)return;

	q = p->next;

	elementtype a = q->data;

	p->next = q->next;
	
	free(q);

	return(a);

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

	//ɾ���ڵ�

	printf_s("\nplease input number of delete node:");
	int j;
	scanf_s("%d", &j);
	delete(phead, j);
	n--;
	for (size_t i = 0; i < n; i++)
	{
		printf_s("%3d", phead->data);
		phead = phead->next;
	}
	return(0);
}