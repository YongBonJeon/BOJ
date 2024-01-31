- 단순한 최단거리 문제로 생각해 BFS 완전 탐색으로 생각했지만 범위가 매우 넓어 시간초과가 발생했다.
### 실패 코드
```java
import java.util.*;

class Solution {
    int[] visited = new int[100000001];
    public int solution(int storey) {
        int max = 0;
        int temp = storey;
        while(temp > 0) {
            max += temp % 10;
            temp /= 10;
        }
        
        Queue<Integer> q = new LinkedList<>();
        q.add(storey);
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            
            int d = 10000000;
            while(d > cur) 
                d /= 10;
            
            while(d > 0) {
                if(cur == d) return visited[cur] + 1;
                if(visited[cur + d] == 0){
                    visited[cur + d] = visited[cur] + 1;
                    q.add(cur + d);
                }
                if(visited[cur - d] == 0)
                    visited[cur - d] = visited[cur] + 1;
                    q.add(cur - d);  
                d /= 10;
            }
        }
    }
}
```

- 일의 자리부터 각 자리수 마다 그리디하게 지금 올라가야 하는지 내려가야 하는지 판단하는 코드로 수정했다.

### 성공 코드
```java
import java.util.*;

class Solution {
    public int solution(int storey) {
        int answer = 0;
        
        String s = Integer.toString(storey);
        int[] storeyArr = new int[s.length()+1];
        for(int i = 1 ; i <= s.length() ; i++) {
            storeyArr[i] = s.charAt(i-1) - '0';
        }
        storeyArr[0] = 0;
        
        for(int i = s.length() ; i >= 0 ; i--) {
            if(storeyArr[i] == 10) {
                storeyArr[i] = 0;
                storeyArr[i-1] += 1;
            }
            if(storeyArr[i] > 5) {
                answer += 10 - storeyArr[i];
                if(i != 0)
                    storeyArr[i-1]++;
            } else if(storeyArr[i] < 5) {
                answer += storeyArr[i];
            } else if(storeyArr[i] == 5) {
                if(i != 0) {
                    if(storeyArr[i-1] >= 5) {
                        storeyArr[i-1]++;
                    }
                }
                answer += 5;
            }
        }
        return answer;
    }
}
```
