#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;
link CreatList()//�������� 
{
	link head = NULL, p = NULL; int n = -1;
	while (scanf("%d", &n) && n != -1)
	{
		link now = (link)malloc(sizeof(node));
		if (now)
		{
			now->data = n;
			now->next = NULL;
			if (!head)
				head = now;
			else
				p->next = now;
			p = now;
		}
		else
			return NULL;
	}
	return head;
}
void DestroyList(link head)
{
	link p = head;
	while (p)
	{
		link r = p;
		p = p->next;
		free(r);
	}
}
void Delete_Node(link head, link fp, link p)//��head��ɾ��p
{
	if (p == head)
		head = head->next;
	else
		fp->next = p->next;
	free(p);
}
int Match(link A,link B)//B�Ƿ���A��������
{
	int flag = 1;//1��ʾ��ǰ���ֳ�����A���У�0��ʾû��
	for (link b=B; b&&flag; b = b->next)
	{
		link a,fa; int find = 0;
		for ( a = A,fa=A; a&&!find;fa=a, a = a->next)
		{
			if (a->data == b->data)
			{
				Delete_Node(A, fa,a);
				find = 1;
			}
		}
		if (!find)
			flag = 0;
	}
	return flag;
}

int main()
{
	link A = CreatList(), B = CreatList();
	printf("%d",Match(A, B));
	DestroyList(A); DestroyList(B);
	system("pause");
	return 0;
}