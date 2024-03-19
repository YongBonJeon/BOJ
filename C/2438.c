#include <stdio.h>

int main()
{
    int n;
    int i,j;
    scanf("%d",&n);

    if(n<1||n>100)
        return 0;

    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}