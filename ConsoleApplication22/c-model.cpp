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
void Insert_List(link &head)
{
	link key = head->next,fkey=head;
	while(key)
	{
		link p = head, front = head;
		int flag = 0;//是否找到元素
		for (; p != key&&(!flag); front = p, p = p->next)
		{
			if (p->data > key->data)
			{
				link tmp = key; key = key->next; flag = 1;
				if (head == p)
				{
					fkey->next=tmp->next; tmp->next = p; head = tmp;
				}
				else
				{
					fkey->next=tmp->next; front->next = tmp; tmp->next = p;
				}

			}
		
		}
		if (!flag)
		{
			fkey = key;
			key = key->next;
		}
	}
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
	Insert_List(head);
	OUT(head);
	system("pause");
	return 0;
}