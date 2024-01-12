import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        int[][] dp = new int[N + 1][K + 1];
        for (int i = 0; i <= N; i++) {
            dp[i][1] = 1;
        }

        for(int cnt = 2 ; cnt <= K ; cnt++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= i; j++) {
                    dp[i][cnt] += dp[j][cnt-1];
                    dp[i][cnt] %= 1000000000;
                }
            }
        }

        /*for (int i = 1; i <= 2; i++) {
            for (int j = 0; j <= N; j++) {
                System.out.print(dp[j][i] + " ");
            }
            System.out.println();
        }*/

        System.out.println(dp[N][K]);
    }
}