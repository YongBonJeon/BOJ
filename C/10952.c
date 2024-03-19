#include <stdio.h>

int main()
{
    int arr[2];

    while(1)
    {
        scanf("%d %d",&arr[0],&arr[1]);
        if(arr[0]==0&&arr[1]==0)
            return 0;

        printf("%d\n",arr[0]+arr[1]);
    }
    return 0;
}