import java.util.*;

public class Main {
    static int N, M, H, K;
    static int sul_y, sul_x, sul_dir, score;
    static boolean reverse = false;
    static Runner[] runners;
    static int[][] map;
    static int[][] trees;
    static int[][] dir = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};

    static class Runner {
        int y, x;
        int dir;
        boolean dead = false;

        Runner(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        H = sc.nextInt();
        K = sc.nextInt();

        map = new int[N+1][N+1];
        sul_y = N/2+1;
        sul_x = N/2+1;
        sul_dir = 0;
        map[sul_y][sul_x] = 1;

        // 도망자 M명 정보
        runners = new Runner[M+1];
        for(int i = 1 ; i <= M ; i++) {
            int y = sc.nextInt();
            int x = sc.nextInt();
            int strict = sc.nextInt();
            if(strict == 1)
                runners[i] = new Runner(y, x, 1);
            else if(strict == 2)
                runners[i] = new Runner(y, x, 2);
        }

        // 나무 H개 정보
        trees = new int[N+1][N+1];
        for(int i = 1 ; i <= H ; i++) {
            trees[sc.nextInt()][sc.nextInt()] = 1;
        }

        int time = 1;
        while(time <= K) {
            // 도망자 이동
            move_runners();

            // 술래 이동
            move_sul(time);
            //System.out.println("술래 위치 " + sul_y + " " + sul_x);
            time++;
        }
        System.out.println(score);
    }

    private static void move_runners() {
        for(int i = 1 ; i <= M ; i++) {
            if(distance(i) > 3 || runners[i].dead) continue;

            int d = runners[i].dir;
            int ny = runners[i].y + dir[d][0];
            int nx = runners[i].x + dir[d][1];

            // 격자 벗어나는 경우
            if(ny < 1 || nx < 1 || ny > N || nx > N) {
                d = (d+2) % 4;
                ny = runners[i].y + dir[d][0];
                nx = runners[i].x + dir[d][1];

                if(ny == sul_y && nx == sul_x) continue;

                runners[i].y = ny;
                runners[i].x = nx;
                runners[i].dir = d;
            }
            // 격자를 벗어나지 않는 경우
            else {
                if(ny == sul_y && nx == sul_x) continue;
                runners[i].y = ny;
                runners[i].x = nx;
            }
        }
    }

    private static void move_sul(int time) {
        sul_y += dir[sul_dir][0];
        sul_x += dir[sul_dir][1];
        map[sul_y][sul_x] = 1;

        if(sul_y == 1 && sul_x == 1) {
            reverse = !reverse;
            map = new int[N+1][N+1];
            map[sul_y][sul_x] = 1;
            sul_dir = 2;
        } else if(sul_y == N/2+1 && sul_x == N/2+1) {
            reverse = !reverse;
            map = new int[N+1][N+1];
            map[sul_y][sul_x] = 1;
            sul_dir = 0;
        }
        else if(!reverse) {
            int ny = sul_y + dir[(sul_dir+1) % 4][0];
            int nx = sul_x + dir[(sul_dir+1) % 4][1];

            if(map[ny][nx] == 0) {
                sul_dir = (sul_dir + 1) % 4;
            }
        } else if(reverse){
            int ny = sul_y + dir[sul_dir][0];
            int nx = sul_x + dir[sul_dir][1];

            if(ny < 1 || nx < 1 || ny > N || nx > N || map[ny][nx] == 1) {
                sul_dir = (sul_dir + 3) % 4;
            }
        }

        for(int i = 0 ; i <= 2 ; i++) {
            int catch_y = sul_y + dir[sul_dir][0]*i;
            int catch_x = sul_x + dir[sul_dir][1]*i;

            for(int r = 1 ; r <= M ; r++) {
                if(runners[r].dead) continue;
                if(runners[r].y == catch_y && runners[r].x == catch_x) {
                    if(trees[catch_y][catch_x] == 0) {
                        score += time;
                        runners[r].dead = true;
                    }
                }
            }
        }
    }

    private static int distance(int num) {
        return Math.abs(sul_y - runners[num].y) + Math.abs(sul_x - runners[num].x);
    }
}