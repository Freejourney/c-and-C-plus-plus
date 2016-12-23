#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *name;
	char *address;
	int age;
	int id;
}ifmts;

int main()
{
	ifmts *peoples;
	char temp[100];
	int l=2;
	int n;
	int m;
	
	peoples=(ifmts *)malloc(sizeof(ifmts));
	if(peoples==NULL)
	{
		printf("memory allocation failure!\n");
		exit(1);
	}
	printf("memeory allocation succeed!\n");
	printf("enter the name\n");
	gets(temp);
	peoples[0].name=(char *)malloc(strlen(temp)+1);
	strcpy(peoples[0].name,temp);
	printf("enter the address\n");
	gets(temp);
	peoples[0].address=(char *)malloc(strlen(temp)+1); 
	strcpy(peoples[0].address,temp);
	printf("enter the age\n");
	scanf("%d", &peoples[0].age);
	getchar();
	printf("enter the id\n");
	scanf("%d", &peoples[0].id);
	getchar();
	
	printf("Enter another person' information? ([Y] to enter and [Q] to quit)\n");
	while(getchar()!='q')
	{
		peoples=(ifmts *)realloc(peoples, (l++)*sizeof(ifmts));
		if(peoples==NULL)
		{
			printf("memory allocation failure!\n");
			exit(1);
		}
		getchar();
		printf("enter the name\n");
		gets(temp);
		peoples[l-2].name=(char *)malloc(strlen(temp)+1);//为什么要加1？strlen不测量最后的空字符？ 
		strcpy(peoples[l-2].name,temp);
		printf("enter the address\n");
		gets(temp);
		peoples[l-2].address=(char *)malloc(strlen(temp)+1);
		strcpy(peoples[l-2].address,temp);
		printf("enter the age\n");
		scanf("%d", &peoples[l-2].age);
		getchar();
		printf("enter the id\n");
		scanf("%d", &peoples[l-2].id);
		getchar(); 
		printf("%d information you have entered\n",l-1);
		printf("Enter another person' information? ([Y] to enter and [Q] to quit)\n");
	}
	for(n=0;n<l-1;n++)
		printf("%d\n%s\n%d\n%s\n",peoples[n].id
								 ,peoples[n].name
								 ,peoples[n].age
								 ,peoples[n].address);
	
	putchar('\n');
	putchar('\n');
	
	for(n=0;n<l-2;n++)
		for(m=0;m<l-2-n;m++)
		{
			if(peoples[m].id>peoples[m+1].id)
			{
				ifmts tempp;
				tempp=peoples[m];
				peoples[m]=peoples[m+1];
				peoples[m+1]=tempp;
			}
		}
			
	for(n=0;n<l-1;n++)
		printf("%d\n%s\n%d\n%s\n",peoples[n].id
								 ,peoples[n].name
								 ,peoples[n].age
								 ,peoples[n].address);
	
	putchar('\n');
	putchar('\n');
	
	printf("please enter id to find the relevent information.\n");
	int fid;
	scanf("%d", &fid);
	getchar();
	for(n=0;n<=l-2;n++)
		if(peoples[n].id==fid)
			printf("%d\n%s\n%d\n%s\n", peoples[n].id
									 , peoples[n].name
									 , peoples[n].age
									 , peoples[n].address);		
	
	printf("Here are information arrange according to ages:\n");
	
	for(m=16;m<=20;m++)
		for(n=0;n<l-1;n++)
			if(peoples[n].age==m)
				printf("%d\n%d\n%s\n%s\n", peoples[n].age
				 						 , peoples[n].id
										 , peoples[n].name
										 , peoples[n].address); 
										 
	printf("You can also find it according to his(her) name:\n");
	printf("please enter the name\n");
	gets(temp);
	for(n=0;n<l-1;n++)
		if(strcmp(temp,peoples[n].name)==0)
			printf("%s\n%d\n%d\n%s\n", peoples[n].name
									 , peoples[n].id
									 , peoples[n].age
									 , peoples[n].address);
	for(n=0;n<l-1;n++)//内存的释放要先从结构体里面的指针开始释放，之后才能释放结构体指针 
	{
		free((peoples+n)->name);
		free((peoples+n)->address);
	}
	free(peoples);
	return 0;
}
