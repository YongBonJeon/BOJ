#include <bits/stdc++.h>
using namespace std;

int N,K;
int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,1,-1,0,0};

typedef struct _h{
    int y;
    int x;
    int dir;
}h;

vector<int> chess[15][15];
int m[15][15];
h horse[15];

void move(int num){
    int y = horse[num].y;
    int x = horse[num].x;
    int dir = horse[num].dir;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    bool out = false;

    // 체스판을 나가려는 경우
    if(ny < 1 || ny > N || nx < 1 || nx > N) out = true;

    // 이동하려는 곳이 파란색
    if(out || m[ny][nx] == 2){
        if(dir == 1 || dir == 2)
            dir = horse[num].dir = dir^3;
        else if(dir == 3 || dir == 4)
            dir = horse[num].dir = dir^7;
        ny = y + dy[dir];
        nx = x + dx[dir];

        if(ny < 1 || ny > N || nx < 1 || nx > N || m[ny][nx] == 2)
            return ;
    }

    vector<int> &v = chess[y][x];
    vector<int> &nextv = chess[ny][nx];
    auto pos = find(v.begin(),v.end(),num);
    if(m[ny][nx] == 1)
        reverse(pos,v.end());
    for(auto it = pos ; it != v.end() ; it++){
        horse[*it].y = ny;
        horse[*it].x = nx;
        nextv.push_back(*it);
    }
    v.erase(pos,v.end());

    // 이동하려는 곳이 흰색
    /*if(m[ny][nx] == 0){
        queue<int> temp;

        bool flag = false;
        for(auto h : chess[y][x]){
            if(h == num){
                flag = true;
                temp.push(h);
            }
            else if(flag){
                temp.push(h);
            }
        }
        for(int i = 0 ; i < temp.size() ; i++)
            chess[y][x].pop_back();
        
        while(temp.size()){
            int h = temp.front(); temp.pop();
            horse[h].y = ny;
            horse[h].x = nx;
            chess[ny][nx].push_back(h);
        }
    }
    // 이동하려는 곳이 빨간색
    else if(m[ny][nx] == 1){
        stack<int> temp;
        bool flag = false;
        for(auto h : chess[y][x]){
            if(h == num){
                flag = true;
                temp.push(h);
            }
            else if(flag){
                temp.push(h);
            }
        }
        for(int i = 0 ; i < temp.size() ; i++)
            chess[y][x].pop_back();
        
        while(temp.size()){
            int h = temp.top(); temp.pop();
            horse[h].y = ny;
            horse[h].x = nx;
            chess[ny][nx].push_back(h);
        }
    }*/
}

int main(){
    scanf("%d %d",&N, &K);
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            scanf("%d",&m[i][j]);

    for(int i = 1 ; i <= K ; i++){
        scanf("%d %d %d",&horse[i].y,&horse[i].x,&horse[i].dir);
        chess[horse[i].y][horse[i].x].push_back(i);
    }

    int turn = 1;
    while(1){
        // 종료 조건
        if(turn > 1000){
            printf("-1\n");
            return 0;
        }

        for(int i = 1 ; i <= K ; i++){
            move(i);

            for(int k = 1 ; k <= N ; k++){
                for(int l = 1 ; l <= N ; l++){
                    if(chess[k][l].size() >= 4){
                        printf("%d\n",turn);
                        return 0;
                    }
                }
            }
        }
        turn++;
    }
}