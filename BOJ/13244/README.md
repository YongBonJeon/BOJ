### 문제
[13244번](https://www.acmicpc.net/problem/13244)

## 풀이
입력으로 주어지는 그래프가 트리인가를 판단하는 문제이다. 트리는 acyclic, connected의 성질을 갖고 있다. 우선 cyclic을 판단하는 것은 매우 간단하다. vertex가 N개일 때 edge가 N+1개 초과이면 cycle이 생길 수 밖에 없다. 또 edge가 N-1개 미만이면 connected 일 수 없다. 이 조건으로 먼저 간단하게 처리할 수 있고 edge가 N+1개 이더라도 unconnected, cyclic일 가능성도 있으므로 임의의 vertex에 대해 DFS를 통해 탐색한 후에 모든 vertex를 방문했는 지를 통해 최종적으로 그래프 or 트리를 판단한다.

