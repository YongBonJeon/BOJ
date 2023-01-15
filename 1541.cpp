#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char exp[50];
    char op[50];
    int num[50],  op_length= 0, num_length = 0;
    int ans = 0, flag = 0;

    scanf("%s",exp);

    int st = 0, length = strlen(exp);

    /* 파싱 */
    for(int i = 0 ; i < length ; i++)
    {
        if(exp[i] == '+' || exp[i] == '-')
        {
            op[op_length++] = exp[i];
            exp[i] = '\0';
            num[num_length++] = atoi(&exp[st]);
            st = i+1;
        }   
    }
    num[num_length++] = atoi(&exp[st]);
    
    /* 초기값은 그냥 더함 */
    ans = num[0];

    for(int i = 0 ; i < op_length ; i++)
    {
        if(!flag)
        {
            if(op[i] == '+')
                ans += num[i+1];
            else if(op[i] == '-'){
                flag = 1;
                ans -= num[i+1];
            }
        }
        else if(flag)
        {
            ans -= num[i+1];
        }
    }

    printf("%d\n",ans);
}