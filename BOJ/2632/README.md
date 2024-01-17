## 문제
[2632번](https://www.acmicpc.net/problem/2632)

## 풀이
정말 어려웠던 문제였다. 처음에 생각했던 풀이는 피자 A, B를 2차원 배열을 통해 0~N-1 각 인덱스부터의 누적합을 나타내고 A의 2차원 누적합 배열을 순회하면서 각 누적합에 대해 B의 2차원 누적합 배열에 원하는 값이 존재하는 지 찾는 알고리즘을 시도했는데 시간복잡도가 O(**N\*M**(2차원 배열 순회) * **M\*logM**(M < N 가정, 이분 탐색 사용))이다. N과 M이 1,000 이하이므로 이렇게 큰 시간복잡도를 가진 알고리즘으론 문제를 해결할 수 없었다.

문제를 해결할 때 도움이 된 부분이 누적합을 나타내는 부분이었다. 처음 풀이에서는 2차원 배열을 사용했다면 1차원 카운팅 배열을 통해 표현을 시도한 것이다. 피자의 누적합의 범위가 1,000 * 1,000 = 1,000,000 이므로 배열의 인덱스로 표현할 수 있었다.

## Code
### 실패 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int order;
int m,n;

int A[1001];
int B[1001];

int sum_A[1001][1001];
int sum_B[1001][1001];

int main()
{
    scanf("%d",&order);
    scanf("%d %d",&m,&n);
    int t;
    for(int i = 0 ; i < m ; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&B[i]);
    }

    for(int i = 0 ; i < m ; i++){
        int sum = 0;
        for(int j = 0 ; j < m ; j++){
            sum += A[(i+j)%m];
            sum_A[i][j] = sum;
        }
    }
    for(int i = 1 ; i < m ; i++)
        sum_A[i][m-1] = 0;
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < n ; j++){
            sum += B[(i+j)%n];
            sum_B[i][j] = sum;
        }
    }
    for(int i = 1 ; i < n ; i++)
        sum_B[i][n-1] = 0;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ",sum_A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d ",sum_B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int ans = 0;
    int need;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            need = order - sum_A[i][j];
            if(need == 0)
                ans++;
            if(need <= 0)
                break;

            for(int k = 0 ; k < n ; k++){
                if(binary_search(sum_B[k],sum_B[k]+n,need)){
                    ans++;
                }
            }

        }
    }
    printf("%d\n",ans);
}
```
### 성공 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int order;
int m,n;

int A[1001];
int B[1001];

int sum_A[1000001] = {0,};
int sum_B[1000001] = {0,};

int main()
{
    scanf("%d",&order);
    scanf("%d %d",&m,&n);
    int sum = 0;
    for(int i = 0 ; i < m ; i++){
        scanf("%d",&A[i]);
        sum += A[i];
    }
    sum_A[sum]++;
    sum = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&B[i]);
        sum += B[i];
    }
    sum_B[sum]++;

    for(int i = 0 ; i < m ; i++){
        int sum = 0;
        for(int j = 0 ; j < m-1 ; j++){
            sum += A[(i+j)%m];
            sum_A[sum]++;
        }
    }
    sum_A[0]++;

    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < n-1 ; j++){
            sum += B[(i+j)%n];
            sum_B[sum]++;
        }
    }
    sum_B[0]++;

    int ans = 0;
    for(int i = 0 ; i <= order ; i++){
        ans += sum_A[i]*sum_B[order-i];
    }
    printf("%d\n",ans);
}
```
