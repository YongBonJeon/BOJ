import java.lang.reflect.Array;
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


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int W = sc.nextInt();
        int H = sc.nextInt();

        int[][] map = new int[H + 1][W + 1];
        int[][][] visited = new int[H + 1][W + 1][K + 1];
        for (int i = 0; i < H; i++) {
            for(int j = 0 ; j < W ; j++){
                map[i][j] = sc.nextInt();
            }
        }

        if(H == 1 && W == 1){
            System.out.println(0);
            return;
        }

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, 0));

        int[][] knight = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
        int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.isEmpty()) {
            Node node = q.poll();
            int x = node.x;
            int y = node.y;
            int count = node.count;

            //System.out.println(node);

            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];

                if (dx < 0 || dx >= W || dy < 0 || dy >= H) {
                    continue;
                }

                if (map[dy][dx] == 0 && visited[dy][dx][count] == 0) {
                    visited[dy][dx][count] = visited[y][x][count] + 1;
                    q.add(new Node(dy, dx, count));
                }
            }

            if(count < K) {
                for (int i = 0; i < 8; i++) {
                    int dx = x + knight[i][0];
                    int dy = y + knight[i][1];

                    if (dx < 0 || dx >= W || dy < 0 || dy >= H) {
                        continue;
                    }

                    if (map[dy][dx] == 0 && visited[dy][dx][count+1] == 0) {
                        visited[dy][dx][count+1] = visited[y][x][count] + 1;
                        q.add(new Node(dy, dx, count + 1));
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= K; i++) {
            if(visited[H - 1][W - 1][i] == 0) continue;
            ans = Math.min(ans, visited[H - 1][W - 1][i]);
        }
        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);

    }



}