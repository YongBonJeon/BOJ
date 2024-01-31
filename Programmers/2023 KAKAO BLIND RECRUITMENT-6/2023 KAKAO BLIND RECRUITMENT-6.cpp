#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
string zero[2] = {"du","lr"};
char go[4] = {'d','l','r','u'};
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
int sn, sm, sx, sy, sr, sc;

string min_ans = "EMPTY";
void dfs(int n, int m, int x, int y, int r, int c, int k, int alpha[], string temp){
    int ny, nx;
    if(min_ans.compare("EMPTY"))
        return ;
    
    if(k == 0){
        if(!min_ans.compare("EMPTY")){
            min_ans = temp;
            //cout << temp << '\n';
        }
        else
            return ;
    }
    
    int cnt = alpha[0]+alpha[1]+alpha[2]+alpha[3];
    // k만큼 더 이동해야하는데 이동이 필요한 길이가 k보다 길다
    if(cnt > k) return ;
    // 앞으로 필요한 방향으로만 이동 가능
    else if(k == cnt){
        for(int i = 0 ; i < 4 ; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            
            if(alpha[i] > 0){
                alpha[i]--;
                dfs(n,m,nx,ny,r,c,k-1,alpha,temp+go[i]);
                //alpha[i]++;
            }
        }
    }
    // ㅈ대로 가라 
    else if(k > cnt){
        // d l r u 
        for(int i = 0 ; i < 4 ; i++){
            nx = x + dx[i];
            ny = y + dy[i];
        
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        
            bool flag = false;
            if(alpha[i] > 0){
                alpha[i]--;
                flag = true;
            }
            else
                alpha[3-i]++;
        
            dfs(n,m,nx,ny,r,c,k-1,alpha,temp+go[i]);
            
            if(flag)
                alpha[i]++;
            else
                alpha[3-i]--;
        }
    }
    
    
    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    sn = n; sm = m ;sx = x; sy = y; sr = r; sc = c;
    string answer = "";
    int alpha[4] = {0,};
    
    // 불가능 조건 
    int dist = abs(x-r)+abs(y-c);
    if(dist > k || (k-dist)%2)
        return "impossible";
    
    // d l r u
    if(x < r) {
        alpha[0] += r-x;
    }
    else{
        alpha[3] += x-r;
    }
    
    if(y < c) {
        alpha[2] += c-y;
    }
    else{
        alpha[1] += y-c;
    }
    
    dfs(n,m,x,y,r,c,k,alpha,"");
    
    answer = min_ans;
    
    return answer;
}