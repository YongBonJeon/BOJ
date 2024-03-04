### 문제
2023 KAKAO BLIND RECRUITMENT - Lv.3
<https://school.programmers.co.kr/learn/courses/30/lessons/150365>

### 풀이
중복 방문을 허용하는 그래프 탐색 문제는 상당한 난이도를 자랑한다. 한 칸 이동하고 다시 돌아오는 경우 등은 기존의 BFS, DFS에서 방문 배열을 통해 불가능하게 했던 경우기에 아예 다른 방식으로 해결해야 한다.

처음에 접근했던 방식은 K만큼의 이동은 일단 논외로 하고 {x,y} -> {r,c}로 이동하는 최단 거리는 정해져 있고 간단하게 구할 수 있다. 예를 들어 {1,1} -> {3,3}은 갈 수 있는 방식은 다양하지만 d\*2,r\*2를 무조건 가야한다. 그래서 처음에 생각했던 방식은 만약 K가 6이라면 "ddrr"을 무조건 path에 넣고 제자리에 이동하는 방법인 "du" 혹은 "rl"을 넣은 후에 **정렬**하는 방식을 생각했는데 사전 순으로 가장 빠르고 정확하게 도달은 할 수 있지만 진행 중간에 Map밖으로 나가는 경우인지 확인을 해야하는 것이 문제였다.

예를 들어 x,y,r,c는 위의 예와 같고 K가 10이라면 "ddrr"에 "du" 혹은 "rl"을 넣을 수 있는 방식은 du\*3, rl\*3, du\*2 + rl, ... 등등 많은데 최악의 경우 이 모든 경우의 수마다 추가로 모든 정렬의 경우의 수에 대해 확인을 해야할 수 있다는 것이다. 어떤 방식으로 최적화를 할 수 있을 지는(?) 모르겠지만 적어도 나는 바로 포기했다.

다음으로 생각한 방식은 유사 DFS(?), 재귀로 해결하는 방식이었다. 추가요망


### Code
```cpp
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
    // 아무렇게나 가라 
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
```