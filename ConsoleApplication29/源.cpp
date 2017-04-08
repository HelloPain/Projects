#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node, *link;

void insertL(link &head, link p)//�����������в���һ���ڵ�
{
	if (!head)//�ձ�
		head = p;
	else
	{
		link q = head, fq = head;
		for (; q&&q->data < p->data; fq = q, q = q->next);//�ҵ������
		if (q == head)
			head = p;
		else
			fq->next = p;
		p->next = q;
	}
}

link CreatL()
{
	int value = 0; link head = NULL;
	while (scanf("%d", &value) && value != -1)
	{
		link p = (link)malloc(sizeof(link));
		if (p)
		{
			p->data = value;
			p->next = NULL;
		}
		insertL(head, p);
	}
	return head;
}

void OUT(link head)//�������
{
	link p = head;//��p��������
	while (p)
	{
		printf("%d%c", p->data, p->next ? ' ' : '\n');
		p = p->next;
	}
}

int main()
{
	link head = CreatL();
	OUT(head);
	system("pause");
	return 0;
}