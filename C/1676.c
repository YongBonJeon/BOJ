#include <stdio.h>

int main(){
    int n;
    long long factorial = 1;
    long long mod = 10;
    int five_cnt = 0;
    int two_cnt = 0;
    scanf("%d",&n);
    for(long long i = n ; i > 0 ; i--){
        long long temp = i;
        while(temp%2==0){
            temp/=2;
            two_cnt++;
        }
        temp = i;
        while(temp%5==0){
            temp/=5;
            five_cnt++;
        }
    }
    if(five_cnt > two_cnt){
        printf("%d\n",two_cnt);
    }
    else{
        printf("%d\n",five_cnt);
    }
}