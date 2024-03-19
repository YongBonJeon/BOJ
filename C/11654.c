#include <stdio.h>

int main()
{
    char n;

    scanf("%c",&n);
    if(n>='0'&&n<='9')
        printf("%d\n",n);
    else if(n>='a'&&n<='z')
        printf("%d\n",n);
    else if(n>='A'&&n<='Z')
        printf("%d\n",n);
    else
        return 0;
    return 0;
}