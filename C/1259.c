#include <stdio.h>
#include <string.h>

int main()
{
    int i,len;
    int check=0;
    char arr[10];

    scanf("%s",arr);
    while(1)
    {
        if(arr[0]=='0')
            break;
        check=0;
        //scanf("%s",arr);
        len=strlen(arr);
        for(i=0;i<(len/2);i++)
        {
            if(arr[i]==arr[len-(i+1)])
                check++;
        }
        if(check==(len/2))
            printf("yes\n");
        else
            printf("no\n");
        memset(arr,0,5);
        scanf("%s",arr);
    }
    return 0;
}