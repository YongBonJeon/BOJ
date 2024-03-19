#include <stdio.h>

int main(){
    int n;
    int i;
    int ans=0;
    int div=10;
    int k;
    scanf("%d",&n);

   
    for(i = 1 ; i <= n ; i*=10){
        ans += n-i+1;
    }
    
    printf("%d\n",ans);
}
