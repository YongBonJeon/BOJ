class Solution {
    public int solution(int[] money) {
        int answer = 0;
        int N = money.length;

        int[] dp = new int[N];

        // 첫번째 집을 터는 경우
        dp[0] = money[0];
        dp[1] = Math.max(money[0], money[1]);

        for(int i = 2 ; i < N-1 ; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + money[i]);
            //System.out.print(dp[i] + " ");
        }
        //System.out.println();

        answer = Math.max(answer, dp[N-2]);

        // 첫번째 집을 털지 않는 경우
        dp = new int[N];
        dp[0] = 0;
        dp[1] = money[1];

        for(int i = 2 ; i < N ; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + money[i]);
            //System.out.print(dp[i] + " ");
        }

        answer = Math.max(answer, dp[N-1]);

        return answer;
    }
}