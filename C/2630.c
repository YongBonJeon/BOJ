#include <stdio.h>

#define MAX 128

int paper[MAX][MAX];
int num[2] = {0,};
int n;

void cut_paper(int y, int x, int n){
    int checker = paper[y][x];
    int cut_flag = 0;


    /* 전부 같은 색인지 확인 */
    for(int i = y ; i < y+n ; i++){
        for(int j = x ; j < x+n ; j++){
            if(checker != paper[i][j]){
                cut_flag = 1;
                break;
            }
        }
        if(cut_flag){
            break;
        }
    }

    if(cut_flag){
        cut_paper(y, x, n/2);

        cut_paper(y, x+(n/2), n/2);

        cut_paper(y+(n/2), x, n/2);

        cut_paper(y+(n/2), x+(n/2), n/2);
    }
    else{
        num[checker]++;
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

    printf("%d\n%d\n",num[0], num[1]);
}

