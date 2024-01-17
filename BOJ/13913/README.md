### 문제
[13913번](https://www.acmicpc.net/problem/13913)

## 풀이
[12851](https://velog.io/@bon0057/CC-%EB%B0%B1%EC%A4%80-12851-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%882)번이나 다른 숨바꼭질 문제와 같이 BFS + DP를 사용하는 것은 똑같으나 최단 거리를 출력해보이는 것은 상당히 까다로운 문제이다. 학교 알고리즘 시간에 DP를 다룰 때에 기억으로 **Path를 기록하는 새로운 배열을 만들어 문제를 해결**하기는 했으나 정확하게 이해는 하지 못하고 제출했다.

Path(Direction) 배열을 기록할 때 처음에 실패했던 것이 BFS 작동 중에 cur -> next로 진행될 때 Direction\[cur](추적)을 이용해서 실패했다가 Direction\[next](역추적)을 이용해서 문제를 해결했었는데 지금 글을 작성하며 이해가 된 것이 Direction\[cur]을 이용해 cur->next로 추적하는 것은 최단거리 보장이 되어 있지 않다. **Direction\[next]는 최단거리가 보장**되어 있어서(우리는 **BFS+DP를 이용해 visited,direction 배열을 항상 최솟값, 최단거리로 최신화**하고 있다!) next->cur(prev)로 역추적을 해서 동선을 파악하는 것이 가능한 것이다.

문제 해결 자체는 그렇게 어렵지 않으나 BFS+DP 개념에 대해서 한번 더 생각해볼 수 있는 좋은 문제였다.


