#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
#define MIN -1000000

int main()
{
    int n,i;
    int *arr;
    int minIdx=0,maxIdx=0;

    scanf("%d",&n);

    if(n<1||n>MAX)
        return 0;
    arr=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<MIN||arr[i]>MAX)
            return 0;
        if(arr[i]>=arr[maxIdx])
            maxIdx=i;
        if(arr[i]<=arr[minIdx])
            minIdx=i;
    }
    printf("%d %d\n",arr[minIdx],arr[maxIdx]);

    free(arr);

    return 0;
}