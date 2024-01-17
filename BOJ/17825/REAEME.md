## 문제
[17825번](https://www.acmicpc.net/problem/17825)

## 풀이
문제로 주어진 그래프를 최대한 자신만의 방법으로 표현하는 것이 중요했다.
![](https://velog.velcdn.com/images/bon0057/post/8dfb6ba3-27a7-405b-939b-9b6045144123/image.jpeg)
중복된 점수를 가진 vertex가 존재하므로 새로 vertex의 번호를 지정해 그래프를 구성했고 완전 탐색을 통해 주사위 10번을 굴리는 동안 4개의 말이 이동할 수 있는 모든 경우의 수를 찾아 점수의 최댓값을 찾았다.

