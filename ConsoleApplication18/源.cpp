#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}Node, *Link;
Link CreatLinklist(int n)//��������Ϊn������
{
	Link pre, now, list = NULL;//list�Ǳ�ͷ
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
void insert(Link list, Link q, int a)//��q������a
{
	Link p = new Node();
	p->data = a;
	if (!list)//�������Ϊ��
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
void digui_OUT_deserve(Link p)//����
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
void Delete(Link list, Link q)//ɾ��q����node
{
	if (q == list)
		list = q->next;
	else
	{
		Link p = list;//ǰ���ڵ�
		for (; p->next != q; p = p->next);//�������ҵ�q��ǰ��node
		p->next = q->next;
	}
	delete q;//ע��ע��ע������������ɾ��������
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
		//Ѱ��ǰ�����
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