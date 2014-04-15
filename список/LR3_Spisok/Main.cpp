#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Spisok
{
	int Value;
	Spisok *next;
	Spisok *prev;
	int number;
}List;

List *Entrance ()
{
 int i, n;
 List *new_List=new List;
 List *first;
 new_List->next=0;
 new_List->prev=0;
 printf ("\nEnter number of elements you want to add:\t");
 scanf ("%d", &n);
 first=new_List;
 printf ("\nEnter elements:\n");
 for (i=0; i<n; ++i)
 {
  new_List->number=i;
  scanf ("%d", &new_List->Value);
  new_List->next=new List;
  new_List->next->prev=new_List;
  new_List->next->next=0;
  new_List=new_List->next;
 }
 first->prev=new_List->prev;
 new_List=first;
 return new_List;
}

void print(List *copyList)
{
	int b=0;
	while (copyList->number!=0) copyList=copyList->prev;
	printf ("\nYour list:\n");
	do
	{
		if (b) copyList=copyList->next;
		printf ("%d\t", copyList->Value);
		b=1;
	} while (copyList->number <= copyList->next->number);
}

void AddToList (List *copyList)
{
	List *New=new List;
	int num;
	printf ("\nEnter number of element after which it will be added  new element:\t");
	scanf ("%d", &num);
	--num;
	while (copyList->number!=num) copyList=copyList->next;
	New->number=num+2;
	printf ("\nEnter value: ");
	scanf ("%d", &New->Value);
	New->prev=copyList;
	New->next=copyList->next;
	New->prev->next=New;	
	New->next->prev=New;
	while (New->number)
	{
		New->number=New->prev->number+1;
		New=New->prev;
	}
}

void DelFromList (List *copyList)
{
	int num;
	List *tmp;
	printf ("\nEnter number of elements you want to remove:\t");
	scanf ("%d", &num);
	--num;
	while (copyList->number!=num) copyList=copyList->next;
	tmp=copyList->next;
	copyList=copyList->prev;
	copyList->next=tmp;
	copyList->next->prev=copyList;
}

int main ()
{
 int i=0;
 List *MyList=new List;
 MyList=Entrance();
 print (MyList);
 AddToList(MyList);
 print (MyList);
 DelFromList(MyList);
 print (MyList);
 printf ("\n");
 system ("pause");
 return 0;
}