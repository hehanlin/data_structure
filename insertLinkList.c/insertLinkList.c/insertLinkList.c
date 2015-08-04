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


//头插法建立整张链表，传入头节点首地址，节点个数
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

//链表插入操作，接收一个头指针，要插入的位置，插入的数值
void insert(Node *phead, int n, elementtype x)
{
	if (n <= 0)return;
	int i = 1;
	Node *p = phead;
	while (p && i < n-1)
	{
		p = p->next;
		i++;
	}
	
	if (!p || i>n)return;

	Node *pnew = NULL;
	pnew = (Node *)malloc(sizeof(Node));
	pnew->data = x;
	pnew->next = p->next;
	p->next = pnew;

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

	//遍历整个链表
	Node *q = phead;
	int i;
	for (i = 0; i < n; i++)
	{
		printf_s("%3d", q->data);
		q = q->next;
	}

	printf_s("\nplease input insert position and value:");
	int j;
	elementtype y;
	scanf_s("%d", &j);
	scanf_s("%d", &y);
	printf_s("\n");
	insert(phead, j, y);
	n++;
	for (i = 0; i < n; i++)
	{
		printf_s("%3d", phead->data);
		phead = phead->next;
	}
	return(0);
}