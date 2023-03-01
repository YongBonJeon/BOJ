#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;

// 1~i 까지 누적합
ll sum(vector<ll> &tree, int i){
    ll ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i&-i);
    }
    return ans;
}

// i번째 노드 수정 -> 트리 최신화
void update(vector<ll> &tree, int i, ll diff){
    while(i < tree.size()){
        tree[i] += diff;
        i += (i&-i);
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    vector<ll> a(n+1);
    // 팬윅 트리
    vector<ll> tree(n+1);
    
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld",&a[i]);
        update(tree, i, a[i]);
    }
    int cmd, idx, idx1;
    ll idx2,diff;
    for(int i = 0 ; i < m+k ; i++){
        scanf("%d",&cmd);
        if(cmd == 1){
            scanf("%d %lld",&idx,&idx2);
            diff = idx2-a[idx];
            a[idx] = idx2;
            update(tree,idx,diff);
        }
        else if(cmd == 2){
            scanf("%d %d",&idx,&idx1);
            printf("%lld\n",sum(tree,idx1)-sum(tree,idx-1));
        }
    }
}