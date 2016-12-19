#include <stdio.h>
#include <stdlib.h> 

typedef struct{
	int size;
	int max;
	int *data;
}seqlist; 

void Inilist(seqlist *l, int n);

int main()
{
	seqlist s;
	Inilist(&s, 10);
	printf("%d\n", (&s)->max);
	printf("%d\n", s.size);
}

void Inilist(seqlist * l, int n)
{
	l->data=(int *)malloc(n*sizeof(int));
	if(l->data==NULL)
	{
		printf("Memory allocation error\n"); 
		exit(1);
	}
	l->size=0;
	l->max=n;
}
