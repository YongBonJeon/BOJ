class Solution {
    boolean[] visited;
    public int solution(int n, int[][] computers) {
        int answer = 0;

        visited = new boolean[n];
        for(int i = 0 ; i < n ; i++) {
            if(visited[i]) continue;
            dfs(i, computers);
            answer++;
        }

        return answer;
    }

    private void dfs(int st, int[][] computers) {
        visited[st] = true;

        for(int next = 0 ; next < computers.length ; next++) {
            if(!visited[next] && computers[st][next] == 1)
                dfs(next, computers);
        }
    }
}