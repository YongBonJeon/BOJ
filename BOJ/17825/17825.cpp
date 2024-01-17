#include <bits/stdc++.h>
using namespace std;

vector<int> adj[33];

int dice[10];
int score_idx[33];
int nextv;
int max0 = 0;

void game(int c[], int thrw, int ans)
{
    if(max0 < ans)
        max0 = ans;
    if(thrw == 10){
        if(max0 < ans)
            max0 = ans;
        return ;
    }

    for(int i = 0 ; i < 4 ; i++)
    {
        int cur = c[i];

        if(cur == 32)
            continue;

        if(cur == 5 || cur == 10 || cur == 15)
            nextv = adj[cur][1];
        else
            nextv = adj[cur][0];

        for(int j = 0 ; j < dice[thrw]-1 ; j++)
            nextv = adj[nextv][0];

        if(nextv != 32)
            if(nextv == c[(i+1)%4] || nextv == c[(i+2)%4] || nextv == c[(i+3)%4])
                continue; 

        c[i] = nextv;
        game(c, thrw+1, ans + score_idx[nextv]);
        c[i] = cur;
    }
    


}

int main()
{
    for(int i = 0 ; i < 20 ; i++)
        adj[i].push_back(i+1);
    adj[21].push_back(22);
    adj[22].push_back(23);
    adj[23].push_back(24);
    adj[25].push_back(26);
    adj[26].push_back(24);
    adj[27].push_back(28);
    adj[28].push_back(29);
    adj[29].push_back(24);
    adj[24].push_back(30);
    adj[30].push_back(31);
    adj[31].push_back(20);
    adj[20].push_back(32);

    adj[5].push_back(21);
    adj[10].push_back(25);
    adj[15].push_back(27);
    adj[32].push_back(32);

    for(int i = 0 ; i <= 20 ; i++)
        score_idx[i] = i*2;
    score_idx[21] = 13;
    score_idx[22] = 16;
    score_idx[23] = 19;
    score_idx[25] = 22;
    score_idx[26] = 24;
    score_idx[24] = 25;
    score_idx[27] = 28;
    score_idx[28] = 27;
    score_idx[29] = 26;
    score_idx[30] = 30;
    score_idx[31] = 35;
    score_idx[32] = 0;     

    for(int i = 0 ; i < 10 ; i++)
        scanf("%d",&dice[i]);

    int c[4] = {0, };
    game(c, 0, 0);
    printf("%d\n",max0);
}