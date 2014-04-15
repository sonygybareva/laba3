#include <stdio.h>
#include <stdlib.h>

int max=1;
int *Stack;
int lvl;

void push(int i)
{
  ++lvl;
  if (lvl>max)
  {
	  realloc (Stack, lvl*sizeof (int));
	  max=lvl;
  }
  Stack[lvl-1]=i;
}

int pop()
{
 --lvl;
 return Stack [lvl];
}

void Print (int Num)
{
	printf ("\nYour list:\n");
	for (int i=0; i<Num; ++i) printf ("%d\t", Stack[i]);
}

void main ()
{
	int Num=0, tmp=0, del=0;
	Stack=(int *) calloc(65536, sizeof (int));
	printf ("\nHow many elements you want to push?\n");
	scanf ("%d", &Num);
	printf ("\nEnter elements: \n");
	for (int i=0; i<Num; ++i)
	{
		scanf ("%d", &tmp);
		push (tmp);
	}
	Print (Num);
	printf ("\nHow many elements you want to pop?\n");
	scanf ("%d", &del);
	printf ("\nYour elements:\n");
	for (int i=0; i<del; ++i)
	{
		if (!lvl) 
		{
			printf ("\nError: Stack is empty\n");
			break;
		}
		else printf ("%d\t", pop());
	}
	printf ("\n");
	free (Stack);
	system ("pause");
}