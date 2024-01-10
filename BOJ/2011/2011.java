import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String code = sc.next();

        if (code.charAt(0) == '0') {
            System.out.println(0);
            return ;
        }

        int[][] dp = new int[code.length()][2];

        if (code.charAt(code.length() - 1) == '0') {
            String c = code.substring(code.length() - 2);
            if (c.compareTo("00") > 0 && c.compareTo("26") <= 0) {
                dp[code.length() - 2][0] = 0;
                dp[code.length() - 2][1] = 1;
            } else {
                System.out.println(0);
                return ;
            }


            for (int i = code.length() - 3; i >= 0; i--) {
                String s = code.substring(i, i + 2);

                if (code.charAt(i) == '0') {
                    s = code.substring(i - 1, i + 1);
                    if (s.compareTo("00") > 0 && s.compareTo("26") <= 0) {
                        dp[i - 1][1] = dp[i + 1][0] + dp[i + 1][1];
                        i--;
                        continue;
                    } else {
                        System.out.println(0);
                        return ;
                    }
                }

                // 합칠 수 있음
                if (s.compareTo("00") > 0 && s.compareTo("26") <= 0) {
                    //System.out.println(code.charAt(i) + " " + code.charAt(i + 1));
                    // 안합 = 직전합 + 직전안합
                    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
                    dp[i][0] %= 1000000;
                    // 합 = 직전안합
                    dp[i][1] = dp[i + 1][0];
                    dp[i][1] %= 1000000;
                } else {
                    // 안합
                    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
                    dp[i][0] %= 1000000;
                }
            }

            System.out.println((dp[0][0] + dp[0][1]) % 1000000);
        } else {
            dp[code.length() - 1][0] = 1;
            dp[code.length() - 1][1] = 0;

            for (int i = code.length() - 2; i >= 0; i--) {
                String s = code.substring(i, i + 2);

                // 무조건 앞이랑 합쳐야됨
                if (code.charAt(i) == '0') {
                    s = code.substring(i - 1, i + 1);
                    if (s.compareTo("00") > 0 && s.compareTo("26") <= 0) {
                        dp[i - 1][1] = dp[i + 1][0] + dp[i + 1][1];
                        i--;
                        continue;
                    } else {
                        System.out.println(0);
                        return ;
                    }
                }

                // 합칠 수 있음
                if (s.compareTo("00") > 0 && s.compareTo("26") <= 0) {
                    // 안합 = 직전합 + 직전안합
                    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
                    // 합 = 직전안합
                    dp[i][1] = dp[i + 1][0];
                    dp[i][0] %= 1000000;
                    dp[i][1] %= 1000000;
                } else {
                    // 안합
                    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
                    dp[i][0] %= 1000000;
                }
            }

            System.out.println((dp[0][0] + dp[0][1]) % 1000000);
        }
    }
}