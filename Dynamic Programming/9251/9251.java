import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s1, s2;

        s1 = sc.next();
        s2 = sc.next();

        // dp[i][j] 의 의미 = s1에서 i번째, s2에서 j번째까지 봤을 때 LCS 값
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];

        for(int i = 1 ; i <= s1.length() ; i++) {
            for(int j = 1 ; j <= s2.length() ; j++) {
                if(s1.charAt(i-1) == s2.charAt(j-1))
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][j-1] + 1);
                else
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }

        /*for(int i = 1 ; i <= s1.length() ; i++) {
            for(int j = 1 ; j <= s2.length() ; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }*/
        System.out.println(dp[s1.length()][s2.length()]);

    }
}