import java.sql.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N, M, H;
        N = sc.nextInt();
        M = sc.nextInt();
        H = sc.nextInt();
        sc.nextLine();

        List<List<Integer>> blocks = new ArrayList<>();
        blocks.add(new ArrayList<>());
        for(int i =  1 ; i <= N ; i++) {
            blocks.add(new ArrayList<>());

            String temp = sc.nextLine();
            String[] split = temp.split(" ");
            blocks.get(i).add(0);
            for(String s : split) {
                blocks.get(i).add(Integer.valueOf(s));
            }
        }

        int[][] dp = new int[N+1][H+1];
        dp[0][0] = 1;

        for(int i = 1 ; i <= N ; i++) {
            for(int block : blocks.get(i)) {
                for(int h = block ; h <= H ; h++) {
                    dp[i][h] += dp[i-1][h-block];
                    dp[i][h] %= 10007;
                }
            }
            /*for(int h = 0 ; h <= H ; h++) {
                System.out.print(dp[i][h] + " ");
            }
            System.out.println();*/
        }
        System.out.println(dp[N][H]);

    }

}