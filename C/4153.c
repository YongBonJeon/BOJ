#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int arr[3];
    
    while(1)
    {
        scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
        qsort(arr,3,sizeof(int),compare);
        if(arr[0]==0&&arr[1]==0&&arr[2]==0)
            return 0;
        if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}