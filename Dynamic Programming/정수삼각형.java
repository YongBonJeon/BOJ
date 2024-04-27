class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int N = triangle.length;
        int[][] dp = new int[N+1][N+1];

        dp[0][0] = triangle[0][0];

        for(int i = 0 ; i < N-1 ; i++) {
            for(int j = 0 ; j <= i ; j++) {
                dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j] + triangle[i+1][j]);
                dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1]);
            }
        }

        for(int i = 0 ; i < N ; i++)
            answer = Math.max(answer, dp[N-1][i]);

        return answer;
    }
}