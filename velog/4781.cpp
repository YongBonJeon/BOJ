#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main(){
    int n,m_100,c,p_100;
    double m,p;

    while(1){
        scanf("%d %lf",&n, &m);
        if(n == 0 && m == 0.00)
            break;
        m_100 = (int)(m*100+0.5);

        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i < n ; i++){
            scanf("%d %lf",&c, &p);
            p_100 = (int)(p*100+0.5);

            for(int j = p_100 ; j <= m_100 ; j++){
                dp[j] = max(dp[j], dp[j-p_100]+c);
            }
        }
        printf("%d\n",dp[m_100]);
    }
}