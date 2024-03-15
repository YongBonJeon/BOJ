import java.util.Scanner;

public class Main {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int tornado_y, tornado_x, tornado_dir;
    static int[][] dir = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N+1][N+1];
        visited = new boolean[N+1][N+1];
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        tornado_y = N/2+1;
        tornado_x = N/2+1;
        tornado_dir = 0;

        int ans = 0;
        while(!(tornado_x == 1 && tornado_y == 1)) {
            //System.out.println("tornado " + tornado_y + " " + tornado_x);
            visited[tornado_y][tornado_x] = true;
            int ny, nx, ay, ax;
            if (!visited[tornado_y + dir[(tornado_dir + 1) % 4][0]][tornado_x + dir[(tornado_dir + 1) % 4][1]] && !(tornado_y == N/2+1 && tornado_x == N/2+1)) {
                tornado_dir = (tornado_dir + 1) % 4;
            }
            ny = tornado_y + dir[tornado_dir][0];
            nx = tornado_x + dir[tornado_dir][1];
            ay = tornado_y + dir[tornado_dir][0]*2;
            ax = tornado_x + dir[tornado_dir][1]*2;
            /*System.out.println("tornado_dir = " + tornado_dir);
            System.out.println("nynx " + ny + " " + nx);
            System.out.println("ayax " + ay + " " + ax);*/

            // 모래 흩날리기
            int sand = map[ny][nx], rest = map[ny][nx];

            //if(sand == 0) continue;

            int sand_y, sand_x;
            // 왼쪽 7퍼
            sand_y = ny + dir[(tornado_dir+1)%4][0];
            sand_x = nx + dir[(tornado_dir+1)%4][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 7 / 100;
            } else
                map[sand_y][sand_x] += sand * 7 / 100;
            rest -= sand * 7 / 100;

            //System.out.println("왼쪽 7퍼 " + sand_y + " " + sand_x);

            // 오른쪽 7퍼
            sand_y = ny + dir[(tornado_dir+3)%4][0];
            sand_x = nx + dir[(tornado_dir+3)%4][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 7 / 100;
            } else
                map[sand_y][sand_x] += sand * 7 / 100;
            rest -= sand * 7 / 100;

            //System.out.println("오 7퍼 " + sand_y + " " + sand_x);

            // 왼쪽 2퍼
            sand_y = ny + dir[(tornado_dir+1)%4][0]*2;
            sand_x = nx + dir[(tornado_dir+1)%4][1]*2;

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 2 / 100;
            } else
                map[sand_y][sand_x] += sand * 2 / 100;
            rest -= sand * 2 / 100;

            //System.out.println("왼 2퍼 " + sand_y + " " + sand_x);

            // 오른쪽 2퍼
            sand_y = ny + dir[(tornado_dir+3)%4][0]*2;
            sand_x = nx + dir[(tornado_dir+3)%4][1]*2;

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 2 / 100;
            } else
                map[sand_y][sand_x] += sand * 2 / 100;
            rest -= sand * 2 / 100;

            //System.out.println("오 2퍼 " + sand_y + " " + sand_x);

            // 왼쪽 1퍼
            sand_y = tornado_y + dir[(tornado_dir+1)%4][0];
            sand_x = tornado_x + dir[(tornado_dir+1)%4][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 1 / 100;
            } else
                map[sand_y][sand_x] += sand * 1 / 100;
            rest -= sand * 1 / 100;

            //System.out.println("왼 1퍼 " + sand_y + " " + sand_x);
            // 오른쪽 1퍼
            sand_y = tornado_y + dir[(tornado_dir+3)%4][0];
            sand_x = tornado_x + dir[(tornado_dir+3)%4][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 1 / 100;
            } else
                map[sand_y][sand_x] += sand * 1 / 100;
            rest -= sand * 1 / 100;

            //System.out.println("오 1퍼 " + sand_y + " " + sand_x);

            // 왼쪽 10퍼
            sand_y = ay + dir[(tornado_dir+1)%4][0];
            sand_x = ax + dir[(tornado_dir+1)%4][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 10 / 100;
            } else
                map[sand_y][sand_x] += sand * 10 / 100;
            rest -= sand * 10 / 100;
            //System.out.println("왼 10퍼 " + sand_y + " " + sand_x);

            // 오른쪽 10퍼
            sand_y = ay + dir[(tornado_dir+3)%4][0];
            sand_x = ax + dir[(tornado_dir+3)%4][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 10 / 100;
            } else
                map[sand_y][sand_x] += sand * 10 / 100;
            rest -= sand * 10 / 100;

            //System.out.println("오 10퍼 " + sand_y + " " + sand_x);

            // 앞 5퍼
            sand_y = ay + dir[tornado_dir][0];
            sand_x = ax + dir[tornado_dir][1];

            if(sand_y < 1 || sand_x < 1 || sand_y > N || sand_x > N) {
                ans += sand * 5 / 100;
            } else
                map[sand_y][sand_x] += sand * 5 / 100;
            rest -= sand * 5 / 100;

            //System.out.println("앞 5퍼 " + sand_y + " " + sand_x);

            if(ay < 1 || ax < 1 || ay > N || ax > N)
                ans += rest;
            else
                map[ay][ax] += rest;

            map[ny][nx] = 0;
            tornado_y = ny;
            tornado_x = nx;

            /*for(int i = 1 ; i <= N ; i++) {
                for(int j = 1 ; j <= N ; j++)
                    System.out.print(map[i][j] + " ");
                System.out.println();
            }
            System.out.println();*/
        }
        System.out.println(ans);
    }
}