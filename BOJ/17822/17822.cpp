#include <bits/stdc++.h>
using namespace std;

int N,M,T;
int m[51][51];

typedef struct _r{
    int T_num;
    int dir;
    int R_num;
}r;

r rot[51];

void update(){
    double sum = 0, num = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(m[i][j]){
                sum += m[i][j];
                num++;
            }
        }
    }
    double average = sum / num;
    //printf("%lf %lf %lf\n",sum,num,average);

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(m[i][j]){
                if(m[i][j] < average)
                    m[i][j] += 1;
                else if(m[i][j] > average)
                    m[i][j] -= 1;
            }
        }
    }
}

int del(){
    int flag = 0;
    int temp[51][51];
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            temp[i][j] = m[i][j];

    // 같은 원판 내 인접 삭제
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(temp[i][j] && temp[i][j] == temp[i][(j)%M+1]){
                // 1234
                m[i][j] = 0;
                // 1234 2345 -> 2341
                m[i][(j)%M+1] = 0;
                flag = 1;
            }
        }
    }
    // 위 아래 원판과 인접 삭제
    for(int i = 1 ; i <= N-1 ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(temp[i][j] && temp[i][j] == temp[i+1][j]){
                m[i][j] = 0;
                m[i+1][j] = 0;
                flag = 1;
            }
        }
    }
    return flag;
}

// n번 원판 시계 방향 회전 
void rotate(int n, int dir, int R_num){
    if(dir){
        R_num = M - R_num;
    }

    int temp[51];
    for(int i = 1 ; i <= M ; i++)
        temp[i] = m[n][i];

    for(int i = 1 ; i <= M ; i++){
        m[n][(i+R_num-1)%M + 1] = temp[i];
    }

    /*printf("%d\n",n);
    for(int i = 1 ; i <= M ; i++)
        printf("%d ",temp[i]);
    printf("\n");
    for(int i = 1 ; i <= M ; i++)
        printf("%d ",m[n][i]);
    printf("\n");*/
}

int main()
{
    scanf("%d %d %d",&N, &M, &T);
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            scanf("%d",&m[i][j]);
        }
    }

    for(int i = 0 ; i < T ; i++){
        scanf("%d %d %d",&rot[i].T_num,&rot[i].dir,&rot[i].R_num);
    }

    for(int i = 0 ; i < T ; i++){
        int num = rot[i].T_num;
        int dir = rot[i].dir;
        int R_num = rot[i].R_num;

        // 회전
        for(int j = num ; j <= N ; j += num){
            //printf("%d %d %d\n",j,dir,R_num);
            rotate(j,dir,R_num);
        }
        /*printf("after rotate\n");
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                printf("%d ",m[i][j]);
            }
            printf("\n");
        }*/
        // 인접 삭제
        if(!del()){
            // 평균 계산 및 원판 최신화
            update();
        }
        /*printf("after update\n");
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                printf("%d ",m[i][j]);
            }
            printf("\n");
        }*/
    }
    int ans = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            ans += m[i][j];
        }
    }
    printf("%d\n",ans);
}