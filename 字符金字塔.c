#include <stdio.h>

int main()
{
	int i, j, k;
	char ch;
	ch=getchar();
	
	k=ch-'A';
	
	for(i=0;i<=k;i++)
	{
		for(j=0;j<k-i;j++)
			putchar(' ');
		for(j=0;j<=i;j++)
			printf("%c", 'A'+j);
		for(j=i-1;j>=0;j--)
			printf("%c", 'A'+j);
		printf("\n");
	}
	return 0;
}
