#include <bits/stdc++.h>
using namespace std;

int K;
int Tree[2050];
int data_[2050];
int idx = 0;

void in(int node)
{
    if(node >= pow(2,K))
        return ;
    in(node*2);
    //printf("%d %d\n",node,data_[idx]);
    Tree[node] = data_[idx++];
    in(node*2 + 1);

}

void level()
{
    queue<int> q;
    int cur = 1, depth = 1;
    
    q.push(cur);

    while(!q.empty())
    {
        cur = q.front(); q.pop();
        printf("%d ",Tree[cur]);
        if(cur == pow(2,depth)-1){
            depth++;
            printf("\n");
        }
        if(cur*2 < pow(2,K))
            q.push(cur*2);
        if(cur*2+1 < pow(2,K))
            q.push(cur*2+1);
    }

}

int main()
{
    scanf("%d",&K);
    for(int i = 0 ; i < pow(2,K)-1 ; i++)
        scanf("%d",&data_[i]);
    in(1);
    level();
   // printf("\n");
}