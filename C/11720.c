#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,sum=0;
    char arr[101];
    
    memset(arr,0,sizeof(char)*101);
    scanf("%d",&n);
    if(n<1||n>100)
        return 0;
    scanf("%s",arr);

    for(i=0;i<n;i++)
    {
        sum+=arr[i]-48;
    }
    printf("%d\n",sum);

    return 0;
}