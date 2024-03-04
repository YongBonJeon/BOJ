### 문제
<https://school.programmers.co.kr/learn/courses/30/lessons/150369>

### 풀이
Level2 문제라고 적혀 있기에 간단하게 해결할 수 있을 줄 알았지만 푸는데 오랜 시간이 걸렸던 문제였다. 특별한 알고리즘이 떠오르진 않아 최대한 간단하게 생각하려 노력했다. **최소 거리**를 움직이기 위해 **최대 거리**에 있는 배달, 수거부터 먼저 진행한다! 라는 생각으로 접근했다.

현재 제일 먼 거리에 있는 집의 배달, 수거를 우선적으로 진행하며 그 과정에서 트럭에서 여유가 있다면 그 다음으로 먼 거리에 있는 집의 배달, 수거도 조금씩 진행한다. 이 아이디어로 예제 정도는 쉽게 해결할 수 있었지만 문제의 조건에 따라 불필요한 반복이 굉장히 많이 생길 수 있다는 단점이 있었고 당연히(?) 시간초과가 발생했다.

불필요한 반복을 줄이기 위해 먼저 현재 제일 먼 거리에 있는 집의 배달, 수거를 끝내기 위해 반복해야 하는 횟수를 구한다. 만약 5의 거리에 있는 집이 배달 물류가 11개, 수거 물류가 4개이고 트럭에 실을 수 있는 최대 물류가 3개라면 5의 거리에 있는 집을 마무리하기 위해선 무조건 4번을 왕복해야 할 것이다. 그렇다면 왕복의 기간 동안 트럭 기사가 배달, 수거할 수 있는 물류는 각 12개이다. 5의 거리에 있는 집에 배달을 11개를 마무리하고 1개의 배달은 다음으로 먼 거리에 있는 집을 진행하고 5의 거리에 있는 집에 수거를 4개를 진행하고 8개는 그 다음으로 먼 거리에 있는 집의 수거를 진행한다.

### Code
```cpp
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int round, temp;
    for(int house = n- 1 ; house >= 0 ; house--){
        if(deliveries[house] == 0 && pickups[house] == 0) continue;
        
        round = (max(deliveries[house], pickups[house])-1)/cap +1;
        
        temp = round*cap;
        for(int i = house ; i >= 0 && temp != 0 ; i--){
            if(deliveries[i] == 0) continue;
            
            if(deliveries[i] <= temp){
                temp -= deliveries[i];
                deliveries[i] = 0;
            }
            else{
                deliveries[i] -= temp;
                temp = 0;
            }
        }
        
        temp = round*cap;
        for(int i = house ; i >= 0 && temp != 0 ; i--){
            if(pickups[i] == 0) continue;
            
            if(pickups[i] <= temp){
                temp -= pickups[i];
                pickups[i] = 0;
            }
            else{
                pickups[i] -= temp;
                temp = 0;
            }
        }
        
        answer += 2*round*(house+1);
    }
    
    return answer;
}
```
