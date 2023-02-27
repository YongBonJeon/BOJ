#include <bits/stdc++.h>
using namespace std;

int R,C,y,x,ny,nx;
int visited[1501][1501];
char m[1501][1501];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

vector<pair<int,int>> swan;
queue<pair<int,int>> swan_q;
queue<pair<int,int>> swan_nq;
queue<pair<int,int>> melt_q;
queue<pair<int,int>> melt_nq;

int main(){
    scanf("%d %d",&R, &C);
    for(int i = 0 ; i < R ; i++)
        scanf("%s",m[i]);

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(m[i][j] == 'L'){
                swan.push_back({i,j});
                //m[i][j] = '.';
                melt_q.push({i,j});
            }
            else if(m[i][j] == '.'){
                melt_q.push({i,j});
            }
        }
    }

    swan_q.push({swan[0].first,swan[0].second});
    visited[swan[0].first][swan[0].second] = 1;

    int cnt = 0; bool meet = false;
    // 만날 때까지 반복문
    while(1){
        // 백조가 이동 가능한 범위 내에서 최대 이동 
        while(!swan_q.empty()){
            tie(y,x) = swan_q.front(); swan_q.pop();

            for(int i = 0 ; i < 4 ; i++){
                ny = y + dy[i];
                nx = x + dx[i];

                if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
                    continue;
                
                if(m[ny][nx] == '.'){
                    swan_q.push({ny,nx});
                    visited[ny][nx] = 1;
                }
                else if(m[ny][nx] == 'X'){
                    swan_nq.push({ny,nx});
                    visited[ny][nx] = 1;
                }
                //else if(ny == swan[1].first && nx == swan[1].second){
                else if(m[ny][nx] == 'L'){
                    meet = true;
                    printf("%d\n",cnt);
                    return 0;
                }
            }
        }

        swan_q = swan_nq;

        while(!melt_q.empty()){
            tie(y,x) = melt_q.front(); melt_q.pop();

            for(int i = 0 ; i < 4 ; i++){
                ny = y + dy[i];
                nx = x + dx[i];

                if(ny < 0 || ny >= R || nx < 0 || nx >= C)
                    continue;

                if(m[ny][nx] == 'X'){
                    m[ny][nx] = '.';
                    melt_nq.push({ny,nx});
                }
            }
        }

        melt_q = melt_nq;

        while(!swan_nq.empty()) swan_nq.pop();
        while(!melt_nq.empty()) melt_nq.pop();

        /*for(int i = 0 ; i < R ; i++)
            printf("%s\n",m[i]);
        printf("\n");*/

        cnt++;
    }
}