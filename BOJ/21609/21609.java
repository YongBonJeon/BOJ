import java.util.*;

public class Main {
    static int N, M, score = 0;
    static int[][] map, dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    static int[][] visited;
    static int maxSize = 0, maxRainbow = 0, criterion_y = 0, criterion_x = 0, maxIdx = 0;
    static List<Pair> rainbows;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N+1][N+1];
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }


        while(findMaxGroup()) {
            // 크기가 가장 큰 블록 그룹 찾고 점수 획득
            // 중력 작용
            gravity();

            // 반시계 방향 회전
            rotate();

            gravity();
        }
        System.out.println(score);
    }

    private static void rotate() {
        int[][] newMap = new int[N+1][N+1];
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                newMap[N+1-j][i] = map[i][j];
            }
        }
        // 1 1 -> 6 1 , 1 2 -> 5 1

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = newMap[i][j];
            }
        }

        /*System.out.println("after rotate");
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = newMap[i][j];
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }*/
    }

    private static void gravity() {
        int[][] newMap = new int[N+1][N+1];
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                newMap[i][j] = map[i][j];
            }
        }
        for(int i = N-1 ; i >= 1 ; i--) {
            for(int j = 1 ; j <= N ; j++) {
                if(map[i][j] == -2 || map[i][j] == -1) continue;

                int k = 1;
                while(i+k <= N && map[i+k][j] == -2) {
                    k++;
                }
                if(k != 1) {
                    map[i+k-1][j] = map[i][j];
                    map[i][j] = -2;
                }
            }
        }

        /*System.out.println("after gravity");
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }*/
    }

    private static boolean findMaxGroup() {
        maxSize = 0; maxRainbow = 0; criterion_y = N; criterion_x = N;
        rainbows = new ArrayList<>();
        visited = new int[N+1][N+1];
        int idx = 1;
        maxIdx = 1;
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(visited[i][j] == 0 && map[i][j] > 0) {
                    bfs(i, j, idx++);
                }
            }
        }

        if(maxSize < 2) return false;

        // 삭제
        delete(criterion_y, criterion_x);

        /*System.out.println("after delete");
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }*/

        score += maxSize * maxSize;

        return true;
    }

    private static void delete(int i, int j) {
        boolean[][] v = new boolean[N+1][N+1];
        int color = map[i][j];

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(i,j));
        v[i][j] = true;
        map[i][j] = -2;

        while (!q.isEmpty()) {
            Pair cur = q.poll();

            for(int d = 0 ; d < 4 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny < 1 || nx < 1 || ny > N || nx > N) continue;

                if(!v[ny][nx] && (map[ny][nx] == 0 || map[ny][nx] == color)) {
                    v[ny][nx] = true;
                    map[ny][nx] = -2;
                    q.add(new Pair(ny, nx));
                }
            }
        }
    }

    private static void bfs(int i, int j, int idx) {
        int size = 0, rainbow = 0, local_y = i, local_x = j;
        int color = map[i][j];

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(i,j));
        visited[i][j] = idx;
        size ++;

        while (!q.isEmpty()) {
            Pair cur = q.poll();

            for(int d = 0 ; d < 4 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny < 1 || nx < 1 || ny > N || nx > N) continue;

                if(visited[ny][nx] == 0 && (map[ny][nx] == 0 || map[ny][nx] == color)) {
                    if(map[ny][nx] == 0) {
                        rainbow++;
                    }
                    visited[ny][nx] = idx;
                    size++;
                    q.add(new Pair(ny, nx));
                }
            }
        }

        if(size < 2) return ;

        if(size > maxSize) {
            maxSize = size;
            maxRainbow = rainbow;
            criterion_y = local_y;
            criterion_x = local_x;
            maxIdx = idx;
            //rainbows = new ArrayList<>(local_rainbows);
        } else if(size == maxSize) {
            if(rainbow > maxRainbow) {
                maxRainbow = rainbow;
                criterion_y = local_y;
                criterion_x = local_x;
                maxIdx = idx;
                //rainbows = new ArrayList<>(local_rainbows);
            } else if(rainbow == maxRainbow) {
                if(local_y > criterion_y) {
                    criterion_y = local_y;
                    criterion_x = local_x;
                    maxIdx = idx;
                    //rainbows = new ArrayList<>(local_rainbows);
                } else if(local_y == criterion_y) {
                    if(local_x > criterion_x) {
                        criterion_x = local_x;
                        maxIdx = idx;
                        //rainbows = new ArrayList<>(local_rainbows);
                    }
                }
            }
        }
        for(int p = 1 ; p <= N ; p++)
            for(int r = 1 ; r <= N ; r++)
                if(map[p][r] == 0) visited[p][r] = 0;
    }

    private static class Pair {
        int y, x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}