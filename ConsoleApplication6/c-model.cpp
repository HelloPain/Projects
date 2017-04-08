#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char name[50];
	char ID[50];
	int grade;
	struct node *next;
}node, *link;
link CreatList()
{
	link head = NULL, r = NULL;
	char name[50] = { '\0' };
	while (scanf("%[^\n]", name) && strcmp(name, "#####"))
	{
		link p = (link)malloc(sizeof(node));
		strcpy(p->name, name);
		scanf("%s", p->ID);
		scanf("%d", &p->grade);
		p->next = NULL;
		if (!head)
			head = p;
		else
			r->next = p;
		r = p;
	}
	return head;
}
void Addnode(link &B,link p)//在h最后追加p
{
	if (!B)
		B = p;
	else
	{
		link q = B;
		while (q->next)
			q = q->next;
		q->next = p;
	}
}
void Deletenode(link h, link p)//delete p from h
{
	if (p == h)
		h = h->next;
	else
	{
		link q = h;
		for (;q->next&& q->next != p; q = q->next);//找到p前面那个
		q->next = p->next;
	}
	p->next = NULL;
}
link the1400(link h)//pick out persons whose grade >=1400
{
	link p = h;//B是listB的头
	link B = NULL;
	while (p)
	{
		link q = p->next;
		if (p->grade >= 1400)
		{
			Addnode(B,p);
			Deletenode(h, p);
		}
		p = q;
	}
	return B;
}
void Out(link l)
{
	link p = l;
	while (p)
	{
		printf("%s\n", p->name);
		p = p->next;
	}
}
int main()
{
	link A = CreatList();
	link B = the1400(A);
	Out(B);
	system("pause");
	return 0;
}