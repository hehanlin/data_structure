#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "time.h"


typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node *createNewNode();


//��һ��ȫ�ֱ���������ͷ�ڵ�
Node *phead = NULL;
Node *createLinkList(int n)
{

	if (n == 0)
	{
		Node *sunPoint = createNewNode();
		phead = sunPoint;
		return sunPoint;
	}
	else
	{
		Node *thePoint = createLinkList(--n);
		thePoint->data = 5;
		thePoint->next = createNewNode();
		return thePoint->next;
	}
	
}

Node *createNewNode()
{
	Node *sPoint = (Node*)malloc(sizeof(Node));
	return sPoint;
}

int main()
{
	//Node *headPoint = createNewNode();
	printf_s("please input number of LinkList node:");
	int n;
	scanf_s("%d", &n);
	int i = 0;
	createLinkList(n);
}