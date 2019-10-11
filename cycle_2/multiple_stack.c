/*  implementation of 2 stacks using single array  */

#include<stdio.h>
void main()
{
    int n,top1,top2,ch=1,a,i,arr[100];
    printf("Enter size of array\n");
    scanf("%d",&n);
    top1=-1;    //new element added in the beginning in stack1
    top2=n;     //new element added in the end in stack2
    while(ch!=0)
    {
        printf("Enter choice:\n");
        printf("1.Push element in stack 1\n");
        printf("2.Push element in stack 2\n");
        printf("3.Pop element from stack 1\n");
        printf("4.Pop element from stack 2\n");
        printf("5.Display stack 1\n");
        printf("6.Display stack 2\n");
        printf("7.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the element\n");
                scanf("%d",&a);
                if(top1!=(top2-1))
                    arr[++top1]=a;
                else
                    printf("Overflow\n");
                break;
            }
            case 2:
            {
                printf("Enter the element\n");
                scanf("%d",&a);
                if(top2!=(top1+1))
                    arr[--top2]=a;
                else
                    printf("Overflow\n");
                break;
            }
            case 3:
            {
                if(top1==-1)
                    printf("Stack1 is empty\n");
                else
                {
                    a=arr[top1--];
                    printf("%d\n",a);
                }
                break;
            }
            case 4:
            {
                if(top2==n)
                    printf("Stack2 is empty\n");
                else
                {
                    a=arr[top2++];
                    printf("%d\n",a);
                }
                break;
            }
            case 5:
            {
                if(top1==-1)
                    printf("Stack1 is empty\n");
                else
                {
                    printf("Stack1 is \n");
                    for(i=0;i<=top1;i++)
                        printf("%d ",arr[i]);
                    printf("\n");
                }
                break;
            }
            case 6:
            {
                if(top2==n)
                    printf("Stack2 is empty\n");
                else
                {
                    printf("Stack2 is \n");
                    for(i=(n-1);i>=top2;i--)
                        printf("%d ",arr[i]);
                    printf("\n");
                }
                break;
            }
            case 7:
                return;
        }
    }
}