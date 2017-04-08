#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node,*link;
link CreatList()
{
	link head=NULL, front=NULL;
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		link p =(link) malloc(sizeof(node));
		p->data = n;p->next = NULL;
		if (!head)
			head = p;
		else
			front->next = p;
		front = p;
	}
	return head;
}
void Addnode(link &list,int value)//add n to the end of list
{
	link p = (link)malloc(sizeof(node));
	p->data = value; p->next = NULL;
	if (!list)//if list is still empty
		list = p;
	else
	{
		link front = list;
		for (; front->next; front = front->next);//find the last node
		front->next = p;
	}

}
void AdBandAjB(link A, link B, link &C1, link &C2)//A-B=C1,A^B=C2
{
	link a = A, b = B;
	while (a&&b)
	{
		if (a->data == b->data)
		{
			Addnode(C2, a->data);
			a = a->next; b = b->next;
		}
		else if (a->data > b->data)
		{
			b = b->next;
		}
		else if (a->data < b->data)
		{
			Addnode(C1, a->data);
			a = a->next;
		}
	}
	while (a)//A还有剩下
	{
		Addnode(C1,a->data);
		a = a->next;
	}
	while (b)
	{
		Addnode(C2, b->data);
		b = b->next;
	}
}
void Out(link l)
{
	if (!l)
		printf("NULL\n");
	else
	{
		link p = l;
		while (p)
		{
			printf("%d", p->data);
			if (p->next)//p不是最后一个
				printf(" ");
			else
				printf("\n");
			p = p->next;
		}
	}
}
int main()
{
	link A = CreatList(), B = CreatList();
	link C1 = NULL, C2 = NULL;
	AdBandAjB(A, B, C1, C2);
	Out(C1); Out(C2);
	system("pause");
	return 0;
}