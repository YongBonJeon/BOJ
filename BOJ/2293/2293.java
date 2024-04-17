import java.util.*;

public class Main {
    static int N, K;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        K = sc.nextInt();

        int[] coin = new int[N];
        int[] dp = new int[K+1];

        for(int i = 0 ; i < N ; i++) {
            coin[i] = sc.nextInt();
        }

        dp[0] = 1;

        for(int c = 0 ; c < N ; c++) {
            for(int i = coin[c] ; i <= K ; i++) {
                dp[i] += dp[i - coin[c]];
            }
        }

        /*for(int i = 0 ; i <= K ; i++)
            System.out.print(dp[i] + " ");*/
        System.out.println(dp[K]);


    }
}