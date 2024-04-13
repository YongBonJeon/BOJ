import java.util.*;

public class Main {
    static int N, M, K, score = 0;
    static int[][] map;
    static boolean[][] dirmap;
    static int[][] move_map;
    static int[][] dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        map = new int[N][N];

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        int time = 0;
        while(time < K) {
            //System.out.println("time " + time);
            move_teams();

            //System.out.println("after move teams");
            //print_map();

            throw_ball(time);
            //System.out.println("after throw ball");
            //print_map();

            //System.out.println("score : " + score);

            time++;
        }

        System.out.println(score);
    }

    private static void throw_ball(int time) {
        time = time % (N*4);
        if(time >= 0 && time < N) {
            //System.out.println(time);
            for(int i = 0 ; i < N ; i++) {
                //System.out.println("i : " + time + " j : " + i);
                if(map[time][i] > 0 && map[time][i] != 4) {
                    //System.out.println("i : " + time + " j : " + i);
                    int s = distance(time, i);
                    //System.out.println("s : " + s);
                    score += s*s;
                    dirmap = new boolean[N][N];
                    change_dir(time, i);
                    return ;
                }
            }
        } else if(time >= N && time < N*2) {
            //System.out.println(time-N);
            for(int i = N-1 ; i >= 0 ; i--) {
                //System.out.println("i : " + i + " j : " + (time-N));
                if(map[i][time-N] > 0 && map[i][time-N] != 4) {
                    //System.out.println("i : " + i + " j : " + (time-N));
                    int s = distance(i, time-N);
                    //System.out.println("s : " + s);
                    score += s*s;
                    dirmap = new boolean[N][N];
                    change_dir(i, time-N);
                    return ;
                }
            }
        } else if(time >= N*2 && time < N*3) {
            //System.out.println((N-1)-(time-N*2));
            for(int i = N-1 ; i >= 0 ; i--) {
                //System.out.println("i : " + ((N-1)-(time-N*2)) + " j : " + i);
                if(map[(N-1)-(time-N*2)][i] > 0 && map[(N-1)-(time-N*2)][i] != 4) {
                    //System.out.println("i : " + ((N-1)-(time-N*2)) + " j : " + i);
                    int s = distance((N-1)-(time-N*2), i);
                    //System.out.println("s : " + s);
                    score += s*s;
                    dirmap = new boolean[N][N];
                    change_dir((N-1)-(time-N*2), i);
                    return ;
                }
            }
        } else if(time >= N*3 && time < N*4) {
            //System.out.println((N-1)-(time-N*3));
            for(int i = 0 ; i < N ; i++) {
                //System.out.println("i : " + i + " j : " + ((N-1)-(time-N*3)));
                if(map[i][(N-1)-(time-N*3)] > 0 && map[i][(N-1)-(time-N*3)] != 4) {
                    //System.out.println("i : " + i + " j : " + ((N-1)-(time-N*3)));
                    int s = distance(i, (N-1)-(time-N*3));
                    //System.out.println("s : " + s);
                    score += s*s;
                    dirmap = new boolean[N][N];
                    change_dir(i, (N-1)-(time-N*3));
                    return ;
                }
            }

        }
    }

    private static void change_dir(int y, int x) {
        dirmap[y][x] = true;
        if(map[y][x] == 3) map[y][x] = 1;
        else if(map[y][x] == 1) map[y][x] = 3;

        for(int d = 0 ; d < 4 ; d++) {
            int ny = y + dir[d][0];
            int nx = x + dir[d][1];

            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

            if(!dirmap[ny][nx] && map[ny][nx] > 0 && map[ny][nx] < 4)
                change_dir(ny, nx);
        }
    }

    private static int distance(int y, int x) {
        int[][] visited = new int[N][N];
        Queue<Pair> q = new ArrayDeque<>();

        visited[y][x] = 1;
        q.add(new Pair(y, x));

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            if(map[cur.y][cur.x] == 1) return visited[cur.y][cur.x];

            for(int d = 0 ; d < 4 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                if(cur.y == y && cur.x == x && map[cur.y][cur.x] == 3 && map[ny][nx] == 1) continue;


                if(visited[ny][nx] == 0 && map[ny][nx] > 0 && map[ny][nx] < 3) {
                    q.add(new Pair(ny, nx));
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                }

            }
        }
        return 0;
    }

    private static void move_teams() {
        List<Pair> starts = new ArrayList<>();
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(map[i][j] == 1)
                    starts.add(new Pair(i, j));
            }
        }

        for(Pair st : starts) {
            int i = st.y;
            int j = st.x;
            if(map[i][j] == 1) {
                int ny, nx;
                for(int d = 0 ; d < 4 ; d++) {
                    ny = i + dir[d][0];
                    nx = j + dir[d][1];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                    if(map[ny][nx] == 3 || map[ny][nx] == 4) {
                        move_team(i, j, ny, nx, 0, false);
                        break;
                    }
                }
            }
        }
    }

    private static void move_team(int y , int x, int ny, int nx, int depth, boolean cycle) {
        if(depth == 0) {
            if(map[ny][nx] == 3)
                cycle = true;
        }
        if(map[y][x] == 1 && depth != 0) {
            if(cycle)
                map[ny][nx] = 3;
            else
                map[ny][nx] = 4;
            return ;
        }
        map[ny][nx] = map[y][x];
        if(map[y][x] == 4) {
            return ;
        }

        for(int d = 0 ; d < 4 ; d++) {
            int cy = y + dir[d][0];
            int cx = x + dir[d][1];

            if(cy < 0 || cx < 0 || cy >= N || cx >= N) continue;

            if(map[cy][cx] > 0 && !(cy == ny && cx == nx)) {
                move_team(cy, cx, y, x, depth+1, cycle);
                break;
            }
        }
    }

    private static void print_map() {
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}