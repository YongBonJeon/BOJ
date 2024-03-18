import java.util.*;

public class Main {
    static int N, M, fuel, taxi_y, taxi_x, cur_client;
    static int[][] map, dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    static int[][] client, target;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        fuel = sc.nextInt();
        map = new int[N+1][N+1];
        client = new int[M+1][3];
        target = new int[M+1][2];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        taxi_y = sc.nextInt();
        taxi_x = sc.nextInt();

        for(int i = 1 ; i <= M ; i++) {
            client[i][0] = sc.nextInt();
            client[i][1] = sc.nextInt();
            client[i][2] = 1;

            target[i][0] = sc.nextInt();
            target[i][1] = sc.nextInt();
        }

        for(int i = 0 ; i < M ; i++) {

            // 최단거리 손님 찾고 이동
            if(!moveToClient()) {
                System.out.println(-1);
                return ;
            }

            // 손님 목적지까지 이동
            if(!moveToDestination()){
                System.out.println(-1);
                return ;
            }
        }
        System.out.println(fuel);

    }

    private static boolean moveToDestination() {
        int[][] visited = new int[N+1][N+1];
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(taxi_y, taxi_x));
        visited[taxi_y][taxi_x] = 1;

        while (!q.isEmpty()) {
            Pair cur = q.poll();

            for(int d = 0 ; d < 4 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

                if(visited[ny][nx] == 0 && map[ny][nx] != 1) {
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    q.add(new Pair(ny, nx));
                }
            }
        }

        int dist = visited[target[cur_client][0]][target[cur_client][1]] - 1;

        if(dist > fuel) return false;

        fuel += dist;
        taxi_y = target[cur_client][0];
        taxi_x = target[cur_client][1];

        /*System.out.println("after moveToTarget");
        System.out.println("taxi " + taxi_y + " " + taxi_x);
        System.out.println("min_dist = " + dist);
        System.out.println("fuel = " + fuel);*/

        return true;
    }

    private static boolean moveToClient() {
        int[][] visited = new int[N+1][N+1];
        int client_y = N, client_x = N, min_dist = Integer.MAX_VALUE;
        calculate(visited);

        for(int i = 1 ; i <= M ; i++) {
            if(client[i][2] == 0) continue;

            if(min_dist > visited[client[i][0]][client[i][1]]) {
                min_dist = visited[client[i][0]][client[i][1]];
                client_y = client[i][0];
                client_x = client[i][1];
                cur_client = i;
            } else if(min_dist == visited[client[i][0]][client[i][1]]) {
                if(client_y > client[i][0]) {
                    client_y = client[i][0];
                    client_x = client[i][1];
                    cur_client = i;
                } else if(client_y == client[i][0]) {
                    if(client_x > client[i][1]) {
                        client_y = client[i][0];
                        client_x = client[i][1];
                        cur_client = i;
                    }
                }
            }
        }
        if(min_dist == 0) return false;
        min_dist --;
        if(min_dist > fuel) return false;

        fuel -= min_dist;
        client[cur_client][2] = 0;
        taxi_y = client_y;
        taxi_x = client_x;

        /*System.out.println("after moveToClient");
        System.out.println("taxi " + taxi_y + " " + taxi_x);
        System.out.println("min_dist = " + min_dist);
        System.out.println("fuel = " + fuel);*/
        return true;
    }

    private static void calculate(int[][] visited) {
        Queue<Pair> q = new ArrayDeque<>();
        visited[taxi_y][taxi_x] = 1;
        q.add(new Pair(taxi_y, taxi_x));

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            for(int d = 0 ; d < 4 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny < 1 || nx < 1 || ny > N || nx > N) continue;

                if(visited[ny][nx] == 0 && map[ny][nx] != 1) {
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    q.add(new Pair(ny, nx));
                }
            }
        }
    }

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}