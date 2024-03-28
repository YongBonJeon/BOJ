import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        // 소요시간 우선순위 큐
        PriorityQueue<int[]> workQ = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        // 작업 시작 시간 우선순위 큐
        PriorityQueue<int[]> startQ = new PriorityQueue<>((o1, o2) -> o1[0] - o2[0]);

        for(int i = 0 ; i < jobs.length ; i++)
            startQ.add(jobs[i]);

        int cur = 0;
        int answer = 0;
        while(!startQ.isEmpty() || !workQ.isEmpty()) {

            // 현재 가능한 작업 소요시간 우선순위 큐에 삽입
            while(!startQ.isEmpty() && startQ.peek()[0] <= cur) {
                workQ.add(startQ.poll());
            }
            //System.out.println("cur " + cur);
            //System.out.println(workQ.peek()[0] + " " + workQ.peek()[1]);
            // 가장 소요시간이 적은 작업 수행
            if(!workQ.isEmpty()) {
                answer += workQ.peek()[1] + cur - workQ.peek()[0];
                cur += workQ.poll()[1];
            } else {
                cur = startQ.peek()[0];
            }

        }

        return answer / jobs.length;
    }
}