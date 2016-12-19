#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *data;
	int size;
	int max;
}orderlist; 

void IniList(orderlist * L, int n);
void Insert(orderlist * L, int n);
void ShowList(orderlist * L, int n);

int main()
{
	orderlist k; 
	IniList(&k, 10);
	Insert(&k, 5);
	ShowList(&k, 5);
	return 0;
}
void ShowList(orderlist * L, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d  ", L->data[i]);
} 

void IniList(orderlist *L, int n)
{
	L->data=(int *)malloc(10*sizeof(int));
	L->size=0;
	L->max=10;
}
 
void Insert(orderlist * L, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", &L->data[i]);
		L->size++; 
	}
}
