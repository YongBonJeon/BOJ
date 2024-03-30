import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.Buffer;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] map, visited;
    static int[][] dir = {{0,-1},{0,1},{-1,0},{1,0}};
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N][M];
        visited = new int[N][M];
        Queue<Pair> q = new ArrayDeque<>();
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                map[i][j] = sc.nextInt();
                if(map[i][j] == 2) {
                    q.add(new Pair(i,j));
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            for(int d = 0 ; d < 4; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

                if(visited[ny][nx] == 0 && map[ny][nx] == 1) {
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    q.add(new Pair(ny,nx));
                }
            }
        }

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                if(map[i][j] == 0)
                    bw.write(0 + " ");
                else
                    bw.write((visited[i][j]-1) + " ");
            }
            bw.write("\n");
        }
        bw.close();

    }

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}