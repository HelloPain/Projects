#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}
node, *link;
link CreatList()//´´½¨Á´±í 
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

void Insert_Sort(link h)
{
	link key = h->next,  p, q;
	h->next = NULL;
	while (key)
	{
		for (p = key, q = h; q&&q->data < key->data;p=q, q = q->next);
		key = key->next;
		if (q == h)
			h = key;
		else

	}
}
void OUT(link h)
{
	link now = h;
	while (now)
	{
		printf("%d%c", now->data,now->next?' ':'\n');	
		now = now->next;
	}
	
}
int main()
{
	link h = CreatList();
	Insert_Sort(h);
	OUT(h);
	system("pause");
	return 0;
}