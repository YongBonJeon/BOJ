#include <bits/stdc++.h>
using namespace std;

int N;
int m[101][101];
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

typedef struct _dragon{
    int x;
    int y;
    int d;
    int g;
}dragon;

vector<dragon> input;

vector<pair<int,int>> last_dragon;

void addDragon()
{
    // 끝점
    int sx = last_dragon[last_dragon.size()-1].first;
    int sy = last_dragon[last_dragon.size()-1].second;

    int l = (int)(last_dragon.size()-1);
    for(int i = 0 ; i < l ; i++){
        int x = last_dragon[l-1-i].first-sx;
        int y = last_dragon[l-1-i].second-sy;
        int nx,ny;

        nx = -y;
        ny = x;

        last_dragon.push_back({sx+nx,sy+ny});
    }
}

void make(int num)
{
    
    int x = input[num].x;
    int y = input[num].y;
    int d = input[num].d;
    int g = input[num].g;

    last_dragon.push_back({0,0});

    // 0세대 드래곤 커브
    last_dragon.push_back({0+dx[d], 0+dy[d]});

    for(int i = 0 ; i < g ; i++){
        addDragon();
    }

    for(auto coordinate : last_dragon){
        coordinate.first += x;
        coordinate.second += y;
        //printf("%d %d\n",coordinate.first,coordinate.second);

        m[coordinate.second][coordinate.first] = 1;
    }
    //printf("\n\n");
}

int main()
{
    scanf("%d",&N);
    int x,y,d,g;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d %d %d",&x,&y,&d,&g);
        dragon n = {x,y,d,g};
        input.push_back(n);
    }

    for(int i = 0 ; i < N ; i++){
        last_dragon.clear();
        make(i);
    }

    int ans = 0;
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            if(m[i][j] && m[i+1][j] && m[i][j+1] && m[i+1][j+1])
                ans++;
        }
    }
    printf("%d\n",ans);



}