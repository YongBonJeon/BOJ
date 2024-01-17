## 문제
[1269번](https://www.acmicpc.net/problem/1269)

## 풀이
정렬과 이분 탐색을 통한 풀이와 Map을 이용한 풀이, 2가지 풀이를 해보았다. 첫번째 풀이의 경우 정렬은 O(BlogB), 이분 탐색은 O(AlogB)의 시간복잡도를 가지므로 충분히 시간 내에 풀 수 있다. 두번째 풀이의 경우 공통 Map을 사용하여 훨씬 간단하게 풀 수 있다. 최종 결과에서 두번째 풀이의 경우가 메모리, 시간 모두 첫번째 풀이에 비해 많이 소요되었는데 Map의 공간, 시간복잡도에 대해서도 공부해볼 필요가 있을 것 같다.

## Code
### binary_search
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    int A[200001];
    int B[200001];

    scanf("%d %d",&a, &b);
    for(int i = 0 ; i < a ; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0 ; i < b ; i++){
        scanf("%d",&B[i]);
    }
    sort(B,B+b);

    int common = 0;
    for(int i = 0 ; i < a ; i++){
        if(binary_search(B,B+b,A[i]))
            common++;
    }
    printf("%d\n",a+b-2*common);
}
```

### Map
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,t;
    map<int,int> m;

    scanf("%d %d",&a, &b);
    for(int i = 0 ; i < a ; i++){
        scanf("%d", &t);
        m[t]++;
    }
    for(int i = 0 ; i < b ; i++){
        scanf("%d",&t);
        m[t]++;
    }
    
    int ans = 0;
    for(auto it : m){
        if(it.second == 1)
            ans++;
    }
    printf("%d\n",ans);
}
```
