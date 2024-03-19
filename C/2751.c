#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n; //개수
    int arr[1000001];
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);

    return 0;
}