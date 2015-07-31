#include "stdio.h"
#define MAXLEN 20

typedef int elementtype;

typedef struct
{
	elementtype s[MAXLEN];
	int length;
}List;

int insert();
int insert(List *list,elementtype x,int i)//����˵�������ĸ����Ա�壬���Ԫ����ʲô�����λ��������
{
	//�ж����Ա��Ƿ�Ϊ��
	if (list->length < 1)return(0);
	
	//�жϲ��λ���Ƿ��ں�������
	if (i<0 || i>list->length)return(0);

	//�����һ��Ԫ�ص���i��Ԫ�أ�������һ��
	int j;
	//������λ�øպ������Ա��ĩβ����ֱ��׷��
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
	//����֮ǰ��ӡ
	int i;
	for (i = 0; i < list.length; i++)
	{
		printf_s("%3d",list.s[i]);
	}
	//����
	elementtype x=9;
	printf_s("\nplease input\n");
	scanf_s("%d",&x);//ֱ��ʹ�ö���õ�ֵ��ȷ������scanf�������
	insert(&list, x, 1);

	//������ӡ
	for (i = 0; i < list.length; i++)
	{
		printf_s("%3d", list.s[i]);
	}

	return(0);
}

