#include <bits/stdc++.h>
using namespace std;

int max_a,max_b,want_a,want_b;
int visited[100][100];
map<pair<int,int>,int> v;

int bfs(){
    int a,b,na,nb;
    queue<pair<int,int>> q;

    //visited[0][0] = 1;
    v[{0,0}] = 1;
    q.push({0,0});

    while(!q.empty()){
        tie(a,b) = q.front(); q.pop();

        //printf("%d %d %d\n",a,b,visited[a][b]);

        if(a == want_a && b == want_b){
            return v[{a,b}];
        }

        // F(a)
        if(!v[{max_a,b}]){
            v[{max_a,b}] = v[{a,b}] + 1;
            q.push({max_a,b});
        }
        // F(b)
        if(!v[{a,max_b}]){
            v[{a,max_b}] = v[{a,b}] + 1;
            q.push({a,max_b});
        }
        // E(a)
        if(!v[{0,b}]){
            v[{0,b}] = v[{a,b}] + 1;
            q.push({0,b});
        }
        // E(b)
        if(!v[{a,0}]){
            v[{a,0}] = v[{a,b}] + 1;
            q.push({a,0});
        }
        // M(a,b)
        if(a+b <= max_b){
            if(!v[{0,a+b}]){
                v[{0,a+b}] = v[{a,b}] + 1;
                q.push({0,a+b});
            }
        }
        else if(a+b > max_b){
            na = a - (max_b - b);
            if(!v[{na,max_b}]){
                //printf("%d %d %d %d",a,max_b,a,b);
                v[{na,max_b}] = v[{a,b}] + 1;
                q.push({na,max_b});
            }
        }
        // M(b,a)
        if(a+b <= max_a){
            if(!v[{a+b,0}]){
                v[{a+b,0}] = v[{a,b}] + 1;
                q.push({a+b,0});
            }
        }
        else if(a+b > max_a){
            nb = b - (max_a - a);
            if(!v[{max_a,nb}]){
                //printf("m(b,a) %d %d %d %d\n",max_a,b,a,b);
                v[{max_a,nb}] = v[{a,b}] + 1;
                q.push({max_a,nb});
            }
        }
    }

    return -1;
}


int main(){
    scanf("%d %d %d %d",&max_a,&max_b,&want_a,&want_b);
    
    int ans;
    if((ans = bfs()) < 0)
        printf("-1\n");
    else
        printf("%d\n",ans-1);

}