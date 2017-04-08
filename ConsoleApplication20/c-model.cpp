#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}
node,*link;
link CreatList()
{
	link head=NULL, p=NULL; int n=-1;
	while (scanf("%d", &n) && n != -1)
	{
		link now =(link) malloc(sizeof(node));
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
int findMax(link now)
{
	if (!(now->next))//最后一个
		return now->data;
	return now->data > findMax(now->next) ? now->data:findMax(now->next);

}
int Sum(link now)
{
	if (!(now->next))
		return now->data;
	return now->data + Sum(now->next);
}
int main()
{
	link head = CreatList();
	printf("%d %d", findMax(head), Sum(head));
	system("pause");
	return 0;
}