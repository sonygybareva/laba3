#include <stdio.h>
#include <stdlib.h>

int max=1;
int *Queue;
int lvl;

void Add(int i)
{
  ++lvl;
  if (lvl>max)
  {
	  realloc (Queue, lvl*sizeof (int));
	  max=lvl;
  }
  for (i=1; i<lvl; ++i) 
	  Queue[lvl-i]=Queue[lvl-i-1];
  Queue[0]=i;
}

int Get()
{
 --lvl;
 return Queue [lvl];
}

void Print (int Num)
{
	printf ("\nYour queue:\n");
	for (int i=0; i<Num; ++i) printf ("%d\t", Queue[i]);
}

void main ()
{
	int Num=0, tmp=0, del=0;
	Queue=(int *) calloc(65536, sizeof (int));
	printf ("\nHow many elements you want to Add?\n");
	scanf ("%d", &Num);
	printf ("\nEnter elements: \n");
	for (int i=0; i<Num; ++i)
	{
		scanf ("%d", &tmp);
		Add (tmp);
	}
	Print (Num);
	printf ("\nHow many elements you want to Get?\n");
	scanf ("%d", &del);
	printf ("\nYour elements:\n");
	for (int i=0; i<del; ++i)
	{
		if (!lvl) 
		{
			printf ("\nError: Queue is empty\n");
			break;
		}
		else printf ("%d\t", Get());
	}
	printf ("\n");
	free (Queue);
	system ("pause");
}