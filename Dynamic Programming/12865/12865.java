import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N, K;

        N = sc.nextInt();
        K = sc.nextInt();

        int[] weight = new int[N];
        int[] value = new int[N];
        int[] dp = new int[K+1];

        for(int i = 0 ; i < N ; i++) {
            weight[i] = sc.nextInt();
            value[i] = sc.nextInt();
        }

        for(int w = 0 ; w < N ; w++) {
            for (int i = K; i >= weight[w]; i--) {
                dp[i] = Math.max(dp[i], dp[i - weight[w]] + value[w]);
            }
        }

        System.out.println(dp[K]);
    }
}