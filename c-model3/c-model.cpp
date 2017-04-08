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

void Swap_Node(link head,link p,link &fp)//����head�е�p��p->next,fpΪǰ�����
{
	link tmp = p->next->next;
	if (p == head)
		head = p->next;
	else
		fp->next = p->next;
	p->next->next = p;
	p->next = tmp;
	fp = fp->next;
}

void Bubble_Sort(link head)
{
	link p = NULL, end = NULL;
	for (; end != head; end = p)
	{
		p = head; link fp = head;
		while (p->next&&p->next != end)
		{
			if (p->data > p->next->data)
				Swap_Node(head, p, fp);
			else
			{
				fp = p;
				p = p->next;
			}
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

void DestroyList(link head)//�ͷ�����
{
	link p = head;//�������
	while (p)
	{
		link r = p;//��ʱ���
		p = p->next;
		free(r);
	}
}

int main()
{
	link head = CreatList();
	Bubble_Sort(head);
	OUT(head);
	DestroyList(head);
	system("pause");
	return 0;
}