#include <stdio.h>

int main()
{
    int arr[9];
    int i,maxIdx=0;

    for(i=0;i<9;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<1||arr[i]>99)
            return 0;
        if(arr[i]>arr[maxIdx])
            maxIdx=i;
    }
    printf("%d\n%d\n",arr[maxIdx],maxIdx+1);

    return 0;
}