#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * n은 짝수가 아니고 5의 배수도 아님
 * 마지막 자리수가 1,3,7,9 일 수 밖에 없다
 */

int main(){
    

    long long n;

    while(scanf(" %lld",&n) != EOF){
        long long onenum=1;
        int cnt=0;

        while(1){
            if(onenum % n == 0 ){
                cnt++;
                break;
            }

            onenum = (onenum*10 + 1);
            printf("onenum%lld\n",onenum);
            onenum%=n;
            printf("onenum%lld\n",onenum);
            cnt++;
        }
        printf("%d\n",cnt);
    }
}