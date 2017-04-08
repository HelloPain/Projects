#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}Node, *Link;
Link CreatLinklist(int n)//创建长度为n的链表
{
	Link pre, now, list = NULL;//list是表头
	int tmp, i;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		now = new Node();
		now->data = tmp;
		now->next = NULL;
		if (!list)
			list = now;
		else
			pre->next = now;
		pre = now;
	}
	//now->next = list;
	return list;
}
void insert(Link list, Link q, int a)//在q处插入a
{
	Link p = new Node();
	p->data = a;
	if (!list)//如果链表为空
	{
		list = p;
		p->next = NULL;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}
void digui_OUT(Link p)
{
	if(!p)
		return;
	cout << p->data << " ";
	digui_OUT(p->next);
}
void reversePrintList(Link headPtr){	if (headPtr->next == NULL)		printf("%d", headPtr->data);	else {		reversePrintList(headPtr->next);		printf("%d", headPtr->data);	}}
void digui_OUT_deserve(Link p)//逆序
{
	if (!p)
		return;
	digui_OUT_deserve(p->next);
	cout << p->data << ' ';
}
void Max_point(Link &Max, Link p)
{
	if (p)
	{
		if (p->data > Max->data)
			Max = p;
		Max_point(Max, p->next);
	}
}
void OUT(Link list, int n)
{
	int i;
	Link tmp = list;
	for (i = 0; i < n; i++)
	{
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
}
void Delete(Link list, Link q)//删除q处的node
{
	if (q == list)
		list = q->next;
	else
	{
		Link p = list;//前驱节点
		for (; p->next != q; p = p->next);//遍历，找到q的前驱node
		p->next = q->next;
	}
	delete q;//注意注意注意这才是正真的删除！！！
}
void destroyLinklist(Link list)
{
	Link p, q;
	p = list;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
}
/*void DeserveList(Link h)
{
	Link rh;
	Link p = h,front=h;
	for (; p->next; front = p, p = p->next);
	rh = p;
	while (p != h)
	{
		p->next = front;
		//寻找前驱结点
		p = p->next;
		for (front = h; front->next != p; front = front->next);
		
	}
}*/
Link Reserve_List(Link h) 
{
	Link p = h, q = h->next, r = q->next;
	p->next = NULL;
	while (q)
	{
		q->next = p;
		p = q; q = r;
		if(!r)r = r->next;
	}
	return p;
}
int main()
{
	Link h = CreatLinklist(3);
	Link p=Reserve_List(h);
	OUT(p,3);
	system("pause");
	return 0;
}