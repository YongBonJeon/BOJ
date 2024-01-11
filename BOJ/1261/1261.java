import java.util.*;

public class Main {
    static int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int M = sc.nextInt();
        int N = sc.nextInt();

        int[][] map = new int[N + 1][M + 1];
        int[][] visited = new int[N + 1][M + 1];


        for (int i = 0; i < N; i++) {
            String s = sc.next();
            for (int j = 0; j < M; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
            Arrays.fill(visited[i], 201);
        }

        PriorityQueue<Pair> q = new PriorityQueue<>((n1, n2) -> n1.cnt - n2.cnt);

        q.add(new Pair(0, 0, 0));
        visited[0][0] = 0;

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            //System.out.println(cur.y + " " + cur.x + " " + visited[cur.y][cur.x]);

            if (cur.y == N - 1 && cur.x == M - 1) {
                System.out.println(visited[N - 1][M - 1]);
                return;
            }

            for (int i = 0; i < 4; i++) {
                Pair next = new Pair(cur.y + dir[i][0], cur.x + dir[i][1], visited[cur.y][cur.x]);

                if (next.y >= N || next.x >= M || next.y < 0 || next.x < 0) continue;

                if (visited[next.y][next.x] == 201) {
                    if (map[next.y][next.x] == 1) {
                        visited[next.y][next.x] = visited[cur.y][cur.x] + 1;
                        //map[next.y][next.x] = 0;
                        next.cnt += 1;
                        q.add(next);
                    } else {
                        visited[next.y][next.x] = visited[cur.y][cur.x];
                        q.add(next);
                    }
                }
            }
        }
    }

    static class Pair {
        int y;
        int x;
        int cnt;

        public Pair(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }
}