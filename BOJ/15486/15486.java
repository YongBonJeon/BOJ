import java.util.*;

public class Main {
    static int N;
    static int[][] info;
    static int[] dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        info = new int[N+55][2];
        dp = new int[N+55];

        for(int i = 1 ; i <= N ; i++) {
            info[i][0] = sc.nextInt();
            info[i][1] = sc.nextInt();
        }

        for(int i = 1 ; i <= N+1 ; i++) {
            if(dp[i] < dp[i-1])
                dp[i] = dp[i-1];
            dp[i + info[i][0]] = Math.max(dp[i + info[i][0]], dp[i] + info[i][1]);
        }

        //for(int i = 1 ; i <= N+1 ; i++)
        //    System.out.println(dp[i]);

        System.out.println(dp[N+1]);
    }
}