import java.util.*;

public class Main {

    static class Node {
        int x;
        int y;
        int count;

        Node(int y, int x, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "x=" + x +
                    ", y=" + y +
                    ", count=" + count +
                    '}';
        }
    }

    static int N;
    static int M;
    static int[][] map;
    static int[][] dp;


    static int[][] dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        M = sc.nextInt();
        N = sc.nextInt();

        map = new int[M+1][N+1];
        dp = new int[M + 1][N + 1];

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                map[i][j] = sc.nextInt();
                dp[i][j] = -1;
            }
        }
        System.out.println(dfs(0, 0));
    }

    private static int dfs(int y, int x) {
        if(y == M-1 && x == N-1){
            return 1;
        }

        if(dp[y][x] != -1)
            return dp[y][x];

        dp[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(nextY < 0 || nextY >= M || nextX < 0 || nextX >= N) continue;

            if(map[nextY][nextX] < map[y][x]){
                dp[y][x] += dfs(nextY, nextX);
            }
        }
        return dp[y][x];
    }


}