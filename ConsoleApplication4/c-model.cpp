#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char name[50];
	char ID[50];
	int grade;
	struct node *next;
}node,*link;
link CreatList()
{
	link head=NULL, r=NULL;
	char name[50] = { '\0' };
	while (scanf("%s", name) && strcmp(name, "#####"))
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
void AddList(link head)
{

}
void DealList(link head,int *A,int *B,int *C)
{
	link p = head;
	while (p)
	{
		switch (p->grade / 100)
		{
		case 12:case 13:(*B)++; break;
		case 14:case 15:case 16:(*A)++; break;
		default:(*C)++;
		}
		p = p->next;
	}
}
void FreeList(link head)
{
	link p = head, r;
	while (p)
	{
		r = p;
		p = p->next;
		free(r);
	}
}
int main()
{
	link h = CreatList();
	int A=0, B=0, C=0;
	DealList(h, &A, &B, &C);
	printf("%d\n%d\n%d\n", A, B, C);
	FreeList(h);
	system("pause");
	return 0;
}