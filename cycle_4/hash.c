#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	char name[30];
	int rollno;
	struct node *link;
}*hash[100]={NULL},*new,*ptr;
int hashfunction(char name[])
{
	return name[strlen(name)/2]-97;
}
void insert(char name[],int rollno)
{
	int index;
	new=(struct node *)malloc(sizeof(struct node));
	strcpy(new->name,name);
	new->rollno=rollno;
	new->link=NULL;
	index=hashfunction(name);
	if(hash[index]==NULL)
		hash[index]=new;
	else
	{
		ptr=hash[index];
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=new;
	}
}
int find(char name[])
{
	int index;
	index=hashfunction(name);
	if(!strcmp(hash[index]->name,name))
		return hash[index]->rollno;
	else
	{
		ptr=hash[index]->link;
		while(ptr!=NULL)
		{
			if(!(strcmp(ptr->name,name)))
				return ptr->rollno;
			ptr=ptr->link;
		}
		return -1;
	}
}
void main()
{
	int ch,rollno;
	char name[30];
	while(1)
	{
		printf("\nMenu\n1.Insert\n2.Search\n3.Exit\nChoice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Name : ");
					scanf(" %[^\n]",name);
					printf("Roll No : ");
					scanf("%d",&rollno);
					insert(name,rollno);
					break;
			case 2: printf("Name : ");
					scanf(" %[^\n]",name);
					if(find(name)!=-1)
						printf("Roll No : %d",find(name));
					else
						printf("Not Found !\n");
					break;
			case 3: exit(0);
		}
	}
}