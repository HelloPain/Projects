#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node,*link;
void insertL(link &head,link p)//�����������в���һ���ڵ�
{
		if (!head)//�ձ�
			head = p;
		else
		{
			link q = head, fq = head;
			for (; q&&q->data < p->data; fq=q,q = q->next);
			fq->next = p;
			p->next = q;
		}
}
link CreatL()
{
	while (scanf)
}
int main()
{
	system("pause");
	return 0;
}