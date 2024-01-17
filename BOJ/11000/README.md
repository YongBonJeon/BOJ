## 문제
[11000번](https://www.acmicpc.net/problem/11000)

## 풀이
강의실의 역할을 할 Priority Queue를 만들고 입력으로 받은 데이터를 정렬한다. 

정렬된 데이터를 하나씩 보면서 Priority Queue의 top(가장 빨리 끝나는 강의)와 비교한다.

같은 강의실을 사용할 수 있으면 top을 pop하고 새로운 강의를 push한다.

같은 강의실을 사용할 수 없으면 그대로 새로운 강의를 push한다.






