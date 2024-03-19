#include <stdio.h>

int main()
{
    int chess[6]={1,1,2,2,2,8};
    int input[6];
    int i;

    for(i=0;i<6;i++){
        scanf("%d",&input[i]);
        if(input[i]<0||input[i]>10)
            return 0;
    }
    
    for(i=0;i<6;i++)
        printf("%d ",chess[i]-input[i]);
    
    printf("\n");
    return 0;
}