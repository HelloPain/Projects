#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;
link CreatList()//创建链表 
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
void SwapNodes(link &head, int s1, int t1, int s2, int t2)//假设输入符合要求
{
	link f1=NULL, f2=NULL;//s1,s2的前驱结点
	link p = head,S1=NULL,S2=NULL,T1=NULL,T2=NULL,T2L=NULL;
	for (int i = 1; p; p = p->next,i++)
	{
		if (i == s1 - 1)
			f1 = p;
		if (i == s1)
			S1 = p;
		if (i == t1)
			T1 = p;
		if (i == s2 - 1)
			f2 = p;
		if (i == s2)
			S2 = p;
		if (i == t2)
		T2 = p;
	}
	T2L = T2->next;
	T2->next = T1->next;
	T1->next = T2L; f2->next = S1;
	if (s1 != 1)
		f1->next = S2;
	else
		head = S2;
}
void OUT(link head)
{
	link p = head;
	while (p)
	{
		printf("%d%c", p->data, p->next ? ' ' : '\n');
		p = p->next;
	}
}
int main()
{
	link head = CreatList();
	int s1, t1, s2, t2;
	scanf("%d %d %d %d", &s1, &t1, &s2, &t2);
	SwapNodes(head, s1, t1, s2, t2);
	OUT(head);
	system("pause");
	return 0;
}