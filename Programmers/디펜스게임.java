import java.util.*;
class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;

        if(enemy.length <= k)
            return enemy.length;

        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> {
            return o1 - o2;});
        for(int i = 0 ; i < k ; i++)
            pq.add(enemy[i]);

        for(int i = k ; i < enemy.length ; i++) {
            if(pq.peek() < enemy[i] && n >= Math.min(pq.peek(), enemy[i])) {
                n -= pq.poll();
                pq.add(enemy[i]);
            } else if(n >= enemy[i]){
                n -= enemy[i];
            } else
                return i;
        }

        return enemy.length;
    }
}