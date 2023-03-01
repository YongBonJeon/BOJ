#include <bits/stdc++.h>
using namespace std;

int N;
char input[20];
int max0 = INT_MIN;

int calculate(int a, int b, char oper)
{
    switch(oper){
        case '-': return a-b;
        case '+': return a+b;
        case '*': return a*b;
        default : return 0;
    }
}

void recursion(int cur, int value)
{
    /* base case */
    if(cur >= N)
    {
        if(value > max0)
            max0 = value;
        return ;
    }

    char oper;
    if(cur == 0)
        oper = '+';
    else
        oper = input[cur-1];

    /* 묶는다 */
    if(cur < N - 2)
    {
        int temp = calculate(input[cur]-'0', input[cur+2]-'0', input[cur+1]);
        recursion(cur+4, calculate(value, temp, oper));
    }

    /* 그냥 계산한다 */
    recursion(cur+2, calculate(value, input[cur]-'0', oper));

}

int main()
{
    scanf("%d",&N);
    scanf("%s",input);

    recursion(0,0);
    printf("%d\n",max0);
}