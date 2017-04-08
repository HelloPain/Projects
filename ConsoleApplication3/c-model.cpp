#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;
link CreatLinkList()
{
	link head = NULL, r = NULL;
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		link p = (link)malloc(sizeof(node));
		if (p)
		{
			p->data = n; p->next = NULL;
			if (!head)
				head = p;
			else
				r->next = p;
			r = p;
		}
		else
			return NULL;
	}
	return head;
}
void Delete(link head, int v)
{
	link p = head, r = head;
	while (p)
	{
		if (p->data == v)
		{
			if (p == head)
				head = p->next;
		    r = p;
			p = p->next;
			free(r);
		}
	}

}
void out(link head)
{
	
	if (head->data>0)
	{
		link p = head;
		while (p)
		{
			printf("%d", p->data);
			if (p->next)
				printf(" ");
			p = p->next;
		}
		printf("\n");
	}
	else
		printf("NULL\n");
}
int main()
{
	link h = CreatLinkList();
	Delete(h, 5);
	out(h);
	system("pause");
	return 0;
}