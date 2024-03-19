#include <stdio.h>

int k[1001];

void tile(int n){
    k[1] = 1;
    k[2] = 3;
    for(int i = 3; i <=n ; i++){
        k[i] = k[i-1] + k[i-2]*2;
        k[i] = k[i]%10007;
    }
}

int main(){
    int n;

    scanf("%d",&n);

    tile(n);

    printf("%d\n",k[n]);
}