## 문제
[3474번](https://www.acmicpc.net/problem/3474)

## 풀이

시간복잡도를 꾸준히 신경써야하는 이유를 알 수 있는 문제였다. 단순하게 수학적으로 문제의 해답은 N!에 2와5가 몇 번 곱해져있는지이다. 이를 통한 접근은 시간초과로 실패했는데 N의 최대 범위가 무려 10억이고 실패한 코드를 보면 1~N까지 순회하면서 각각 2와5가 몇 번 곱해져있는지 파악했는데 이 코드의 시간복잡도는 O(NlogN)이다. 성공하면 오히려 이상하다.

서칭해서 정답 코드들을 살펴보았을 때 대부분 다 같은 코드였지만 왜 그 코드가 답을 도출해내는지 이해가 가지 않아서 많은 고민을 했다.


|/|1|2|3|4|5|6|7|8|9|10|개수|
|:---:|---|---|---|---|---|---|---|---|---|:---:|:---:|
|2|0|1|0|1|0|1|0|1|0|1|5|
|4|0|0|0|1|0|0|0|1|0|0|2|
|8|0|0|0|0|0|0|0|1|0|0|1|

작은 예시부터 고민을 해보며 왜 답이 도출되는 지 파악했다. 결과적으로 위 표를 토대로 쓴 성공 코드의 시간복잡도는 O(logN)이다.

이 문제를 통해 얻은 교훈은 입력의 크기가 상당히 큰 경우 O(logN) 혹은 O(N)으로 문제를 해결해보려고 노력해야 한다는 점이다.

## Code

### - 실패 코드
```cpp
#include<bits/stdc++.h>
using namespace std;

map<int, int> ans;
vector<int> input;

int solve(int n)
{
    int num_5 = 0;

    for(int i = n ; i >= 2 ; i--)
    {
        int temp = i;
        /*while(temp % 2 == 0)
        {
            num_2++;
            temp = temp/2;
        }*/

        while(temp % 5 == 0)
        {
            num_5++;
            temp = temp/5;
        }
    }
    return num_5;
}

int main()
{
    int num_TC;

    scanf("%d",&num_TC);

    for(int i = 0 ; i < num_TC ; i++)
    {
        int N;

        scanf("%d",&N);
        
        printf("%d\n",solve(N));
    }
}
```
### - 성공 코드
```cpp
#include<bits/stdc++.h>
using namespace std;

map<int, int> ans;
vector<int> input;

int solve(int n)
{
    int num_5 = 0;

    for(int i = 5 ; i <= n ; i*=5)
    {
        num_5 += n / i;
    }
    return num_5;
}

int main()
{
    int num_TC;

    scanf("%d",&num_TC);

    for(int i = 0 ; i < num_TC ; i++)
    {
        int N;

        scanf("%d",&N);

        printf("%d\n",solve(N));
    }
}
```

