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
Node *createLinkList(int n)
{

	if (n == 0)
	{
		Node *sunPoint = createNewNode();
		return sunPoint;
	}
	else
	{
		Node *thePoint = createLinkList(--n);
		thePoint->data = 5;
		thePoint->next = createNewNode();
		return thePoint->next;
	}
	/*
	int m = n;
	if (m == n)
	{
		Node *sunPoint;
		sunPoint = createNewNode();
		sunPoint->data = 5;
		sunPoint->next = createNewNode();
		return sunPoint->next;
	}
	else
	{
		m++;
		Node *thePoint = createLinkList(m);
		thePoint->data = 5;
		thePoint->next = createLinkList(m-1);

	}
	*/
	

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
	Node *headPoint = createLinkList(n);
}