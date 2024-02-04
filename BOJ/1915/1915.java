import java.util.*;

public class Main {
    static int N, M;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        int[][] dp = new int[N + 1][M + 1];

        boolean zero = true;
        for(int i = 1; i <= N; i++) {
            String next = sc.next();
            for(int j = 0 ; j < M ; j++) {
                if (next.charAt(j) == '1') {
                    dp[i][j + 1] = 1;
                    zero = false;
                }
            }
        }
        if(zero){
            System.out.println(0);
            return;
        }

        int size = 1;
        boolean isUpdate = true;
        while(isUpdate){
            isUpdate = false;
            for (int i = 1; i < N; i++) {
                for (int j = 1; j < M; j++) {
                    if (dp[i][j] == size && dp[i+1][j] == size
                            && dp[i][j+1] == size && dp[i+1][j+1] == size) {
                        //System.out.println(i + " " + j + " " + size);
                        dp[i][j] = size + 1;
                        isUpdate = true;
                    }
                }
            }
            if(isUpdate) {
                size++;
            }
        }
        System.out.println(size*size);
    }
}