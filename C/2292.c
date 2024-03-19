#include <stdio.h>

int main()
{
    int i;
    int target;

    scanf("%d",&target);

    for(i=0;i<100000;i++)
    {
        if(target<(i*(i+1)*3)+2)
            break;
    }
    printf("%d\n",i+1);

    return 0;

}