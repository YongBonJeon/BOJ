#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n,i,j,m,k;
    char arr[20];
    char *tok;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        memset(arr,0,sizeof(char)*20);
        scanf(" %[^\n]",arr);
        tok=strtok(arr," ");
        m=atoi(tok);
        tok=strtok(NULL," ");

        for(j=0;j<strlen(tok);j++)
        {
            for(k=0;k<m;k++)
                printf("%c",tok[j]);
        }
        printf("\n");
    }
    return 0;
}