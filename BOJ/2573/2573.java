import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N, M;
    static int[][] map = new int[301][301];
    static int[][] newMap = new int[301][301];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] = sc.nextInt();
            }
        }

        int sec = 0;

        while(!isAllZero()) {
            melt();
            if(blockNum() == 1) {
                sec++;
            } else if(blockNum() == 2) {
                System.out.println(++sec);
                return;
            } else {
                System.out.println(0);
                return;
            }
        }
        System.out.println(sec);


    }

    private static void melt() {
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] != 0){
                    int cnt = 0;
                    if(i-1 >= 0 && map[i-1][j] == 0) cnt++;
                    if(i+1 < N && map[i+1][j] == 0) cnt++;
                    if(j-1 >= 0 && map[i][j-1] == 0) cnt++;
                    if(j+1 < M && map[i][j+1] == 0) cnt++;
                    newMap[i][j] = map[i][j] - cnt;
                    if(newMap[i][j] < 0) newMap[i][j] = 0;
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] = newMap[i][j];
                newMap[i][j] = 0;
            }
        }
    }

    private static int blockNum() {
        boolean[][] visited = new boolean[N][M];
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] != 0 && !visited[i][j]){
                    cnt++;
                    dfs(i, j, visited);
                    if(cnt >= 2) return 2;
                }
            }
        }
        return cnt;
    }

    private static void dfs(int i, int j, boolean[][] visited) {
        visited[i][j] = true;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(map[nx][ny] != 0 && !visited[nx][ny]){
                dfs(nx, ny, visited);
            }
        }
    }

    private static boolean isAllZero() {
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] != 0) return false;
            }
        }
        return true;
    }


}
