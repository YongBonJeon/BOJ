#include <stdio.h>

int main(){
    int num_test;
    int M,N,x,y;

    scanf("%d",&num_test);

    while(num_test>0){
        scanf("%d %d %d %d",&M,&N,&x,&y);
        num_test--;

        int outerflag = -1;
        for(int i = 0; i < M ; i++){
            if((M*i)-(N*(N-1))> N-1){
                continue;
            }
            for(int j = 0 ; j < N ; j++){
                if((M*i)-(N*j) < 1-M){
                    break;
                }
                if((M*i)-(N*j)> N-1){
                    continue;
                }
                if((y-x) == (M*i)-(N*j)){
                    printf("%d\n",M*i+x);
                    outerflag=1;
                    break;
                }
            }
            if(outerflag == 1){
                break;
            }
        }
        if(outerflag == -1)
            printf("-1\n");
    }

}