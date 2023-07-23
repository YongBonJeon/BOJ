#include <bits/stdc++.h>
using namespace std;

int space[21][21];
int N, shark_y, shark_x, shark_size;
int target_y, target_x;
int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};

int caneat(){
    
    queue<pair<int,int>> q;
    int visited[21][21];
    memset(visited,0,sizeof(visited));

    q.push({shark_y,shark_x});
    visited[shark_y][shark_x] = 1;

    int cur_y,cur_x,next_y,next_x;
    while(!q.empty()){
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();
        //printf("%d %d\n",cur_y,cur_x);

        if(space[cur_y][cur_x] != 0 && space[cur_y][cur_x] < shark_size){
            return 1;
        }

        for(int i = 0 ; i < 4 ; i++){
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            //printf("%d %d %d\n",next_y,next_x,visited[next_y][next_x]);
            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)
                continue;
            
            if(space[next_y][next_x] == 0 || space[next_y][next_x] <= shark_size){
                if(visited[next_y][next_x] == 0){
                    visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
                    q.push({next_y,next_x});
                }
            }
        }

    }

    return -1;
}

int bfs(){
    int visited[21][21];

    memset(visited,0,sizeof(visited));

    priority_queue<tuple<int,int,int>> q;

    q.push({-1,-shark_y, -shark_x});
    visited[shark_y][shark_x] = 1;
    int cur_y, cur_x,next_y,next_x,val;
    while(!q.empty()){
        tie(val,cur_y,cur_x) = q.top();
        cur_y = -cur_y;
        cur_x = -cur_x;
        q.pop();

        //printf("%d %d\n",cur_y,cur_x);

        if(space[cur_y][cur_x] < shark_size && space[cur_y][cur_x] != 0){
            target_y = cur_y;
            target_x = cur_x;
            //printf("%d %d %d\n",target_y,target_x, visited[cur_y][cur_x]);
            return visited[cur_y][cur_x]-1;
        }

        for(int i = 0 ; i < 4 ; i++){
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)
                continue;

            if(space[next_y][next_x] <= shark_size){
                if(visited[next_y][next_x] == 0){        
                    visited[next_y][next_x] += visited[cur_y][cur_x] + 1;
                    q.push({-visited[next_y][next_x],-next_y,-next_x});
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%1d",&space[i][j]);
            if(space[i][j] == 9){
                shark_y = i;
                shark_x = j;
            }
        }
    }
    shark_size = 2;

    int totaleat = 0;
    int doeat, cnt = 0, dist;
    while((doeat = caneat()) != -1){
        /*printf("doeat %d shark_size %d cnt %d\n",doeat,shark_size,cnt);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                printf("%d ",space[i][j]);
            }
            printf("\n");
        }*/
        if(doeat == 1){
            if((dist = bfs()) == -1){
                break;
            }
            space[shark_y][shark_x] = 0;
            space[target_y][target_x] = 0;
            cnt += dist;
            totaleat += 1;
            shark_y = target_y;
            shark_x = target_x;
        }
        else{
            if((dist = bfs()) == -1){
                break;
            }
            cnt += dist;
            space[shark_y][shark_x] = 0;
            space[target_y][target_x] = 0;
            shark_y = target_y;
            shark_x = target_x;
            totaleat += 1;
        }
        if(totaleat == shark_size){
            totaleat = 0;
            shark_size++;
        }
    }
    printf("%d\n",cnt);
}