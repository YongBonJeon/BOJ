import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[N];
        long[][] dp = new long[N][21];

        for(int i = 0 ; i < N ;i++)
            arr[i] = sc.nextInt();

        dp[0][arr[0]] = 1L;

        for(int i = 1 ; i < N-1 ; i++) {
            for(int n = 0 ; n <= 20 ; n++) {
                if(n+arr[i] >= 0 && n+arr[i] <= 20)
                    dp[i][n + arr[i]] += dp[i-1][n];
                if(n-arr[i] >= 0 && n-arr[i] <= 20)
                    dp[i][n - arr[i]] += dp[i-1][n];
            }
        }

        System.out.println(dp[N-2][arr[N-1]]);
    }

}