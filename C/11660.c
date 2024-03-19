#include <stdio.h>

int chart[1025][1025]={0,};
int xy[100000][4] ={0,};

int main(){
    int n, m;

    scanf("%d %d",&n, &m);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            scanf("%d",&chart[i][j]);
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++){
            chart[i][j] += (chart[i-1][j] +    chart[i][j-1] -  chart[i-1][j-1]);
        }
    }

    /*for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            printf("%d ",chart[i][j]);
        }
        printf("\n");
    }*/
    int x1,y1,x2,y2;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        printf("%d\n",chart[x2][y2] - chart[x1-1][y2] - chart[x2][y1-1] + chart[x1-1][y1-1]);
    }


}