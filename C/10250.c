#include <stdio.h>

int main(){
    int t,w,h,n;
    int i;
    int yy,xx, total=0;
    scanf("%d",&t);

    for(i = 0 ; i < t ; i++){
        scanf("%d %d %d",&w, &h, &n);
        yy = (n % w);
        xx = (n / w)+1;
        total = yy*100+xx;
        printf("%d\n",total);
    }
    return 0;
}