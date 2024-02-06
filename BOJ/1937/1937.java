import java.util.*;

public class Main {
    static int N;
    static int[][] dp;
    static int[][] map;
    static int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        dp = new int[N+1][N+1];
        map = new int[N+1][N+1];

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                map[i][j] = sc.nextInt();
                dp[i][j] = -1;
            }
        }

        if(N == 1){
            System.out.println(1);
            return;
        }

        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                if(dp[i][j] == -1) {
                    dfs(i, j);
                }
            }
        }

        int ans = 1;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println(ans);
    }

    private static int dfs(int y, int x) {
        if(dp[y][x] != -1) return dp[y][x];

        dp[y][x] = 1;
        for(int i = 0 ; i < 4 ; i++ ){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if(ny < 1 || nx < 1 || ny > N || nx > N) continue;

            if(map[ny][nx] > map[y][x]) {
                dp[y][x] = Math.max(dp[y][x], dfs(ny, nx) + 1);
            }
        }
        return dp[y][x];
    }


}