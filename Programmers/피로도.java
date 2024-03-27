class Solution {
    boolean[] visited;
    int N, max_ans = 0;
    public int solution(int k, int[][] dungeons) {
        int answer = -1;

        N = dungeons.length;
        visited = new boolean[N];
        select(0, new StringBuilder(), k, dungeons);
        return max_ans;
    }

    private void select(int idx, StringBuilder sb, int k, int[][] d) {
        if(idx == N) {
            int local_ans = 0;

            for(int i = 0 ; i < N ; i++) {
                if(d[sb.charAt(i)-'0'][0] <= k) {
                    k -= d[sb.charAt(i)-'0'][1];
                    local_ans++;
                } else break;
            }
            max_ans = Math.max(max_ans, local_ans);
        }

        for(int i = 0 ; i < N ; i++) {
            if(visited[i]) continue;

            visited[i] = true;
            StringBuilder nsb = new StringBuilder(sb);
            select(idx+1, nsb.append(i), k, d);
            visited[i] = false;
        }
    }
}