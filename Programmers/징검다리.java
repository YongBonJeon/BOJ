import java.util.*;
class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;

        Arrays.sort(rocks);

        int left = 0, right = distance;

        int s = 0;
        while(left <= right) {
            //System.out.println(left + " " + right);
            int mid = (left + right) / 2;
            int prev = 0, cnt = 0;

            for(int rock : rocks) {
                if(mid > rock - prev)
                    cnt++;
                else
                    prev = rock;
            }
            if(distance - prev < mid) cnt++;

            if(cnt <= n) {
                left = mid + 1;
                answer = Math.max(answer, mid);
            } else
                right = mid - 1;
        }
        return answer;
    }
}