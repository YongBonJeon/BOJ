#include <stdio.h>

#define MAX 1000000

int main()
{
    int i;
    int person;
    int area;
    int news[5];

    scanf("%d %d",&person,&area);
    scanf("%d %d %d %d %d",&news[0],&news[1],&news[2],&news[3],&news[4]);

    if(person<0||person>11)
        return 0;
    if(area<0||area>1000)
        return 0;
    for(i=0;i<5;i++)
    {
        if(news[i]>=MAX||news[i]<0)
            return 0;
    }

    for(i=0;i<5;i++)
        printf("%d ",news[i]-person*area);
    printf("\n");

    return 0;
    
}