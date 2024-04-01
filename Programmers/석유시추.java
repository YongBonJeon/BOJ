import java.util.*;
class Solution {
    int[][] oil, dir = {{0,1},{0,-1},{-1,0},{1,0}};
    int N,M, max = 0;
    public int solution(int[][] land) {
        int answer = 0;
        N = land.length;
        M = land[0].length;
        oil = new int[N][M];

        int count = 1;
        int[] oilIndex = new int[N*M+1];
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                if(land[i][j] == 1 && oil[i][j] == 0) {
                    int num = dfs(i,j, count, 1, land);
                    oilIndex[count++] = num+1;
                }
            }
        }


        for(int i = 0 ; i < M ; i++) {
            int num = 0;
            boolean[] check = new boolean[N*M+1];
            for(int j = 0 ; j < N ; j++) {
                if(check[oil[j][i]]) continue;
                check[oil[j][i]] = true;
                num += oilIndex[oil[j][i]];
            }
            answer = Math.max(answer, num);
        }

        return answer;
    }
    private int dfs(int y, int x, int c, int depth, int[][] land) {
        oil[y][x] = c;
        int num = 0;
        for(int d = 0 ; d < 4 ; d++) {
            int ny = y + dir[d][0];
            int nx = x + dir[d][1];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if(land[ny][nx] == 1 && oil[ny][nx] == 0) {
                num += dfs(ny, nx, c, depth + 1, land) + 1;
            }
        }
        return num;
    }
}