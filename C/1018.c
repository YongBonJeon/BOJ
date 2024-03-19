#include <stdio.h>
#include <stdlib.h>

int makeChessW(char **arr,int i,int j)
{
    int k,l;
    int fk=0;

    for(k=0;k<8;k++)
    {
        for(l=(k%2);l<8+(k%2);l+=2)
        {
            if(arr[i+k][j+l]!='W')
                fk++;
        }
    }
    for(k=0;k<8;k+=1)
    {
        for(l=(k+1)%2;l<8;l+=2)
        {
            if(arr[i+k][j+l]!='B')
                fk++;
        }
    }
    //printf("W%d\n",fk);
    return fk;
}
int makeChessB(char **arr,int i,int j)
{
    int k,l;
    int fk=0;

    for(k=0;k<8;k++)
    {
        for(l=(k%2);l<8+(k%2);l+=2)
        {
            if(arr[i+k][j+l]!='B')
                fk++;
        }
    }
    for(k=0;k<8;k++)
    {
        for(l=(k+1)%2;l<8;l+=2)
        {
            if(arr[i+k][j+l]!='W')
                fk++;
        }
    }
    //printf("B%d\n",fk);
    return fk;
}

int main()
{
    int m,n,i,j; //m=세로 n=가로
    char **arr;
    int min=64;

    scanf("%d %d",&m,&n);

    arr=(char**)malloc(sizeof(char*)*m);
    for(i=0;i<m;i++)
        arr[i]=(char*)malloc(sizeof(char)*n);

    for(i=0;i<m;i++)
        scanf(" %s",arr[i]);

    for(i=0;i<m-7;i++)
    {
        for(j=0;j<n-7;j++)
        {
           // printf("m%dn%d\n",m,n);
            //printf("i%dj%d\n",i,j);
            if(makeChessB(arr,i,j)<min)
                min=makeChessB(arr,i,j);
            if(makeChessW(arr,i,j)<min)
                min=makeChessW(arr,i,j);
        }
    }
    printf("%d\n",min);
    return 0;
}