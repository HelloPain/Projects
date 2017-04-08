#include <stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	struct Node * nextPtr;
};
typedef struct Node LIST1, LIST2;
typedef LIST1* LISTPTR1;
typedef LIST2* LISTPTR2;
typedef LIST1* LISTPTR;


void correctlist(LISTPTR1 headPtr1, LISTPTR2 headPtr2)
{
	LISTPTR1 currentPtr1;
	LISTPTR2 currentPtr2;
	currentPtr1 = headPtr1;
	currentPtr2 = headPtr2;
	int flage = 0;
	while ((currentPtr1 != NULL) && flage != 2)
	{
		while (currentPtr2 != NULL&&flage != 1)
		{
			while (currentPtr2&&currentPtr2->data != currentPtr1->data)
			{
				currentPtr2 = currentPtr2->nextPtr;
			}
			if (currentPtr2)
			{
				flage = 1;
			}
			else
			{
				flage = 2;
			}
		}
		currentPtr1 = currentPtr1->nextPtr;
	}
	if (flage == 1)
		printf("ListB is the sub sequence of ListA");
	else
		printf("ListB is not the sub sequence of ListA");

}

void freeList(LISTPTR headPtr)
{
	LISTPTR tempPtr = NULL;
	while (headPtr != NULL)
	{
		tempPtr = headPtr;
		headPtr = headPtr->nextPtr;
		free(tempPtr);
	}
}


int main()
{
	LISTPTR1 headPtr1=NULL, currentPtr1=NULL, lastPtr1=NULL;
	LISTPTR2	headPtr2=NULL, currentPtr2=NULL, lastPtr2=NULL;

	int num;
	scanf("%d", &num);
	while (num != -1) {
		currentPtr1 =(LISTPTR1) malloc(sizeof(LISTPTR1));
		if (currentPtr1 != NULL)
		{
			currentPtr1->data = num;
			if (headPtr1 == NULL)
			{
				headPtr1 = currentPtr1;
				lastPtr1 = currentPtr1;
			}
			else
			{
				lastPtr1->nextPtr = currentPtr1;
				lastPtr1 = currentPtr1;
			}
		}
		scanf("%d", &num);
	}
	lastPtr1->nextPtr = NULL;
	currentPtr1 = headPtr1;

	scanf("%d", &num);
	while (num != -1) {
		currentPtr2 =(LISTPTR2) malloc(sizeof(LISTPTR2));
		if (currentPtr2 != NULL)
		{
			currentPtr2->data = num;
			if (headPtr2 == NULL)
			{
				headPtr2 = currentPtr2;
				lastPtr2 = currentPtr2;
			}
			else
			{
				lastPtr2->nextPtr = currentPtr2;
				lastPtr2 = currentPtr2;
			}
		}
		scanf("%d", &num);
	}
	lastPtr2->nextPtr = NULL;
	currentPtr2 = headPtr2;

	correctlist(headPtr2, headPtr1);

	freeList(headPtr1);
	freeList(headPtr2);
	system("pause");
	return 0;
}