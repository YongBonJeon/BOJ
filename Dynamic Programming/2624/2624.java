import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int K = sc.nextInt();
        int[] p = new int[K];
        int[] n = new int[K];

        for(int i = 0 ; i < K ; i++) {
            p[i] = sc.nextInt();
            n[i] = sc.nextInt();
        }

        int[] dp = new int[T+1];
        dp[0] = 1;
        for(int i = 0 ; i < K ; i++) {
            int[] nextdp = new int[T+1];
            for(int j = 0 ; j <= T ; j++)
                nextdp[j] = dp[j];
            for(int nn = n[i] ; nn >= 1 ; nn--) {
                for(int temp = T ; temp >= p[i]*nn ; temp--) {
                    //System.out.println(temp + " " + (temp-p[i]*nn) + " " + dp[temp-p[i]*nn]);
                    nextdp[temp] += dp[temp - p[i]*nn];
                }
            }
            for(int j = 0 ; j <= T ; j++) {
                dp[j] = nextdp[j];
                //System.out.print(dp[j] + " ");
            }
            //System.out.println();
        }

        System.out.println(dp[T]);


    }

}