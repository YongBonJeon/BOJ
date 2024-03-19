#include <stdio.h>

int main()
{
    int move_second[4];
    int i,sum=0;

    for(i=0;i<4;i++)
    {
        scanf("%d",&move_second[i]);
        if(move_second[i]<=0)
            return 0;
        sum+=move_second[i];
    }
    if(sum<60||sum>3599)
        return 0;

    printf("%d\n%d\n",sum/60,sum%60);

    return 0;
}