import java.sql.Array;
import java.util.*;

public class Main {
    static int T, N, M;
    static long answer = 0;
    static long[][] dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();

        while(T-- > 0) {
            answer = 0L;
            N = sc.nextInt();
            M = sc.nextInt();

            dp = new long[N+1][M+1];

            for(int i = 0 ; i <= M ; i++)
                dp[0][i] = 1L;

            for(int n = 1 ; n <= N ; n++) {
                for(int m = 1 ; m <= M ; m++) {
                    dp[n][m] = dp[n-1][m/2] + dp[n][m-1];
                }
            }
            System.out.println(dp[N][M]);
        }
    }



}