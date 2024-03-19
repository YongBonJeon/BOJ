#include <stdio.h>
#include <stdlib.h>
void printTomato(int **arr,int m,int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
void growTomato(int **arr,int m,int n,int i,int j)
{
    if(i==0)
    {
        if(j==0)
        {
            if(arr[i+1][j]==0)
                arr[i+1][j]=1;
            if(arr[i][j+1]==0)
                arr[i][j+1]=1;
        }
        else if(j==m-1)
        {
            if(arr[i+1][j]==0)
                arr[i+1][j]=1;
            if(arr[i][j-1]==0)
                arr[i][j-1]=1;
        }
        else
        {
            if(arr[i][j+1]==0)
                arr[i][j+1]=1;
            if(arr[i][j-1]==0)
                arr[i][j-1]=1;
            if(arr[i+1][j]==0)
                arr[i+1][j]=1;
        }
    }
    else if(j==0)
    {
        if(i==n-1)
        {
            if(arr[i][j+1]==0)
                arr[i][j+1]=1;
            if(arr[i-1][j]==0)
                arr[i-1][j]=1;
        }
        else
        {
            if(arr[i+1][j]==0)
                arr[i+1][j]=1;
            if(arr[i-1][j]==0)
                arr[i-1][j]=1;
            if(arr[i][j+1]==0)
                arr[i][j+1]=1;
        }
    }
    else if(i==n-1)
    {
        if(j==m-1)
        {
            //printf("cc\n");
            if(arr[i-1][j]==0)
                arr[i-1][j]=1;
            if(arr[i][j-1]==0)
                arr[i][j-1]=1;
        }
        else
        {
            if(arr[i-1][j]==0)
                arr[i-1][j]=1;
            if(arr[i][j-1]==0)
                arr[i][j-1]=1;
            if(arr[i][j+1]==0)
                arr[i][j+1]=1;
        }
    }
    else if(j==m-1)
    {
        if(arr[i-1][j]==0)
            arr[i-1][j]=1;
        if(arr[i+1][j]==0)
            arr[i+1][j]=1;
        if(arr[i][j-1]==0)
            arr[i][j-1]=1;
    }
    else
    {
        if(arr[i+1][j]==0)
            arr[i+1][j]=1;
        if(arr[i][j+1]==0)
            arr[i][j+1]=1;
        if(arr[i-1][j]==0)
            arr[i-1][j]=1;
        if(arr[i][j-1]==0)
            arr[i][j-1]=1;
    }
    return ;
}
int AllTomatoGrow(int **arr,int m,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==0)
                return 0;
        }
    }
    return 1;
}
int tomatoTotomato(int **arr,int m, int n)
{
    int i,j;
    int **check;
    int idx=0;
    check=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        check[i]=(int*)malloc(sizeof(int)*m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            check[i][j]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==1)
                check[i][j]=1;
        }
    }

    while(AllTomatoGrow(arr,m,n)==0){
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            { 
                if(check[i][j]==1)
                    growTomato(arr,m,n,i,j);
            }
        }  
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==1)
                check[i][j]++;
        
        }  
    }
    idx++;
    if(idx>(m*n))
        return -1;
    }
    return idx;
}

int main()
{
    int m,n;
    int i,j;
    int **arr;
    int num;

    scanf("%d %d ",&m,&n);
    arr=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    }
    num=tomatoTotomato(arr,m,n);
    printf("%d\n",num);

    return 0;
}