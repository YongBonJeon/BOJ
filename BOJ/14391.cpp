#include <bits/stdc++.h>
using namespace std;

int N,M;
char m[5][5];
int visited[5][5];
int max_ = 0;

int cal_low()
{
    int check[5][5], sum = 0;
    memset(check,0,sizeof(check));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int temp = 0;
            int t = j;
            while(t < M && !check[i][t] && !visited[i][t] ){
                temp = temp*10 + m[i][t]-'0';
                check[i][t] = 1;
                t++;
            }
            sum += temp;
        }
    }
    return sum;
}
int cal_col()
{
    int check[5][5], sum = 0;
    memset(check,0,sizeof(check));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int temp = 0;
            int t = i;
            while(t < N && !check[t][j] && visited[t][j] ){
                temp = temp*10 + m[t][j]-'0';
                check[t][j] = 1;
                t++;
            }
            sum += temp;
        }
    }
    return sum;
}

void select(int start,int depth)
{
    max_ = max(cal_col()+cal_low(),max_);

    for(int i = start; i < N*M ; i++){
        int y = i / M;
        int x = i % M;

        visited[y][x] = 1;
        select(i+1, depth+1);
        visited[y][x] = 0;
    }

}

int main()
{
    scanf("%d %d",&N,&M);

    for(int i = 0 ; i < N ; i++)
        scanf("%s",m[i]);

    select(0,0);

    printf("%d\n",max_);
}