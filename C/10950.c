#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr;
    int n,i;

    scanf("%d",&n);
    arr=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*2);

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        if(arr[i][0]<1||arr[i][0]>9)
            return 0;
        if(arr[i][1]<1||arr[i][1]>9)
            return 0;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i][0]+arr[i][1]);
    }
    return 0;
}