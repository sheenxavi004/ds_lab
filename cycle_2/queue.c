/*  Queue Implementation using an Array  */
#include<stdio.h>
int q[10],x,front=-1,rear=-1;
void enqueue()
{
	if(rear==9)
		printf("Overflow\n");
	else
	{
		printf("Input : ");
		scanf("%d",&x);
		if(front==-1)
			front=0;
		q[++rear]=x;
	}
}
void dequeue()
{
	if(front==-1||front>rear)
		printf("Underflow\n");
	else
		printf("Dequeued %d",q[front]);
		front++;
}
void display()
{
	int i;
	if(front==-1||front>rear)
		printf("Underflow\n");
	for(i=front;i<=rear;i++)
		printf("%d ",q[i]);
}
void main()
{		
	int ch;
	char choice='Y';
	while(choice=='y'||choice=='Y')
	{
		printf("MENU\n1.Insert\n2.Delete\n3.Display\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enqueue();
				break;	
			case 2: dequeue();
				break;
			case 3: display();
				break;
			default: printf("Wrong Input");
					
		}
		printf("Do you want to continue(Y/N) ");
		scanf(" %c",&choice);
	}
}
