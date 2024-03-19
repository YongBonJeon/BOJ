#include <stdio.h>

int main()
{
    int score[5];
    int i,sum=0;

    for(i=0;i<5;i++)
    {
        scanf("%d",&score[i]);
        sum+=score[i];
    }
    /*for(i=0;i<5;i++)
           if(score[i]<0||score[i]>10)
               return 0;*/

    printf("%d\n",sum);

    return 0;
}