#include <bits/stdc++.h>
using namespace std;

int space[21][21];
int N, shark_y, shark_x, shark_size;
int target_y, target_x;

int caneat(){
    int fish = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(space[i][j] < shark_size && space[i][j] != 0)
                fish++;
        }
    }
    return fish;
}

int bfs(){
    int dy[4] = {-1,0,0,1};
    int dx[4] = {0,-1,1,0};
    int visited[21][21];

    memset(visited,0,sizeof(visited));

    priority_queue<pair<int,int>> q;

    q.push({-shark_y, -shark_x});
    visited[shark_y][shark_x] = 1;
    int cur_y, cur_x,next_y,next_x;
    while(!q.empty()){
        cur_y = -q.top().first;
        cur_x = -q.top().second;
        q.pop();

        printf("%d %d\n",cur_y,cur_x);

        if(space[cur_y][cur_x] < shark_size && space[cur_y][cur_x] != 0){
            target_y = cur_y;
            target_x = cur_x;
            printf("%d %d %d\n",target_y,target_x, visited[cur_y][cur_x]);
            return visited[cur_y][cur_x];
        }

        for(int i = 0 ; i < 4 ; i++){
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)
                continue;

            if(space[next_y][next_x] <= shark_size){
                if(visited[next_y][next_x] == 0){        
                    visited[next_y][next_x] += visited[cur_y][cur_x] + 1;
                    q.push({-next_y,-next_x});
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
    int k=0;
    while((doeat = caneat()) != 0 && (k++)<4){
        printf("doeat %d shark_size %d cnt %d\n",doeat,shark_size,cnt);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                printf("%d ",space[i][j]);
            }
            printf("\n");
        }
        if(doeat == 1){
            dist = bfs();
            space[shark_y][shark_x] = 0;
            space[target_y][target_x] = 9;
            cnt += dist;
            totaleat += 1;
            shark_y = target_y;
            shark_x = target_x;
        }
        else{
            dist = bfs();
            cnt += dist;
            space[shark_y][shark_x] = 0;
            space[target_y][target_x] = 9;
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