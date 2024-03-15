class Solution {
    public int[] solution(int target) {
        int[] answer = {};

        int[][] dp = new int[target+101][2];
        for(int i = 1 ; i <= target ; i++) {
            dp[i][0] = 987654321;
            dp[i][1] = 987654321;
        }

        // 우선순위 : 싱글+불 / 더블+트리플

        for(int cur = 0 ; cur < target ; cur++) {
            // 싱글 or 불
            for(int single = 1 ; single <= 20 ; single++) {
                if(dp[cur+single][0] + dp[cur+single][1] > dp[cur][0] +dp[cur][1]+ 1) {
                    dp[cur + single][0] = dp[cur][0] + 1;
                    dp[cur + single][1] = dp[cur][1];
                } else if(dp[cur+single][0] + dp[cur+single][1] == dp[cur][0] +dp[cur][1]+ 1) {
                    if(dp[cur+single][0] < dp[cur][0] + 1) {
                        dp[cur + single][0] = dp[cur][0] + 1;
                        dp[cur + single][1] = dp[cur][1];
                    }
                }
            }
            if(dp[cur+50][0] + dp[cur+50][1] > dp[cur][0] +dp[cur][1]+ 1) {
                dp[cur + 50][0] = dp[cur][0] + 1;
                dp[cur + 50][1] = dp[cur][1];
            } else if(dp[cur+50][0] + dp[cur+50][1] == dp[cur][0] +dp[cur][1]+ 1) {
                if(dp[cur+50][0] < dp[cur][0] + 1) {
                    dp[cur + 50][0] = dp[cur][0] + 1;
                    dp[cur + 50][1] = dp[cur][1];
                }
            }

            // 더블 or 트리플
            for(int dou = 2 ; dou <= 40 ; dou+=2) {
                if(dp[cur+dou][0] + dp[cur+dou][1] > dp[cur][1] +dp[cur][0]+ 1) {
                    dp[cur + dou][1] = dp[cur][1] + 1;
                    dp[cur + dou][0] = dp[cur][0];
                }
            }
            for(int triple = 3 ; triple <= 60 ; triple+=3) {
                if(dp[cur+triple][0] + dp[cur+triple][1] > dp[cur][1]+dp[cur][0] + 1) {
                    dp[cur + triple][1] = dp[cur][1] + 1;
                    dp[cur + triple][0] = dp[cur][0];
                }
            }
        }

        /*for(int i = 0 ; i <= target ; i++) {
            System.out.print(i + " " + dp[i][0] + " " + dp[i][1] + "\n");
        }*/

        return new int[]{dp[target][0] + dp[target][1], dp[target][0]};
    }
}