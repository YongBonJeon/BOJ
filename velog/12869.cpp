#include <bits/stdc++.h>
using namespace std;

int N;
int scv[61][61][61];

typedef struct tri_
{
    int x,y,z;
}tri;

tri damage[6] = 
    {{1,3,9},
    {1,9,3},
    {3,1,9},
    {3,9,1},
    {9,1,3},
    {9,3,1}
    };

void attack(int num, int a, int b, int c)
{
    queue<tri> q;
    int na,nb,nc;

    scv[a][b][c] = 1;
    q.push({a,b,c});

    while(!q.empty())
    {
        tri cur = q.front(); q.pop();

        for(int i = 0 ; i < 6 ; i++)
        {
            na = cur.x - damage[i].x;
            nb = cur.y - damage[i].y;
            nc = cur.z - damage[i].z;

            na = max(na, 0);
            nb = max(nb, 0);
            nc = max(nc, 0);

            if(!scv[na][nb][nc] || scv[na][nb][nc] > scv[cur.x][cur.y][cur.z]+1)
            {
                scv[na][nb][nc] = scv[cur.x][cur.y][cur.z] + 1;

                if(na != 0 || nb != 0 || nc != 0)
                    q.push({na,nb,nc});
            }
        }
    }
}

int main()
{
    scanf("%d",&N);
    
    int temp[3] = {0,};
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&temp[i]);
    }

    attack(0, temp[0], temp[1], temp[2]);

    printf("%d\n",scv[0][0][0]-1);
}