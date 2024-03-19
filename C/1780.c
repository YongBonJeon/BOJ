#include <stdio.h>

#define MAX 2188

int n;
int paper[MAX][MAX];
int num[3] = {0,};

void cut_paper(int y, int x, int n){
    int checker = paper[y][x];
    //printf("checker %d ", checker);
    int cut_flag = 0;

    if(n == 1){
        //printf("%d %d %d %d\n",checker, y,x,n);
        num[checker+1]++;
        return ;
    }

    for(int i = y ; i < y+n ; i++){
        for(int j = x ; j < x+n ; j++){
            /* 같은 수로 이루어진 종이가 아니라면 */
            if(paper[i][j] != checker){
                cut_flag = 1;
            }
        }
    }

    /* 전부 같은 수로 이루어진 종이라면 */
    if(!cut_flag){
        //printf("%d %d %d %d\n",checker, y,x,n);
        num[checker+1]++;
    }
    else{
        for(int k = 0 ; k < 3 ; k++){
            for(int l = 0 ; l < 3 ; l++){
                cut_paper(y+(n/3)*k, x+(n/3)*l, n/3);
            }
        }
    }
}

int main(){
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d",&paper[i][j]);
        }
    }
    cut_paper(0, 0, n);

    printf("%d\n%d\n%d\n",num[0],num[1],num[2]);
    
}