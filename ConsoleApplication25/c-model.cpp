#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node, *link;

link* hash = NULL;
int n;


link* Creat_Hash()//创建长度为n的哈希表
{
	link *Hash = (link*)malloc(sizeof(link)*n);
	for (int i = 0; i < n; i++)
		Hash[i] = NULL;
	return Hash;
}

void Add_Node(int value)//在哈希表中插入节点
{
	int i = value%n;
	link p = (link)malloc(sizeof(link));
	p->data = value; p->next = NULL;
	if (!hash[i])
		hash[i] = p;
	else
	{
		link q = hash[i];
		for (; q->next; q = q->next);//找到最后一个节点
		q->next = p;
	}
}

void OUT_Hash()
{
	for (int i = 0; i < n; i++)
	{
		link p = hash[i];
		while (p)
		{
			printf("->%d", p->data);
			p = p->next;
		}
		printf("->NULL\n");
	}
}

/*void Destroy_Hash()
{
	for (int i = 0; i < n; i++)
	{
		link p = hash[i];//用p遍历链表
		while (p)
		{
			link r = p;
			p = p->next;
			free(r);
		}
	}
}
*/
int main()
{
	scanf("%d", &n);
	hash = Creat_Hash();
	int value = -1;
	while (scanf("%d", &value) && value != -1)
		Add_Node(value);
	OUT_Hash();
	//Destroy_Hash();
	system("pause");
	return 0;
}