## 문제
<https://www.acmicpc.net/problem/2294>

## 풀이
풀 때도 느끼고 복습하면서도 느끼는 거지만 내 알고리즘 풀이의 제일 약점은 다이내믹 프로그래밍인 것 같다. DP를 활용해야겠다는 잘 느끼지만서도 이게 참 구현력이 부족한 것 같다. 불과 몇 주전에 구현했던 코드인데 DP를 활용하긴 했지만 참 어렵게도 생각했다는 느낌을 받아 훨씬 간단하게 고쳐보았다. 수정 후에 동작 시간도 훨씬 줄어드는 것을 알 수 있었다.

## Code
### Waste
```cpp
#include <bits/stdc++.h>
using namespace std;

int n,k;
int dp[100001];

int main(){
    scanf("%d %d",&n, &k);

    for(int i = 0 ; i <= k ; i++)
        dp[i] = INT_MAX;

    int t;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&t);
        dp[t] = 1;
    }

    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j < i ; j++){
            if(dp[j] != INT_MAX && dp[i-j] != INT_MAX)
                dp[i] = min(dp[i],dp[j] + dp[i-j]);
        }
    }

    if(dp[k] == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n",dp[k]);

}
```
### Good

```cpp
#include <bits/stdc++.h>
using namespace std;

int n,k;
int dp[100001];
int INF = 98765321;

int main(){
    scanf("%d %d",&n, &k);

    for(int i = 1 ; i <= k ; i++)
        dp[i] = INF;

    int t;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&t);

        for(int j = t ; j <= k ; j++){
            dp[j] = min(dp[j], dp[j-t]+1);
        }

    }

    if(dp[k] == INF)
        printf("-1\n");
    else
        printf("%d\n",dp[k]);

}
```
