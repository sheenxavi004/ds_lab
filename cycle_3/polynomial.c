#include<stdio.h>
#include<stdlib.h>
struct node{
        int exp;
        int coef;
        struct node *link;
}*now,*ptr,*poly1=NULL,*poly2=NULL,*result,*ptr1,*ptr2,*pre,*result1,*ptr3;
void repr(struct node **poly,int n)
{
        while(n--)
        {
                printf("TERM-------------------------\n");
                now=(struct node*)malloc(sizeof(struct node));
                now->link=NULL;
                printf("EXP :");
                scanf("%d",&now->exp);
                printf("CO : ");
                scanf("%d",&now->coef);
                if(*poly==NULL)
                        *poly=now;
                else
                {
                        ptr=*poly;
                        while(ptr->exp>now->exp)
                        {
                                pre=ptr;
                                ptr=ptr->link;
                                if(ptr==NULL)
					break;
                        }
                        if(ptr==*poly)
                        {
                                now->link=*poly;
                                *poly=now;
                        }
                        else
                        {
                                pre->link=now;
                                now->link=ptr;
                        }
                }
        }
}
void disp(struct node **poly)
{
        ptr=*poly;
        while(ptr!=NULL)
        {
                if(ptr->link!=NULL)
                        printf("%dX^%d + ",ptr->coef,ptr->exp);
                else
                        printf("%dX^%d",ptr->coef,ptr->exp);
                ptr=ptr->link;
        }
        printf("\n");
}
void add(struct node **p1,struct node **p2,struct node **res)
{
        *res=NULL;
        ptr1=*p1;
        ptr2=*p2;
        while(ptr1!=NULL&&ptr2!=NULL)
        {
                now=(struct node *)malloc(sizeof(struct node));
                now->link=NULL;
                if((ptr1->exp) > (ptr2->exp))
                {
                        now->exp=ptr1->exp;
                        now->coef=ptr1->coef;
                        if(*res==NULL)
                                *res=now;
                        else
                        {
                                ptr=*res;
                                while(ptr->link!=NULL)
                                        ptr=ptr->link;
                                ptr->link=now;
                        }
                        ptr1=ptr1->link;
                }
                else if((ptr1->exp) < (ptr2->exp))
                {
                        now->exp=ptr2->exp;
                        now->coef=ptr2->coef;
                        if(*res==NULL)
                                *res=now;
                        else
                        {
                                ptr=*res;
                                while(ptr->link!=NULL)
                                        ptr=ptr->link;
                                ptr->link=now;
                        }
                        ptr2=ptr2->link;
                }
                else if(ptr1->exp==ptr2->exp)
                {
                        now->exp=ptr1->exp;
                        now->coef=(ptr1->coef)+ptr2->coef;
                        if(*res==NULL)
                                *res=now;
                        else
                        {
                                ptr=*res;
                                while(ptr->link!=NULL)
                                        ptr=ptr->link;
                                ptr->link=now;
                        }
                        ptr1=ptr1->link;
                        ptr2=ptr2->link;
                }
        }
        while(ptr1!=NULL)
	{
                now=(struct node *)malloc(sizeof(struct node));
                now->exp=ptr1->exp;
                now->coef=ptr1->coef;
                now->link=NULL;
                if(*res==NULL)
                        *res=now;
                else
                {
                        ptr=*res;
                        while(ptr->link!=NULL)
                                ptr=ptr->link;
                        ptr->link=now;
                }
                ptr1=ptr1->link;
        }
        while(ptr2!=NULL)
        {
                now=(struct node *)malloc(sizeof(struct node));
                now->exp=ptr2->exp;
                now->coef=ptr2->coef;
                now->link=NULL;
                if(*res==NULL)
                        *res=now;
                else
                {
                        ptr=*res;
                        while(ptr->link!=NULL)
                                ptr=ptr->link;
                        ptr->link=now;
                }
                ptr2=ptr2->link;
        }
}
void mult(struct node **p1,struct node **p2,struct node **res)
{
        *res=NULL;
        ptr1=*p1;
        ptr2=*p2;
        if(ptr1==NULL || ptr2==NULL)
                ;
        else
        {
                while(ptr1!=NULL)
                {
			ptr2=*p2;
                        while(ptr2!=NULL)
                        {
                                now=(struct node*)malloc(sizeof(struct node));
                                now->exp=ptr1->exp+ptr2->exp;
                                now->coef=ptr1->coef*ptr2->coef;
				now->link=NULL;
                                if(*res==NULL)
                                        *res=now;
                                else
                                {
                                        ptr=*res;
                                        while(ptr->exp>now->exp)
					{
						pre=ptr;
						ptr=ptr->link;
						if(ptr==NULL)
							break;
                                        }
					if(ptr!=NULL)
					{
						if(ptr==*res&&ptr->exp!=now->exp)
						{
							now->link=*res;
							*res=now;
						}
						else if(ptr->exp==now->exp)
						{
							ptr->coef+=now->coef;
							free(now);
						}
						else
						{
							pre->link=now;
							now->link=ptr;
						}
					}
					else
						pre->link=now;
				}
                                ptr2=ptr2->link;
                        }
			ptr1=ptr1->link;
		}
	}
}
void main()
{
        int i,ch;
        while(1)
        {
		poly1=poly2=NULL;
                printf("\nMENU\n1.ADDITION\n2.MULTIPLICATION\n3.EXIT\nCHOICE : ");
                scanf("%d",&ch);
                if(ch==3)
                        exit(0);
                printf("NO OF TERMS IN POLY1 : ");
                scanf("%d",&i);
                repr(&poly1,i);
                disp(&poly1);
                printf("NO OF TERMS IN POLY2 : ");
                scanf("%d",&i);
                repr(&poly2,i);
                disp(&poly2);
                if(ch==1)
                {
                        result=NULL;
                        add(&poly1,&poly2,&result);
			if(result==NULL)
				printf("Result : 0\n");
			else
			{
                        	printf("Result  : ");
                        	disp(&result);
			}
                }
                if(ch==2)
                {
			result=NULL;
                        mult(&poly1,&poly2,&result);
			if(result==NULL)
				printf("Result : 0\n");
			else
			{
				printf("Result : ");
                        	disp(&result);
			}
                }
        }
}
