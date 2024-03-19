#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000001],*tok;
    int check=1;


    fgets(arr,1000001,stdin);

    if(arr[0]==' ')
        check--;
    if(arr[strlen(arr)-2]==' ')
        check--;
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]==' ')
            check++;
    }
    printf("%d\n",check);

}