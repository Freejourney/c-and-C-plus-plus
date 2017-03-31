#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct infor{
	char * name;
	int age;
	struct infor * next;
};

int main(void)
{
	struct infor * head = NULL;
	struct infor * prev, * current;
	char temp[40];
	
	printf("Enter first person's name:\n");
	while(gets(temp)!=NULL&&temp[0]!='\0')
	{
		
		current = (struct infor *)malloc(sizeof(struct infor));
		current->name = (char *)malloc(strlen(temp)+1); 
		
		if(head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}
		
		current->next = NULL;
		
		strcpy(current->name, temp);
		
		printf("Please enter the age:\n");
		scanf("%d", &current->age);
		while(getchar()!='\n')
			continue;
			
		prev = current;
		printf("Enter the next person's name:\n");
	}
	
	if(head == NULL)
		printf("No record!\n");
	else
		printf("Here is the students' information:\n");
		
	current = head;
		
	while(current != NULL)
	{
		printf("%s\t%d\n", current->name, current->age);
		current=current->next;
	}
	
	current = head;
	
	while(current != NULL)
	{
		free(current);
		current=current->next; 
	}
	
	return 0;
}
