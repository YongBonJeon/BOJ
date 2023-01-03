#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* '-' 기호가 오면 괄호로 다 묶어라 */

int main(){
    char exp[50];
    char op[50], op_length= 0;
    int num[50], num_length = 0;
    int ans = 0, flag = 0;

    scanf("%s",exp);

    int st = 0, length = strlen(exp);
    int tempsum = 0;

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

    /* '-' 기호를 만났을 때부터 flag를 이용해서 괄호처럼 사용 */
    for(int i = 0 ; i < op_length ; i++)
    {
        if(op[i] == '-' && flag == 0)
        {
            flag = 1;
            tempsum += num[i+1];
        }
        else if(op[i] == '+' && flag == 1)
        {
            tempsum += num[i+1];
        }
        else if(op[i] == '+' && flag == 0)
        {
            ans += num[i+1];
        }
        else if(op[i] == '-' && flag == 1)
        {
            ans -= tempsum;
            ans -= num[i+1];
            tempsum = 0;
        }
    }
    printf("%d\n",ans - tempsum);
}