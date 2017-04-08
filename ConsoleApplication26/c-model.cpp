#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;

link CreatList()//�������� 
{
	link head = NULL, p = NULL; int n = -1;//head����ͷ��pǰ����㣬n��������
	while (scanf("%d", &n) && n != -1)
	{
		link now = (link)malloc(sizeof(node));//��ǰ���
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

link MergeList(link head1, link head2)//�鲢������������
{
	if (!head2)
		return head1;
	else
	{
		link p = head1;
		for (; p->next; p = p->next);//�ҵ�����1���һ��Ԫ��//ÿ�ζ���Ҫ�ң���������
		if (p->data < head2->data)//ֱ�Ӳ��뵽����1�����
			p->next = head2;
		else
		{
			p = head1; link fp = head1;
			link q = head2, fq = head2;
			for (; p&&p->data < q->data; fp = p, p = p->next);//�ҵ���head1�еĲ����
			fp->next = q;
			for (; q&&q->data < p->data; fq = q, q = q->next);//�ҵ�head2�еĲ������ֹ��
			fq->next = p;
			MergeList(head1, q);
		}
	}
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
	link A = CreatList();
	link B = CreatList();
	A=MergeList(A, B);
	OUT(A);
	system("pause");
	return 0;
}