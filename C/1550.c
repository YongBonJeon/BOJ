#include <stdio.h>

#define MAX 

int main()
{
    int hex;
    
    scanf("%x",&hex);
    if(hex>=16*16*16*16*16*16)
        return 0;
    printf("%d\n",hex);
    
    return 0;
}