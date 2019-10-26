#include<stdio.h>
#include<stdlib.h>
struct node{
        int item;
        struct node *link;
}*header=NULL,*pre,*now,*ptr,*pre1;
int i;
void push(int x)
{
        now=(struct node*)malloc(sizeof(struct node));
        now->item=x;
        now->link=header;
        header=now;
}
void pop()
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                ptr=header;
                header=header->link;
                free(ptr);
        }
}
void disp()
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                ptr=header;
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->item);
                        ptr=ptr->link;
                }
                printf("\n");
        }
}
void main()
{
        int ch,x,p;
        while(1)
        {
                printf("MENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nCHOICE : ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("INPUT : ");
                                scanf("%d",&x);
                                push(x);
                                break;
                        case 2: pop();
                                break;
                        case 3: disp();
                                break;
			case 4: exit(0);
                        default:printf("Wrong Input\n");
                }
        }
}

