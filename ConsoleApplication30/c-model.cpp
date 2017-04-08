#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node, *link;

void insertL(link &head, link p)//在升序链表中插入一个节点
{
	if (!head)//空表
		head = p;
	else
	{
		link q = head, fq = head;
		for (; q&&q->data < p->data; fq = q, q = q->next);//找到插入点
		if (q == head)
			head = p;
		else
			fq->next = p;
		p->next = q;
	}
}

link CreatL()//用插入节点的方式建立升序链表
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

link Merge_List(link A, link B)//将B归并到A
{
	link p = B;
	while(p)
	{
		link tmp = p->next;
		insertL(A, p);
		p = tmp;
	}
	return A;
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

void DestroyList(link head)//释放链表
{
	link p = head;//遍历结点
	while (p)
	{
		link r = p;//临时结点
		p = p->next;
		free(r);
	}
}

int main()
{
	link A = CreatL();
	link B = CreatL();
	OUT(Merge_List(A, B));
	DestroyList(A);
	system("pause");
	return 0;
}