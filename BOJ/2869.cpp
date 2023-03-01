#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,V,cur;

    scanf("%d %d %d",&A,&B,&V);

    cur = (V-A)/(A-B);
    if((V-A)%(A-B))
        cur++;
    printf("%d\n",cur+1);
}