#include <stdio.h>
/*
    메커니즘 1부터 계속 올라가면서 종말의 수 인지 확인
    종말의 수면 count올려주면서 n번째 종말의 수 체크
*/
int main()
{
    int n;

    int ans=0; //영화 제목
    int count=0; //몇번째 종말의 수인지
    int temp;
    scanf("%d",&n);
    while(count!=n)
    {
        ans++;
        temp=ans;

        while(temp!=0)
        {
            if(temp%1000==666)//종말의 수이면
            {
                count++;
                break;
            }
            else
                temp/=10;
        }
    }
    printf("%d\n",ans);
}