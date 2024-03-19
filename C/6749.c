#include <stdio.h>

int main()
{
    int y,m,o;

    scanf("%d",&y);
    scanf("%d",&m);

    if(y<0||y>50)
        return 0;
    if(m<y||m>50)
        return 0;

    printf("%d\n",2*m-y);

    return 0;
}