import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;

    static class node {
        int x, y, dir;

        public node() {
        }

        node(int x, int y, int dir){
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N+1][M+1];
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                map[i][j] = sc.nextInt();
            }
        }
        int y = sc.nextInt();
        int x = sc.nextInt();
        int dir = sc.nextInt();
        node start = new node(x, y, dir);

        y = sc.nextInt();
        x = sc.nextInt();
        dir = sc.nextInt();
        node end = new node(x, y, dir);

        System.out.println(bfs(start, end));
    }

    private static int bfs(node start, node end) {
        Queue<node> q = new LinkedList<>();
        int[][][] visited = new int[N+1][M+1][5];

        // 동 서 남 북
        int[] dx = {0, 1, -1, 0, 0};
        int[] dy = {0, 0, 0, 1, -1};
        q.add(start);
        visited[start.y][start.x][start.dir] = 1;

        while(!q.isEmpty()){
            node cur = q.poll();
            /*System.out.println("cur.y: " + cur.y + " cur.x: " + cur.x + " cur.dir: " + cur.dir);
            System.out.println("visited[cur.y][cur.x][cur.dir]: " + visited[cur.y][cur.x][cur.dir]);*/
            if(cur.x == end.x && cur.y == end.y && cur.dir == end.dir){
                return visited[cur.y][cur.x][cur.dir] - 1;
            }

            // 1. Go k
            for(int k=1; k<=3; k++){
                int nx = cur.x + dx[cur.dir] * k;
                int ny = cur.y + dy[cur.dir] * k;

                if(nx < 1 || ny < 1 || nx > M || ny > N) break;
                if(map[ny][nx] == 1) break;

                if(visited[ny][nx][cur.dir] != 0) continue;
                visited[ny][nx][cur.dir] = visited[cur.y][cur.x][cur.dir] + 1;
                q.add(new node(nx, ny, cur.dir));
            }

            // 2. Turn left
            int next_dir = next_left(cur.dir);
            if(visited[cur.y][cur.x][next_dir] == 0){
                visited[cur.y][cur.x][next_dir] = visited[cur.y][cur.x][cur.dir] + 1;
                q.add(new node(cur.x, cur.y, next_dir));
            }

            // 3. Turn right
            next_dir = next_right(cur.dir);
            if(visited[cur.y][cur.x][next_dir] == 0){
                visited[cur.y][cur.x][next_dir] = visited[cur.y][cur.x][cur.dir] + 1;
                q.add(new node(cur.x, cur.y, next_dir));
            }
        }
        return -1;
    }

    private static int next_left(int dir) {
        if(dir == 1) return 4;
        else if(dir == 2) return 3;
        else if(dir == 3) return 1;
        else return 2;
    }

    private static int next_right(int dir) {
        if(dir == 1) return 3;
        else if(dir == 2) return 4;
        else if(dir == 3) return 2;
        else return 1;
    }
}