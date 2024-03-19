#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char str[51];
    int len;
}Str;

int compare(const void *a, const void *b)
{
    Str s1=*(Str*)a;
    Str s2=*(Str*)b;
    if(s1.len<s2.len)
        return -1;
    else if(s1.len>s2.len)
        return 1;
    return strcmp(s1.str,s2.str);
}

int main()
{
    int n,i;
    Str *str;

    scanf("%d",&n);
    str=(Str*)malloc(sizeof(Str)*n);
    for(i=0;i<n;i++)
    {
        scanf(" %s",str[i].str);
        str[i].len=strlen(str[i].str);
    }
    qsort(str,n,sizeof(Str),compare);
    printf("%s\n",str[0].str);
    for(i=1;i<n;i++)
        if(strcmp(str[i-1].str,str[i].str))
            printf("%s\n",str[i].str);

    return 0;
}