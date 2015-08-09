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


//尾插法建立整张链表，传入头节点首地址，节点个数
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

//删除整张链表，传入头节点
int deleteLinkListAll(Node *phead)
{
	if (!phead)return(0);

	Node *p = phead;
	Node *q = NULL;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	phead->next = NULL;
	return(1);
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
	for (size_t i = 0; i < n; i++)
	{
		printf_s("%3d", q->data);
		q = q->next;
	}

	//删除整个链表
	deleteLinkListAll(phead);
	return(0);
}