#include <bits/stdc++.h>
using namespace std;

int R,C,M;
int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,1,-1};

typedef struct _shark{
    int y;
    int x;
    int s;
    int d;
    int z;
    bool death;
}shark;

shark sharks[10000];

int main()
{
    scanf("%d %d %d",&R,&C,&M);

    int y,x,s,d,z;
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d %d %d %d",&y,&x,&s,&d,&z);
        sharks[i].y = y;
        sharks[i].x = x;
        sharks[i].s = s;
        sharks[i].d = d;
        sharks[i].z = z;
        sharks[i].death = false;
        
    }

    int catchSum = 0;
    for(int man = 1 ; man <= C ; man++)
    {
        printf("%d\n",man);
        for(int sh = 0 ; sh < M ; sh++)
            printf("%d %d\n",sharks[sh].y, sharks[sh].x);
        printf("\n\n");

        // 상어 잡기
        int min_ = 10000, min_idx = -1; 
        for(int sh = 0 ; sh < M ; sh++)
        {
            if(!sharks[sh].death && sharks[sh].x == man){
                if(min_ > sharks[sh].y){
                    min_ = sharks[sh].y;
                    min_idx = sh;
                }
            }
        }

        if(min_idx != -1){
            printf("catch %d\n",sharks[min_idx].z);
            catchSum += sharks[min_idx].z;
            sharks[min_idx].death = true;
        }

        // 상어 이동
        for(int sh = 0 ; sh < M ; sh++)
        {
            if(sharks[sh].death) continue;

            int speed = sharks[sh].s;
            int dir = sharks[sh].d;
            int ny = sharks[sh].y;
            int nx = sharks[sh].x;

            if(dir == 1 || dir == 2)
                speed = speed % ((R-1)*2);
            else if(dir == 3 || dir == 4)
                speed = speed % ((C-1)*2);
            
            //printf("sh %d speed %d\n",sh,speed);
            for(int s = 0 ; s < speed ; s++)
            {
                ny += dy[dir];
                nx += dx[dir];

                if(ny == 0){
                    ny = 2;
                    dir++;
                }
                if(ny == R+1){
                    ny = R-1;
                    dir--;
                }
                if(nx == 0){
                    nx = 2;
                    dir--;
                }
                if(nx == C+1){
                    nx = C-1;
                    dir++;
                }
                //printf("%d %d\n",ny,nx);
            }

            sharks[sh].y = ny;
            sharks[sh].x = nx;
            sharks[sh].d = dir;
        }

        // 상어 잡아먹기
        for(int i = 0 ; i < M ; i++){
            for(int j = i+1 ; j < M ; j++){
                if(sharks[i].y == sharks[j].y && sharks[i].x == sharks[j].x && !sharks[i].death && !sharks[j].death){
                    int big = (sharks[i].z > sharks[j].z) ? i : j;
                    int small = (big == i) ? j : i;

                    sharks[big].z += sharks[small].z;
                    sharks[small].death = true;
                }
            }
        }



    }
    printf("%d\n",catchSum);
}