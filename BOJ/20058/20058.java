import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;
import java.awt.*;

public class Main {
    static int N,Q, twoN;
    static int[][] map, newMap;
    static int[][] dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    static boolean[][] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int order;

        N = sc.nextInt();
        Q = sc.nextInt();

        twoN = (int) Math.pow(2, N);
        map = new int[twoN][twoN];

        for(int i = 0 ; i < twoN ; i++) {
            for(int j = 0 ; j < twoN ; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        //rotate_unit(0,0, 8);

        while(Q > 0) {
            order = sc.nextInt();

            // 회전
            rotate(order);

            // 녹이기
            melt();
            Q--;
        }

        int rest_ans = 0;
        int max_ans = 0;
        visited = new boolean[twoN][twoN];
        for(int i = 0 ; i < twoN ; i++) {
            for(int j = 0 ; j < twoN ; j++) {
                //System.out.print(map[i][j] + " ");
                rest_ans += map[i][j];
                if(!visited[i][j] && map[i][j] > 0)
                    max_ans = Math.max(max_ans, bfs(i,j));
            }
            //System.out.println();
        }
        System.out.println(rest_ans);
        System.out.println(max_ans);
    }

    private static int bfs(int i, int j) {
        int cnt = 1;
        visited[i][j] = true;

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(i, j));

        while (!q.isEmpty()) {
            Pair cur = q.poll();

            for (int d = 0; d < 4; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if (ny < 0 || nx < 0 || ny >= twoN || nx >= twoN) continue;

                if (!visited[ny][nx] && map[ny][nx] > 0) {
                    q.add(new Pair(ny, nx));
                    visited[ny][nx] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    private static void melt() {
        int[][] meltMap = new int[twoN][twoN];
        for(int i = 0 ; i < twoN ; i++) {
            for(int j = 0 ; j < twoN ; j ++) {
                if(map[i][j] == 0) continue;
                int cnt = 0;
                for(int d = 0 ; d < 4 ; d++) {
                    int ny = i + dir[d][0];
                    int nx = j + dir[d][1];

                    if(ny < 0 || nx < 0 || ny >= twoN || nx >= twoN) continue;

                    if(map[ny][nx] > 0) cnt++;
                }
                if(cnt < 3)
                    meltMap[i][j] = map[i][j] -1;
                else
                    meltMap[i][j] = map[i][j];
            }
        }
        for(int i = 0 ; i < twoN ; i++) {
            for (int j = 0; j < twoN; j++) {
                map[i][j] = meltMap[i][j];
            }
        }
    }

    private static void rotate(int order) {
        int unit = (int) Math.pow(2, order);

        newMap = new int[twoN][twoN];

        for(int i = 0 ; i < twoN ; i+=unit) {
            for (int j = 0; j < twoN; j += unit) {
                rotate_unit(i, j, unit);
            }
        }

        for(int i = 0 ; i < twoN ; i++) {
            for (int j = 0; j < twoN; j ++) {
                map[i][j] = newMap[i][j];
            }
        }





    }

    private static void rotate_unit(int y, int x, int size) {
        for(int i = 0 ; i <  size ; i++) {
            for (int j = 0; j <  size; j++) {
                newMap[y+j][x+size - i - 1] = map[y+i][x+j];
            }
        }

        /*System.out.println("after rotate unit");
        for(int i = y ; i < y + size ; i++) {
            for(int j = x ; j < x + size ; j++) {
                System.out.print(newMap[i][j] + " ");
            }
            System.out.println();
        }*/
    }

    private static class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}