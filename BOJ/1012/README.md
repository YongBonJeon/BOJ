## 문제

[1012번](https://www.acmicpc.net/problem/1012)


## 풀이

입력이 Map으로 주어져 있는 입력에 대해서 Connected Components를 찾는 문제이다. DFS, BFS 어떤 것을 사용해도 상관이 없다. Map을 순회하며 배추가 있고 방문한 적이 없다면 DFS를 호출하여 해당 배추와 연결된 배추들을 탐색한다. DFS의 호출 횟수가 정답이 된다.

기억할만한 점은 visited[][] **2차원 배열의 간단한 초기화 방법**과 입력이 Map으로 주어지고 DFS, BFS로 풀어야 하는 문제들의 **정형화된 코드**이다. 2차원 배열로 Map과 Visited 선언, 4방향 탐색을 위한 dy, dx 배열 선언 꼴이다.

