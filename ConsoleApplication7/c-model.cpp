
#include <stdio.h>

#include <string.h>

#include <stdlib.h>



typedef struct node

{

	char name[21];

	char ID[21];

	int grade;

	struct node * next;

} *link;



link CreateLink()

{

	char name[21] = { 0 };

	link head = (link)malloc(sizeof(node));

	link front = head, rear;

	while (gets(name) && strcmp(name, "#####") )

	{

		rear = (link)malloc(sizeof(node));

		front->next = rear;

		front = rear;

		strcpy(front->name, name);

		scanf("%s", front->ID);

		scanf("%d", &front->grade);

		front->next = NULL;

	}

	return head;

}



void Addnode(link source, link & dest)

{

	dest->next = source;

	dest = dest->next;

}



void Deletenode(link theNode)

{

	theNode->next = theNode->next->next;

}



link the1400(link source)

{

	link head = (link)malloc(sizeof(node));

	link rear = head;

	while (source->next)

	{

		if (source->next->grade >= 1400)

		{

			Addnode(source->next, rear);

			Deletenode(source);

			rear->next = NULL;

		}

		else

		{

			source = source->next;

		}

	}

	return head;

}



void Out(link theLink)

{

	while (theLink->next)

	{

		theLink = theLink->next;

		printf("%s\n", theLink->name);

	}

}



int main()

{

	link A, B;

	A = CreateLink();

	B = the1400(A);

	Out(B);

	system("pause");
	return 0;

}