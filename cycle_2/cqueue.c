/*     Circular Queue Implementation using Arrays     */
#include<stdio.h>
int q[10],front=-1,rear=-1,x;
void insert()
{
	if(front==rear+1||rear==9&&front==0)
		printf("Overflow\n");
	else
	{
		printf("\nINPUT : ");
		scanf("%d",&x);
		if(front==-1)
			front++;
		rear=(rear+1)%10;
		q[rear]=x;
	}
}
void del()
{
	if(front==-1)
		printf("Underflow\n");
	else
	{
		printf("Dequeued : %d\n",q[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%10;
	}
}
void display()
{
	int i;
	if(front==-1)
		printf("Underflow\n");
	else
	{
		if(rear>=front)
			for(i=front;i<=rear;i++)
				printf("%d ",q[i]);
		else
		{
			for(i=front;i<10;i++)
				printf("%d ",q[i]);
			for(i=0;i<=rear;i++)
				printf("%d ",q[i]);
		}
	}
}
void main()
{
	int ch;
	char choice='Y';
	while(choice=='Y'||choice=='y')
	{
		printf("MENU\n1.INSERT\n2.DELETE\n3.DISPLAY\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
				break;
			case 2: del();
				break;
			case 3: display();
				break;
			default : printf("Wrong Input\n");
		}
		printf("Do you want to continue(Y/N)?");
		scanf(" %c",&choice);
	}
}
