import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class counseling {
        int time;
        int profit;

        public counseling(int time, int profit) {
            this.time = time;
            this.profit = profit;
        }
    }
    public static void main(String[] args) {
        int N, t, p;
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        List<counseling> counselings = new ArrayList<>();
        for(int i = 0 ; i < N ; i++) {
            t = sc.nextInt();
            p = sc.nextInt();
            counselings.add(new counseling(t, p));
        }

        int[] dp = new int[N+10];
        dp[0] = 0;

        //System.out.println();
        int max = 0;
        for(int i = 0 ; i < N ; i++) {
            dp[i + counselings.get(i).time] = Math.max(dp[i + counselings.get(i).time], dp[i] + counselings.get(i).profit);
            for(int j = i + counselings.get(i).time ; j < N ; j++)
                dp[j] = Math.max(dp[j], dp[i+counselings.get(i).time]);

            //System.out.println((i + counselings.get(i).time) + " " + dp[i + counselings.get(i).time]);
        }

        //System.out.println();

        int ans = 0;
        for(int i = 0 ; i <= N ; i++) {
            //System.out.println(dp[i] + " ");
            ans = Math.max(ans, dp[i]);
        }
        System.out.println(ans);
    }
}