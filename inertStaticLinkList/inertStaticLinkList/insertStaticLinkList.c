#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLEN 20

typedef int elementtype;
struct link
{
	elementtype data;
	int cur;
}staticLinkList[MAXLEN];

void initStaicLinkList()
{
	int i;
	for (i = 0; i < MAXLEN - 1; i++)
		staticLinkList[i].cur = i + 1;
	staticLinkList[MAXLEN - 1].cur = 1;
}

int malloc_arr()
{
	int i = staticLinkList[0].cur;

	if (staticLinkList[0].cur)
	{
		staticLinkList[0].cur = staticLinkList[i].cur;
	}

	return(i);
}

int create(int n)
{
	if (n >= MAXLEN - 1)return(0);
	//if (staticLinkList[0].cur != 1 || staticLinkList[MAXLEN - 1].cur != 1)return(0);

	int i;
	for (i = 0; i < n; i++)
	{
		int j = malloc_arr();
		staticLinkList[j].data = rand() % 9 + 1;
	}
	return(staticLinkList[MAXLEN].cur);
}

//传入插入的数值，要在哪个节点前插入
void insert(elementtype s,int n)
{
	int j,k;
	k = staticLinkList[MAXLEN - 1].cur;
	if (n > staticLinkList[0].cur || n < 1)return;
	
	j = malloc_arr();
	staticLinkList[j].data = s;
	for (size_t i = 1; i < n-1; i++)
	{
		k = staticLinkList[k].cur;
	}
	staticLinkList[j].cur = staticLinkList[k].cur;
	staticLinkList[k].cur = j;
}

int main()
{
	initStaicLinkList();
	int n, i;
	n = 5;
	create(n);

	int nowSize = staticLinkList[0].cur - 1;
	for (i = 1; i <= nowSize; i++)
	{
		printf_s("%3d", staticLinkList[i].data);
	}

	printf_s("\nplease input number of position and value:");
	int k,m;
	scanf_s("%d%d", &k,&m);
	insert(k,m);

	nowSize = staticLinkList[0].cur - 1;
	for (i = 1; i <= nowSize; i++)
	{
		printf_s("%3d", staticLinkList[i].data);
	}
	
	return(0);
}