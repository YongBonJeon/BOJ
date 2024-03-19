#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr;
    int *score;
    int n,i,j,check;

    scanf("%d",&n);
    arr=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
        arr[i]=(char*)malloc(sizeof(char)*80);

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    score=(int*)malloc(sizeof(int)*n);
    memset(score,0,sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        check=0;
        for(j=0;j<strlen(arr[i]);j++)
        {
            if(arr[i][j]=='O')
            {
                check++;
                score[i]+=check;
            }
            else if(arr[i][j]=='X')
                check=0;
            else
                return 0;
        }
    }
    for(i=0;i<n;i++)
        printf("%d\n",score[i]);

    return 0;
}