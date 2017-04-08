#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;
link CreatLinklist(int n)//创建长度为n的链表
{
	link pre, now, list = NULL;//list是表头
	int tmp, i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		now = (link)malloc(sizeof(node));
		if (now)
		{
			now->data = tmp;
			now->next = NULL;
			if (!list)
				list = now;
			else
				pre->next = now;
			pre = now;
		}
	}
	return list;
}
link Reserve_List(link h)
{
	link p = h, q = h->next, r ;
	p->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q; q = r;
	}
	return p;
}
void OUT(link h)
{
	link p = h;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
int main()
{
	link h = CreatLinklist(4);
	link p = Reserve_List(h);
	OUT(p);
	system("pause");
	return 0;
}