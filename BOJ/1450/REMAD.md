## 문제
<https://www.acmicpc.net/problem/1450>
## 풀이
냅색 문제는 유명하고 해결 알고리즘이 존재하지만 매번 잠깐 써먹고 까먹었다.. 스윽 문제를 보고 DP 배열을 통한 완전 탐색으로 풀 수 있을 줄 알고 대충 덤볐다고 호되게 혼났다. 틀린 풀이는 아니지만 N의 범위가 문제였다. O(2^30)은 쉬운 놈이 아니었다.. 서칭을 통해 찾아본 해결법은 Meet in the Middle 이라는 알고리즘이다. 매우 특별한 것은 아니고 단순하게 문제를 반으로 쪼개는 것이다. 2^30 혹은 2^40 등 브루트포스 알고리즘으로 풀어야 하지만(?) 풀 수 없을 때 문제를 반으로 쪼개서 O(k\*2^(N/2))로 해결하려고 하는 것이다. 처음 보기도 하고 앞으로 잘 적용하려고 노력해봐야겠다.

문제에서 주어진 배열을 반으로 쪼개고 그 배열에서 나올 수 있는 모든 합을 구한다.
예를 들어 {1,2,3,4,5,6,7,8}이라는 배열이 주어졌으면 {1,2,3,4} 배열에서 나올 수 있는 모든 합을 구한다. 2^4 = 16개가 나올 것이다. 반대도 마찬가지로 {5,6,7,8} 배열에서 나올 수 있는 모든 합을 구하고 각 배열을 정렬한다.

그 후에 각 배열을 비교하면서 가능한 합이 존재하는 지 찾는 것이다. 정렬을 하는 이유는 upper_bound를 통해 더 빠르고 쉽게 찾기 위함이다. 냅색 문제이지만ㅁ 부분 배열의 합 문제처럼 해결할 수 있었다.


### success
```cpp
#include<bits/stdc++.h>

using namespace std;

int N,C;
int arr[31];

void make_sum(int idx, int end, int sum, vector<int> &v){
    if(sum > C || sum > 1e9)
        return ;
    if(idx == end){
        v.push_back(sum);
        return ;
    }

    make_sum(idx+1, end, sum+arr[idx], v);
    make_sum(idx+1, end, sum, v);
}

int main(){
    scanf("%d %d",&N, &C);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&arr[i]);

    vector<int> sum1, sum2;

    make_sum(0,N/2,0, sum1);
    make_sum(N/2,N,0, sum2);
    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());

    int ret = 0;
    for(auto x : sum1){
        if(C-x >= 0){
            int pos = upper_bound(sum2.begin(),sum2.end(),C-x) - sum2.begin();
            ret += (pos);
        }
    }
    printf("%d\n",ret);
}
```
### fail
```cpp
typedef long long ll;

int N,C;
int info[31];

map<pair<int,int>,ll> dp;

ll dfs(int idx, int sum){
    ll& ret = dp[{idx,sum}];

    if(idx == N)
        return 1;

    if(ret)
        return ret;

    // 넣을 수 있다면 넣는다
    if(sum+info[idx] <= C){
        ret += dfs(idx+1, sum+info[idx]);
    }
    // 안넣는다
    ret += dfs(idx+1, sum);

    return ret;
}

int main(){
    scanf("%d %d",&N, &C);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&info[i]);

    printf("%lld\n",dfs(0,0));
}
```

