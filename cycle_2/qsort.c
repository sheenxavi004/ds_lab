#include<stdio.h>
void qsort(int A[],int l,int r)
{
        int temp,ul,ll;
        if(r-l<=1)
                return ;
        ll=l+1;
        for(ul=l+1;ul<r;ul++)
                if(A[ul]<A[l])
                {
                        temp=A[ul];
                        A[ul]=A[ll];
                        A[ll]=temp;
                        ll++;
                }
        temp=A[ll-1];
        A[ll-1]=A[l];
        A[l]=temp;
        qsort(A,l,ll-1);
        qsort(A,ll,ul);
}
void main()
{
        int A[100],n,i;
        printf("Enter the no of elements : ");
        scanf("%d",&n);
        printf("Enter the elements \n");
        for(i=0;i<n;i++)
                scanf("%d",&A[i]);
        qsort(A,0,n);
        printf("The sorted array : ");
        for(i=0;i<n;i++)
                printf(" %d",A[i]);
        printf("\n");
}

