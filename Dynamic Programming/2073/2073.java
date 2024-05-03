import java.sql.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int D, P;
        D = sc.nextInt();
        P = sc.nextInt();

        int[] ds = new int[P+1];
        int[] ps = new int[P+1];

        //
        int[] dp = new int[D+1];

        for(int i = 1 ; i <= P ; i++) {
            ds[i] = sc.nextInt();
            ps[i] = sc.nextInt();
        }

        dp[0] = Integer.MAX_VALUE;
        for(int i = 1 ; i <= P ; i++) {
            for(int j = D ; j >= ds[i] ; j--) {
                dp[j] = Math.max(dp[j], Math.min(dp[j-ds[i]], ps[i]));
            }
        }
        System.out.println(dp[D]);


    }



}