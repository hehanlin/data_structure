#include "stdio.h"
#define MAXLEN 20

typedef int elementtype;

typedef struct
{
	elementtype s[MAXLEN];
	int length;
}List;

//����listָ�룬ɾ����i��Ԫ�أ���ɾ����Ԫ�ص�ֵ����p��
int deleteList(List *list, int i)
{
	if (list->length < 0)
	{
		return(0);
	}
	
	if (i<0 || i>(list->length - 1))
	{
		return(0);
	}
	int j;
	if (i != (list->length - 1)) {
		for (j = i; j <= (list->length - 1); j++)
		{
			list->s[j] = list->s[j + 1];
		}
	}

	list->length--;
	return(1);
}

int main()
{
	List q = { 1,2,3,4,5,6,7,8,9 };
	q.length = 9;
	int i;
	for (i = 0; i <= (q.length - 1); i++)
	{
		printf_s("%3d", q.s[i]);
	}

	printf_s("\nplease input number of node:");
	elementtype j;
	scanf_s("%d", &j);

	deleteList(&q, j);

	for (i = 0; i <= (q.length - 1); i++)
	{
		printf_s("%3d", q.s[i]);
	}
	return(0);
}