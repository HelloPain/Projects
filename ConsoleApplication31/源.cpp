#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nextptr;
};
typedef struct node NODE;
typedef NODE *link;

link CreatL()
{
	int n;
	printf("Please input a list(end by -1):");
	scanf("%d", &n);
	link headptr = NULL, p = NULL, lastptr = NULL;
	while (n != -1)
	{
		p = (link)malloc(sizeof(link));
		if (p != NULL)
		{
			p->data = n;
			if (headptr == NULL)
			{
				headptr = p;
				lastptr = p;
			}
			else
			{
				lastptr->nextptr = p;
				lastptr = p;
			}
		}
		scanf("%d", &n);
	}
	lastptr->nextptr = NULL;
	return headptr;
}//´´½¨Á´±í 

void Change(link *headptr, link *p, link *p0)
{
	link pnn, pn;
	pnn = (*p)->nextptr->nextptr;
	pn = (*p)->nextptr;
	if (*p == *headptr)
	{
		*headptr = (*p)->nextptr;
	}
	else
	{
		(*p0)->nextptr = (*p)->nextptr;
	}
	(*p)->nextptr->nextptr = *p;
	(*p)->nextptr = pnn;
	*p0 = pn;
}//Ê¹Á´±íÇ°ºóÁ½Ïî¶Ôµ÷ 

void SortL(link *headptr)
{
	link *p = (link *)malloc(sizeof(link)), *q = (link *)malloc(sizeof(link)), *p0=(link *)malloc(sizeof(link));
	*q = NULL;
	while (*q != *headptr)
	{
		*p = *headptr;
		*p0 = *headptr;
		while (((*p)->nextptr != NULL) && ((*p)->nextptr != *q))
		{
			if ((*p)->data>(*p)->nextptr->data)
			{
				Change(headptr, p, p0);
			}
			else
			{
				*p0 = *p;
				*p = (*p)->nextptr;
			}
		}
		*q = *p;
	}
}//Ã°ÅÝÅÅÐò 

void OutputL(link headptr)
{
	link p = headptr;
	printf("The new list is:");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->nextptr;
	}
}//Êä³öÁ´±í 

/*void FREE(link headptr)
{
	link p;
	while (headptr != NULL)
	{
		p = headptr;
		headptr = headptr->nextptr;
		free(p);
	}
}//ÊÍ·ÅÁ´±í */

int main()
{
	link headptr = CreatL();
	link *head = &headptr;
	SortL(head);
	OutputL(headptr);
	//FREE(headptr);
	system("pause");
	return 0;
}
