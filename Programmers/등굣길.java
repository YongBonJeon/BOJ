class Solution {
    int M, N;
    int[][] map, dp;
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        M = m; N = n;
        dp = new int[M+1][N+1];
        map = new int[M+1][N+1];

        for(int[] puddle : puddles)
            map[puddle[0]][puddle[1]] = 1;
        for(int i = 1 ; i <= M ; i++)
            for(int j = 1 ; j <= N ; j++)
                dp[i][j] = -1;

        answer = dfs(1,1);

        return answer % 1000000007;
    }

    private int dfs(int y, int x) {
        if(y == M && x == N) return 1;

        if(dp[y][x] != -1) return dp[y][x];

        int l = 0,r = 0;
        if(y + 1 <= M && map[y+1][x] == 0) {
            l = dfs(y+1, x);
        }
        if(x + 1 <= N && map[y][x+1] == 0)
            r = dfs(y, x+1);

        dp[y][x] = (l+r) % 1000000007;
        return dp[y][x];
    }
}