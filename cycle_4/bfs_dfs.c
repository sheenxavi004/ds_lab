#include<stdio.h>
#include<stdlib.h>
int g[10][10]={0},visited[10],stack[10],queue[10],top=-1,front=-1,rear=-1,size=0;
void ginsert(int v1,int v2)
{
        g[v1][v2]=1;
}
void push(int x)
{
        if(top==9)
                printf("Overflow\n");
        else
                stack[++top]=x;
}
int pop()
{
        int item;
        if(top==-1)
                printf("Underflow\n");
        else
        {
                item=stack[top];
                top--;
                return item;
        }
}
void insert(int x)
{
        if(rear==9)
                printf("Overflow\n");
        else
        {
                if(front==-1)
                        front++;
                queue[++rear]=x;
        }
}
int del()
{
        int item;
        if(front==-1)
                printf("Underflow\n");
        else
        {
                item=queue[front];
                if(front==rear)
                        front=rear=-1;
                else
                        front++;
                return item;
        }
}
void bfs(int x)
{
        int i,j,item;
        size=0;
        insert(x);
        while(front!=-1)
        {
                item=del();
                if(size==0)
                        visited[size++]=item;
                else
                {
                        for(i=0;i<size;i++)
                                if(visited[i]==item)
                                        break;
                        if(i==size)
                                visited[size++]=item;
                }
                for(i=0;i<10;i++)
                {
                        if(g[item][i]==1)
                        {
                                for(j=0;j<size;j++)
                                        if(visited[j]==i)
                                                break;
                                if(j==size)
                                        insert(i);
                        }
                }
        }
        printf("BFS : ");
        for(i=0;i<size;i++)
                printf("%d ",visited[i]);
}
void dfs(int x)
{
        int i,j,item;
        push(x);
        while(top!=-1)
        {
                item=pop();
                if(size==0)
                        visited[size++]=item;
                else
                {
                        for(i=0;i<size;i++)
                                if(visited[i]==item)
                                        break;
                        if(i==size)
                                visited[size++]=item;
                }
                for(i=0;i<10;i++)
                {
                        if(g[item][i]==1)
                        {
                                for(j=0;j<size;j++)
                                        if(visited[j]==i)
                                                break;
                                if(j==size)
                                        push(i);
                        }
                }
        }
        printf("DFS : ");
        for(i=0;i<size;i++)
                printf("%d ",visited[i]);
}
void main()
{
        int x,ch,v1,v2;
        printf("MENU\n1.BFS\n2.DFS\n3.INSERT\n4.EXIT\n");
        while(1)
        {
                printf("CHOICE : ");
                scanf(" %d",&ch);
                switch(ch)
                {
                        case 1: printf("Staring Point : ");
                                scanf("%d",&x);
                                bfs(x);
                                break;
                        case 2: printf("Staring Point : ");
                                scanf("%d",&x);
                                dfs(x);
                                break;
                        case 3: printf("Vertices : ");
                                scanf("%d %d",&v1,&v2);
                                ginsert(v1,v2);
                                break;
                        case 4: exit(0);
                        default : break;
                }
        }
}
