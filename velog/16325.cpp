#include <bits/stdc++.h>
using namespace std;

int N,M,K;

int m[11][11];
int s2d2[11][11];


vector<int> trees[11][11];


int main(){
    scanf("%d %d %d",&N,&M,&K);
    
    // 1년마다 영양 공급량 
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            scanf("%d",&s2d2[i][j]);

    // 초기 양분
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            m[i][j] = 5;

    int y,x,age;    
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d %d",&y,&x,&age);

        trees[y][x].push_back(age);
    }

    while(K--){

        // 봄, 여름 : 나이만큼 양분 섭취 -> 나이 1 증가
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                sort(trees[i][j].begin(),trees[i][j].end());
                vector<int> temp;
                int yangbun = 0;
                for(auto age : trees[i][j]){
                    if(m[i][j] >= age){
                        m[i][j] -= age;
                        temp.push_back(age+1);
                    }
                    else{
                        yangbun += age/2;
                    }
                }
                trees[i][j].clear();
                trees[i][j] = temp;
                m[i][j] += yangbun;
            }
            
        }

        // 가을 : 나무 번식
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                for(auto age : trees[i][j]){
                    if(age%5 == 0){
                        for(int p = -1 ; p <= 1 ; p++){
                            for(int q = -1 ; q <= 1 ; q++){
                                if(p == 0 && q == 0) continue;
                                if(i+p < 1 || j+q < 1 || i+p > N || j+q > N) continue;
                                trees[i+p][j+q].push_back(1);
                            }
                        }
                    }
                }
            }
        }


        // 겨울 : s2d2 
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                m[i][j] += s2d2[i][j];
    }

    int ans = 0;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            ans += trees[i][j].size();
    
    printf("%d\n",ans);

}