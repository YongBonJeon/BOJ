#include <stdio.h>

#define MAX 16500

int n;
int r,c;
int dist_flag = 0;
int dist = 0;

void recursion(int y, int x, int n){

    if(n == 1 || dist_flag){
        return ;
    }
    if(n == 2){
        //printf("%d %d %d\n",y,x,dist);
        if(y == r && x == c){
            //printf("%d\n",dist);
            dist_flag = 1;
            return ;
        }
        else{
            dist++;
        }
        //printf("%d %d %d\n",y,x+1,dist);
        if(y == r && x+1 == c){
            //printf("%d\n",dist);
            dist_flag = 1;
            return ;
        }
        else{
            dist++;
        }
        //printf("%d %d %d\n",y+1,x,dist);
        if(y+1 == r && x == c){
            //printf("%d\n",dist);
            dist_flag = 1;
            return ;
        }
        else{
            dist++;
        }
        //printf("%d %d %d\n",y+1,x+1,dist);
        if(y+1 == r && x+1 == c){
            //printf("%d\n",dist);
            dist_flag = 1;
            return ;
        }
        else{
            dist++;
        }
    }

    if(r < y+(n/2) && c < x+(n/2)){
        recursion(y, x, n/2);
    }
    else if(r < y+(n/2) && c >= x+(n/2)){
        dist+=(n/2)*(n/2);
        recursion(y, x+(n/2), n/2);
    }
    else if(r >= y+(n/2) && c < x+(n/2)){
        dist+=2*(n/2)*(n/2);
        recursion(y+(n/2), x, n/2);
    }
    else{
        dist+=3*(n/2)*(n/2);
        recursion(y+(n/2), x+(n/2), n/2);
    }
    
}

int main(){
    scanf("%d %d %d",&n, &r, &c);
    
    int go = 1;
    for(int i = 0 ; i < n ; i++){
        go = go*2;
    }
    //printf("%d go\n",go);

    recursion(0, 0, go);

    printf("%d\n",dist);
}