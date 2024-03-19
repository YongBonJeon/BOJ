#include <stdio.h>

int main()
{
    int arr[8];
    int i;
    int check_as=0,check_ds=0;

    for(i=0;i<8;i++)
    {
        scanf(" %d",&arr[i]);
        if(arr[i]==i+1)
            check_as++;
        else if(arr[i]==8-i)
            check_ds++;
    }
    if(check_as==8)
        printf("ascending\n");
    else if(check_ds==8)
        printf("descending\n");
    else
        printf("mixed\n");

    return 0;
}