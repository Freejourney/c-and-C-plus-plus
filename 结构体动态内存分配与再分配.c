#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int id;
	char name[40];
}infor;

int main()
{
	infor * peoples;
	peoples=(infor *)malloc(2*sizeof(infor));//用malloc来实现动态数组 
	printf("infor's size:'%d\nint's size:%d\nchar *'s size:%d\n", sizeof(peoples), sizeof(int),sizeof(char *));
	if(peoples==NULL)
		printf("Memory allocation fail\n");
	else
		printf("Succeed!\n");
	int i;
	for(i=0;i<2;i++)
	{
		printf("Now enter the id:\n");
		scanf("%d", &peoples[i].id);
		getchar();
		printf("Now enter the name:\n");
	 	gets(peoples[i].name);
	 	printf("enter succeed!\n");
	 }
	printf("Here are original list:\n");
	for(i=0;i<2;i++)
		printf("%d:%s\n", peoples[i].id, peoples[i].name);
	printf("This is the original address:\n");
	printf("%p\n",peoples);
	int j=1;
	printf("Do you want to enter another person?(Enter [Y] to enter, Enter [#] to quit)\n");
	while(getchar()!='#')
	{
		j++;
		peoples=(infor *)realloc(peoples,j*sizeof(infor));//realloc的使用方式 
		if(peoples==NULL)
			printf("Memory reallocation fail\n");
		printf("Here is the address after realloc\n");
		printf("This is the size of peoples:%d\n", sizeof(peoples));
		printf("%p\n",peoples);
		printf("Now enter the id:\n");
		scanf("%d", &peoples[j].id);
		getchar();
		printf("Now enter the name:\n");
		gets(peoples[j].name);	
		printf("Do you want to enter another person?(Enter [Y] to enter, Enter [#] to quit)\n");
	}
	printf("Here is final list：\n");
	for(i=0;i<=j;i++)
	{
		printf("%d:%s\n", peoples[i].id, peoples[i].name);
	}
	return 0;
} 
