#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i,j,t;
    int *arr;

    scanf("%d",&n);
    if(n<1||n>10000000)
        return 0;
    arr=(int*)malloc(sizeof(int)*10001);
    memset(arr,0,sizeof(int)*10001);

    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t<1||t>10000)
            return 0;
        arr[t]++;
    }
    for(i=1;i<10001;i++)
    {
        if(arr[i]>0)
        {
            for(j=0;j<arr[i];j++)
                printf("%d\n",i);
        }
    }

    free(arr);
    return 0;
}