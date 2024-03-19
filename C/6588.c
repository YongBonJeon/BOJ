#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/* y보다 크고 x보다 작은 소수 중 가장 작은 소수 반환 */
int findPrime(int x, int y){
    for(int i = y ; i <= x ; i++){
        int isPrime = TRUE;
        for(int j = 2 ; j <= sqrt(i); j++){
            if(i%j==0){
                isPrime = FALSE;
                break;
            }
        }
        if(isPrime)
            return i;
    }
    return 0;
}

/* 소수 테스트 */
int isPrime(int y){
    //2~root(y)까지 나눠지는 숫자가 있으면 소수가 아님
    for(int j = 2 ; j <= sqrt(y) ; j++){
        if(y%j==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int testcase = -1;

    while(1){
        scanf(" %d",&testcase);
        if(testcase == 0){  break;}
        
        int min = 2;
        while(1){
            int a = findPrime(testcase,min+1);
            if(a == 0 && a > testcase/2){ //testcase보다 작은 소수가 존재x
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
            int b = testcase - a;
            if(isPrime(b)){
                printf("%d = %d + %d\n",testcase,a,b);
                break;
            }
            else{
                min=a;
            }
        }
    }

    
}
