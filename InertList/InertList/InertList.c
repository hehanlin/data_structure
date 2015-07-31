#include "stdio.h"
#define MAXLEN 20

typedef int elementtype;

typedef struct
{
	elementtype s[MAXLEN];
	int length;
}List;

int insert();
int insert(List *list,elementtype x,int i)//参数说明，往哪个线性表插，插的元素是什么，插的位置在哪里
{
	//判断线性表是否为空
	if (list->length < 1)return(0);
	
	//判断插的位置是否在合理区间
	if (i<0 || i>list->length)return(0);

	//从最后一个元素到第i个元素，都各退一步
	int j;
	//如果插的位置刚好是线性表的末尾，则直接追加
	if (i != list->length) {
		for (j = list->length - 1; j >= i; j--)
		{
			list->s[j + 1] = list->s[j];
		}
	}
	list->s[i] = x;
	list->length++;
}

int main()
{
	List list={ 1,2,3,4,5,6,7,8,9 };
	list.length = 9;
	//插入之前打印
	int i;
	for (i = 0; i < list.length; i++)
	{
		printf_s("%3d",list.s[i]);
	}
	//插入
	elementtype x=9;
	printf_s("\nplease input\n");
	scanf_s("%d",&x);//直接使用定义好的值正确，但是scanf输入错误
	insert(&list, x, 1);

	//插入后打印
	for (i = 0; i < list.length; i++)
	{
		printf_s("%3d", list.s[i]);
	}

	return(0);
}

