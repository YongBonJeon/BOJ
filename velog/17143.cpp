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
    bool move;
}shark;

vector<shark> sharks[102][102];

bool cmp(shark a, shark b)
{
    return a.z > b.z;
}

int main()
{
    scanf("%d %d %d",&R,&C,&M);

    int y,x,s,d,z;
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d %d %d %d",&y,&x,&s,&d,&z);
        sharks[y][x].push_back({y,x,s,d,z,false});
    }

    int catchSum = 0;
    for(int man = 1 ; man <= C ; man++)
    {
        /*for(int i = 1 ; i <= R ; i++){
            for(int j = 1 ; j <= C ; j++)
                if(!sharks[i][j].empty())
                    printf("%d %d %d\n",i,j,sharks[i][j][0].z);
        }
        printf("\n\n");*/


        for(int i = 1 ; i <= R ; i++){
                for(int j = 1 ; j <= C ; j++){
                    if(!sharks[i][j].empty())
                        sharks[i][j][0].move = false;
                }
            }

        // 상어 잡기
        for(int i = 1 ; i <= R ; i++){
            if(!sharks[i][man].empty()){
                //printf("%d catch\n",sharks[i][man][0].z);
                catchSum += sharks[i][man][0].z;
                sharks[i][man].pop_back();
                break;
            }
        }

        

        // 상어 이동
        for(int i = 1 ; i <= R ; i++){
            for(int j = 1 ; j <= C ; j++){
                if(sharks[i][j].empty())
                    continue;
                
                for(int k = 0 ; k < sharks[i][j].size() ; k++){
                    if(sharks[i][j][k].move)
                        continue;

                    int speed = sharks[i][j][k].s;
                    int dir = sharks[i][j][k].d;
                    int ny = sharks[i][j][k].y;
                    int nx = sharks[i][j][k].x;
                    int nz = sharks[i][j][k].z;

                    if(dir == 1 || dir == 2)
                        speed = speed % ((R-1)*2);
                    else if(dir == 3 || dir == 4)
                        speed = speed % ((C-1)*2);

                    //printf("sp %d %d %d\n",i,j,speed);
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
                    sharks[i][j].erase(sharks[i][j].begin()+k);
                    //sharks[i][j].pop_back();
                    sharks[ny][nx].push_back({ny,nx,speed,dir,nz,true});
                }
            }
        }
            
        // 상어 잡아먹기
        for(int i = 1 ; i <= R ; i++){
            for(int j = 1 ; j <= C ; j++){
                if(sharks[i][j].size() > 1){
                    sort(sharks[i][j].begin(),sharks[i][j].end(),cmp);
                    while(sharks[i][j].size() != 1){
                        sharks[i][j].pop_back();
                    }
                }
            }
        }
    }
    printf("%d\n",catchSum);
}