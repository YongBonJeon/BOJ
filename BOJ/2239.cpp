#include <bits/stdc++.h>
using namespace std;

string m[10];
string ans[10];

bool check(int y, int x, int target){
    if(find(m[y].begin(),m[y].end(),target+'0') != m[y].end())
        return false;
    for(int i = 0 ; i < 9 ; i++){
        if(m[i][x] == target+'0')
            return false;
    }
    int sy = y-y%3;
    int sx = x-x%3;

    for(int i = sy ; i < sy+3 ; i++){
        for(int j = sx ; j < sx+3 ; j++){
            if(m[i][j] == target + '0')
                return false;
        }
    }
    return true;
}

void go(int start){
    if(start == 82){
        for(int i = 0 ; i < 9 ; i++)
            cout << m[i] << '\n';
        exit(0);
    }

    int y = start/9;
    int x = start%9;
    bool un = false;

    for(int i = 1 ; i <= 9 ; i++){
        if(m[y][x] != '0'){
            go(start+1);
            return ;
        }
        if(check(y,x,i)){
            m[y][x] += i;
            go(start+1);
            m[y][x] -= i;
        }
    }
}

int main(){
    for(int i = 0 ; i < 9 ; i++)
        cin >> m[i];
    go(0);
}