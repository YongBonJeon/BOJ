import java.sql.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        // 3 7
        // 3 5 6
        int N = sc.nextInt();
        int[] arr = new int[N];
        int[] dp = new int[N];

        for(int i = 0 ; i < N ; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.fill(dp, 1);

        int max = 0;
        for(int i = 1 ; i < N ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(arr[j] < arr[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            max = Math.max(dp[i], max);
        }

        System.out.println(N - max);



    }

}