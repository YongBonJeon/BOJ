#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

int m[11][11];
int cnt = 0;
int s[6] = {5,5,5,5,5,5};

bool check(int y, int x, int r){
    if(s[r] == 0)
        return false;
    
    for(int i = y ; i < y+r ; i++){
        for(int j = x ; j < x+r ; j++){
            if(i >= 10 || j >= 10)
                return false;
            if(m[i][j] == 0)
                return false;
        }
    }
    return true;
}

int sack(int y, int x, int r){
    int temp = 0;
    for(int i = y ; i < y+r ; i++){
        for(int j = x ; j < x+r ; j++){
            m[i][j] = 0;
            temp++;
        }
    }
    return temp;
}
void unsack(int y, int x, int r){
    for(int i = y ; i < y+r ; i++){
        for(int j = x ; j < x+r ; j++){
            m[i][j] = 1;
        }
    }
}

void backtracking(int start, int depth){
    if(depth >= ans)
        return ;
    if(cnt == 0){
        ans = min(ans, depth);
        return ;
    }

    int y = start/10;
    int x = start%10;

    // 0일 경우 칠하지 않고 다음 탐색 
    if(!m[y][x])
        backtracking(start+1,depth);
        
    // 1이므로 1~5의 크기 색종이 중 하나로 가능하다면 색칠하고 다음 탐색 
    for(int r = 5 ; r >= 1 ; r--){
        if(check(y,x,r)){
            int t = sack(y,x,r);
            cnt -= t;
            s[r]--;
            backtracking(start + r,depth+1);
            s[r]++;
            unsack(y,x,r);
            cnt += t;
        }
    }
}


int main(){
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            scanf("%d",&m[i][j]);
            if(m[i][j]){
                cnt++;
            }
        }
    }
    backtracking(0,0);
    if(ans == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n",ans);

}