#include <bits/stdc++.h>
using namespace std;

int N;
int m[21][21];

int go(vector<int> start, vector<int> link){
    int sum = 0;
    for(int i = 0 ; i < N/2 ; i++)
            for(int j = 0 ; j < N/2 ; j++)
                sum += m[start[i]][start[j]];
        

    for(int i = 0 ; i < N/2 ; i++)
            for(int j = 0 ; j < N/2 ; j++)
                sum -= m[link[i]][link[j]];
    
    return abs(sum);
}

int main(){

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++)
            scanf("%d",&m[i][j]);
    }

    int ret = INT_MAX;
    for(int i = 0 ; i < (1 << N) ; i++){
        if(__builtin_popcount(i) != N/2) continue;

        vector<int> start, link;
        
        for(int j = 0 ; j < N ; j++){
            if(i & 1 << j)
                start.push_back(j);
            else
                link.push_back(j);
        }

        ret = min(ret, go(start, link));
    }
    printf("%d\n",ret);
}


/*
int N, total = 0, min_ = 999;
int temp[21][21];
int stat[200] = {0,};

vector<int> team;
void select(int st,int num)
{
    // 절반으로 팀이 나뉜 경우
    if(num == N/2)
    {
        vector<int> another;
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            if(find(team.begin(),team.end(),i) == team.end())
               another.push_back(i);    
        }

        for(int i = 0 ; i < num ; i++){
            for(int j = i+1 ; j < num ; j++)
                sum += temp[another[i]][another[j]] + temp[another[j]][another[i]];
        }

        for(int i = 0 ; i < num ; i++){
            for(int j = i+1 ; j < num ; j++)
                sum -= temp[team[i]][team[j]] + temp[team[j]][team[i]];
        }
        min_ = min(min_, abs(sum));
        
        return ;
    }

    for(int i = st ; i < N ; i++){
        team.push_back(i);
        select(i+1,num+1);
        team.pop_back();
    }

}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d",&temp[i][j]);
            total += temp[i][j];
        }
    }

    select(0,0);
    
    printf("%d\n",min_);

}
*/