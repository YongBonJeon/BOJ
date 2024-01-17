import java.lang.reflect.Array;
import java.util.*;

public class Main {

    static class Pair {
        int curV;
        int level;

        public Pair(int cur, int level) {
            this.curV = cur;
            this.level = level;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "curV=" + curV +
                    ", level=" + level +
                    '}';
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int start = sc.nextInt();
        int max = sc.nextInt();

        int[][] dp = new int[101][1001];

        dp[0][start] = 1;

        for (int i = 0; i < N; i++) {
            int cur = sc.nextInt();
            for (int v = 0; v <= max; v++) {
                if (dp[i][v] == 1) {
                    if(v-cur >= 0)
                        dp[i+1][v-cur] = 1;
                    if(v+cur <= max)
                        dp[i+1][v+cur] = 1;
                }
            }
        }
        for (int v = max; v >= 0; v--) {
            if (dp[N][v] == 1) {
                System.out.println(v);
                return ;
            }
        }
        System.out.println(-1);


    }

}