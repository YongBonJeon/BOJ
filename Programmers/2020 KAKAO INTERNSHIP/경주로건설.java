import java.util.*;

class Solution {
    int[][] dir = {{0,1}, {1, 0}, {0,-1}, {-1,0}};
    public int solution(int[][] board) {
        int answer = Integer.MAX_VALUE;
        int N = board.length;
        int[][][] visited = new int[N][N][4];
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                for(int d = 0 ; d < 4 ; d++)
                    visited[i][j][d] = Integer.MAX_VALUE;

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(0, 0, 0));
        visited[0][0][0] = 1;
        q.add(new Pair(0, 0, 1));
        visited[0][0][1] = 1;

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            //System.out.println("cur " + cur.y + " " + cur.x + " " + cur.dir + " " + visited[cur.y][cur.x][cur.dir]);

            for(int d = 0 ; d < 4 ; d++) {
                int ny, nx;
                if(cur.dir == d) {
                    ny = cur.y + dir[d][0];
                    nx = cur.x + dir[d][1];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                    if(board[ny][nx] == 0 && visited[ny][nx][d] > visited[cur.y][cur.x][d] + 100) {
                        q.add(new Pair(ny, nx, d));
                        visited[ny][nx][d] = visited[cur.y][cur.x][d] + 100;
                    }
                } else {
                    ny = cur.y + dir[d][0];
                    nx = cur.x + dir[d][1];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                    if(board[ny][nx] == 0 && visited[ny][nx][d] > visited[cur.y][cur.x][cur.dir] + 500) {
                        q.add(new Pair(ny, nx, d));
                        visited[ny][nx][d] = visited[cur.y][cur.x][cur.dir] + 600;
                    }
                }
            }
        }

        for(int d = 0 ; d < 4 ; d++) {
            answer = Math.min(answer, visited[N-1][N-1][d] -1);
        }

        return answer;
    }

    class Pair {
        int y, x, dir;

        Pair(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }
}