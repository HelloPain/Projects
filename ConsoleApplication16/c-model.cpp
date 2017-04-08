#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *front;
}node,*link;
link Creatlist()
{
	link head = NULL, r = NULL;
	int n;
	while(scanf("%d",&n)&&n!=-1)
	{
		link p =(link) malloc(sizeof(node));
		p->data = n; p-> front= NULL;
		/*if(!head)
		head = p;
		else
		{
			p->front=r;
			head = p;
		}*/
		if (head)
			p->front = r;
		head = p;
		r = p;
	}
	return head;
}
void Out(link h)
{
	link p = h;
	while (p)
	{
		printf("%d ", p->data);
		p = p->front;
	}
}
int main()
{
	link h = Creatlist();
	Out(h);
	system("pause");
	return 0;
}