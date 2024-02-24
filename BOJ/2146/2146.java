import java.awt.*;
import java.util.*;
import java.util.List;

public class Main {

    static int N, numIsland = 1;
    static int[][] map;
    static boolean[][] mapVisited;
    static int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static int result = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N][N];
        mapVisited = new boolean[N][N];


        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] == 1 && !mapVisited[i][j]){
                    numIsland++;
                    makeIsland(i, j, numIsland);
                }
            }
        }

        numIsland--;
        /*System.out.println(numIsland);
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
*/


        for(int i = 1 ; i <= numIsland; i++){
            bfs(i);
        }

        System.out.println(result);






    }

    private static void bfs(int n) {
        Queue<Point> queue = new LinkedList<>();

        int[][] dist = new int[N][N];
        boolean[][] visited = new boolean[N][N];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] == n){
                    queue.add(new Point(i, j));
                    visited[i][j] = true;
                }
            }
        }

        while(!queue.isEmpty()) {
            Point p = queue.poll();

            for (int i = 0; i < 4; i++) {
                int x = p.x + dir[i][0];
                int y = p.y + dir[i][1];

                if (x < 0 || x >= N || y < 0 || y >= N) continue;
                if (visited[x][y]) continue;

                if (map[x][y] == 0) {
                    dist[x][y] = dist[p.x][p.y] + 1;
                    visited[x][y] = true;
                    queue.add(new Point(x, y));
                } else if (map[x][y] != n) {
                    result = Math.min(result, dist[p.x][p.y]);
                }
            }
        }

    }

    private static void makeIsland(int i, int j, int n) {
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(i, j));

        map[i][j] = n-1;
        mapVisited[i][j] = true;

        while(!queue.isEmpty()){
            Point p = queue.poll();
            int x = p.x;
            int y = p.y;

            if(x-1 >= 0 && map[x-1][y] == 1 && !mapVisited[x-1][y]){
                map[x-1][y] = n-1;
                mapVisited[x-1][y] = true;
                queue.add(new Point(x-1, y));
            }
            if(x+1 < N && map[x+1][y] == 1 && !mapVisited[x+1][y]){
                map[x+1][y] = n-1;
                mapVisited[x+1][y] = true;
                queue.add(new Point(x+1, y));
            }
            if(y-1 >= 0 && map[x][y-1] == 1 && !mapVisited[x][y-1]){
                map[x][y-1] = n-1;
                mapVisited[x][y-1] = true;
                queue.add(new Point(x, y-1));
            }
            if(y+1 < N && map[x][y+1] == 1 && !mapVisited[x][y+1]){
                map[x][y+1] = n-1;
                mapVisited[x][y+1] = true;
                queue.add(new Point(x, y+1));
            }
        }
    }


}
