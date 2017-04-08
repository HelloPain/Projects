#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;

link CreatList()//创建链表 
{
	link head = NULL, p = NULL; int n = -1;//head链表头，p前驱结点，n读入数字
	while (scanf("%d", &n) && n != -1)
	{
		link now = (link)malloc(sizeof(node));//当前结点
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

link MergeList(link head1, link head2)//归并两个有序链表
{
	if (!head2)
		return head1;
	else
	{
		link p = head1;
		for (; p->next; p = p->next);//找到链表1最后一个元素//每次都需要找？？？！！
		if (p->data < head2->data)//直接插入到链表1的最后
			p->next = head2;
		else
		{
			p = head1; link fp = head1;
			link q = head2, fq = head2;
			for (; p&&p->data < q->data; fp = p, p = p->next);//找到在head1中的插入点
			fp->next = q;
			for (; q&&q->data < p->data; fq = q, q = q->next);//找到head2中的插入的终止点
			fq->next = p;
			MergeList(head1, q);
		}
	}
}

void OUT(link head)//输出链表
{
	link p = head;//用p遍历链表
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