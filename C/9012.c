#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j;
    int vps=0;
    char str[51];

    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        scanf("%s",str);
        for(j = 0 ; j < strlen(str) ; j++){
            if(str[j] == '('){
                vps++;
            }
            else if(str[j] == ')'){
                vps--;
            }
            if(vps<0){
                break;
            }
        }
        if(vps == 0){
            printf("YES\n");
        }
        else 
            printf("NO\n");
        vps=0;
    }
    return 0;
}