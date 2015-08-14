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
	staticLinkList[MAXLEN-1].cur = 1;
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
	if (n >= MAXLEN-1)return(0);
	//if (staticLinkList[0].cur != 1 || staticLinkList[MAXLEN - 1].cur != 1)return(0);

	int i;
	for (i = 0; i < n; i++)
	{
		int j = malloc_arr(staticLinkList);
		staticLinkList[j].data = rand() % 9 + 1;
	}
	return(staticLinkList[MAXLEN].cur);
}



int main()
{
	initStaicLinkList();
	int n, i;
	n = 5;
	create(n);
	for (i = 1; i < MAXLEN; i++)
	{
		printf_s("%3d", staticLinkList[i].data);
	}

}