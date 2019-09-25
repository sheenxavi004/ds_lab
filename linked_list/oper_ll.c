// Linked List Operations
#include<stdlib.h>
#include<stdio.h>
struct node{
	int x;
	struct node *link;
}*header=NULL,*nes,*ptr,*pre,*nxt;
void main()
{
	int n,ch,r;
	char choice='y';
	while(choice=='y')
	{
		printf("MENU\n1.INSERT_REAR\n2.INSERT_FRONT\n3.INSERT_LEFT\n4.INSERT_RIGHT\n5.REMOVE_FRONT\n6.REMOVE_REAR\n7.REMOVE_X\n8.REMOVE_X_LEFT\n9.REMOVE_X_RIGHT\n10.REPLACE\n11.DISPLAY\n12.END\nENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :nes=(struct node*)malloc(sizeof(struct node)); //Insert at Back side of the previous element
				printf("Input : ");
				scanf("%d",&nes->x);
				nes->link=NULL;
				if(header==NULL)
				 	header=nes;
				else
				{
					ptr=header;
					while(ptr->link!=NULL)
						ptr=ptr->link;
					ptr->link=nes;
				}	
				break;
			case 2 :nes=(struct node*)malloc(sizeof(struct node)); //Insert at the front of the previous element
                                printf("Input : ");
                                scanf("%d",&nes->x);
				nes->link=header;
				header=nes;
				break;
			case 3 :if(header==NULL)                                //Insert at the left of a given element
					printf("No elements\n");
				else
				{
					nes=(struct node*)malloc(sizeof(struct node)); 
                                	printf("Input : ");
                              	        scanf("%d",&nes->x);
					printf("Before : ");
					scanf("%d",&n);
                                	nes->link=NULL;
   	                                ptr=header;
					if(ptr->x==n)
					{
						header=nes;
						nes->link=ptr;
					}
					else
					{
   		                            	while(ptr->link!=NULL&&ptr->x!=n)
						{
							pre=ptr;
                                                	ptr=ptr->link;
						}
                                        	if(ptr->x==n)
						{
							pre->link=nes;
							nes->link=ptr;
						}	
                                	}
				}       
                                break;
			case 4 :if(header==NULL)                           // Insert at the right of the given element
                                        printf("No elements\n");
                                else
                                {
                                        nes=(struct node*)malloc(sizeof(struct node)); 
                                        printf("Input : ");
                                        scanf("%d",&nes->x);
                                        printf("After : ");
                                        scanf("%d",&n);
                                        nes->link=NULL;
                                        ptr=header;
                                        while(ptr->link!=NULL&&ptr->x!=n)
                                                ptr=ptr->link;
                                        if(ptr->x==n)
                                        {
                                                nes->link=ptr->link;
                                                ptr->link=nes;
                                        }
                                }       
                                break;

			case 5 :if(header==NULL)                       // Removing element from the front
					printf("Empty LL");
				else
				{
					ptr=header;
					header=header->link;
					free(ptr);
				}
				break;
			case 6 :pre=ptr=header;				// Removing element from behind
				if(header==NULL)
					printf("Empty LL");
				else
				{
					while(ptr->link!=NULL)
					{
						pre=ptr;
						ptr=ptr->link;
					}
					pre->link=NULL;
					free(ptr);
				}
				break;
			case 7 :if(header==NULL)                     // Removing a specific element
					printf("Empty LL");
				else
				{
					printf("Delete : ");
					scanf("%d",&n);
					ptr=header;
					if(ptr->x==n)
					{
						header=ptr->link;
						free(ptr);
					}
					else
					{
						while(ptr->link!=NULL&&ptr->x!=n)
						{
							pre=ptr;
							ptr=ptr->link;
						}
						if(ptr->x==n)
						{
							pre->link=ptr->link;
							free(ptr);
						}
					}
				}
				break;
			case 8 :if(header==NULL)			// Removing a particular element before the given element
                                        printf("NULL");
                                else
                                {
                                        printf("Delete Before : ");
                                        scanf("%d",&n);
                                        ptr=header;
					nxt=ptr->link;
					if(nxt->x==n)
					{
						header=nxt;
						free(ptr);
					}
					else
					{	
						pre=header;
						ptr=pre->link;
						nxt=nxt->link;
                                        	while(nxt->link!=NULL&&nxt->x!=n)
						{
							pre=nxt;
                                                	ptr=ptr->link;
							nxt=ptr->link;
						}
                                     	        if(nxt->x==n)
                                        	{
                                                	pre->link=nxt;
                                                	free(ptr);
                                        	}
                                	}
				}
                                	break;
			case 9 :if(header==NULL)			// Removing a particular element after the given element
					printf("NULL");
				else
				{
					printf("Delete After : ");
					scanf("%d",&n);
					ptr=header;
					while(ptr->link!=NULL&&ptr->x!=n)
						ptr=ptr->link;
					if(ptr->x==n)
					{
						nxt=ptr->link;
						ptr->link=nxt->link;
						free(nxt);
					}
				}
				break;
			case 10:if(header==NULL)                     // Replacing one element with another
                                        printf("Empty LL");
                                else
                                {	
                                        printf("Element To Replaced : ");
					scanf("%d",&n);
					printf("Replacement : ");
					scanf("%d",&r);
                                        ptr=header;
                                        while(ptr->link!=NULL&&ptr->x!=n)
                                        {
                                                pre=ptr;
                                                ptr=ptr->link;
                                        }
                                        if(ptr->x==n)
                                  		ptr->x=r;
                                }
                                break;
			case 11:if(header==NULL)                        // Displaying Element
                                        printf("Empty ");
                                ptr=header;
                                while(ptr!=NULL)
                                {
                                        printf("%d ",ptr->x);
                                        ptr=ptr->link;
                                }
				printf("\n");
                                break;
			case 12: exit(0);
		}

	}


}
