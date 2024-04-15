import java.util.*;
public class Main {
    static int N;
    static int[][] visited;
    static int[][] dir ={{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        visited = new int[N][N];

        Queue<Pair> q = new ArrayDeque<>();
        int y = sc.nextInt(), x = sc.nextInt();
        q.add(new Pair(y, x));
        visited[y][x] = 1;

        int target_y = sc.nextInt(), target_x = sc.nextInt();
        while(!q.isEmpty()) {
            Pair cur = q.poll();

            if(cur.y == target_y && cur.x == target_x) {
                System.out.println(visited[cur.y][cur.x] - 1);
                return ;
            }

            for(int d = 0 ; d < 6 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                if(visited[ny][nx] == 0) {
                    q.add(new Pair(ny, nx));
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                }
            }
        }
        System.out.println(-1);
    }

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}