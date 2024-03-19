#include <stdio.h>
#include <string.h>
char fsum(char d1,char d2)
{
    //printf("chh%c\n",(d1+(d2-48))); //'8'=56 //'14'?
    if(d1+(d2-48)>'9')
        return d1+(d2-48)-10;
    return (d1+d2-48);
}
//매개변수 2,6 =>68 
void newInput(char *d1,char *d2)
{
    char temp=*d2;
    *d2=fsum(*d1,*d2);
    *d1=temp;
}
int main()
{
    char input[3]={'0','0'};
    char finput[3];
    int check=1;
    int cinput;

    scanf("%d",&cinput);
    if(cinput<0||cinput>100)
        return 0;
    input[0]=cinput/10+48;
    input[1]=(cinput%10)+48;

    strcpy(finput,input);

    newInput(&input[0],&input[1]);
    while(strcmp(finput,input)!=0)
    {
        newInput(&input[0],&input[1]);
        check++;
    }
    printf("%d\n",check);
    return 0;
}