import java.util.*;
public class Main {
    static int N, M;
    static int[][] map;
    static boolean[][] cloud;
    static int[][] move;
    static int[][] dir = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    static int[][] diagonal = {{0, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N+1][N+1];
        cloud = new boolean[N+1][N+1];
        move = new int[M+1][2];

        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                map[i][j] = sc.nextInt();
        for(int i = 1 ; i <= M ; i++) {
            move[i][0] = sc.nextInt();
            move[i][1] = sc.nextInt();
        }

        // 초기 구름 생성
        cloud[N][1] = true;
        cloud[N][2] = true;
        cloud[N-1][1] = true;
        cloud[N-1][2] = true;

        for(int i = 1 ; i <= M ; i++) {
            // 구름 이동
            move_cloud(i);

            //System.out.println("after move cloud");
            //print();

            // 비내리기
            rain();

            //System.out.println("after rain");
            //print();

            // 물복사버그
            watercopybug();

            //System.out.println("after copybug");
            //print();

            // 구름 생성
            make_cloud();

            //System.out.println("after make cloud");
            //print();
        }

        int answer = 0;
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                answer += map[i][j];
        System.out.println(answer);
    }

    private static void print() {
        System.out.println("cloud");
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                System.out.print(cloud[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("map");
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void make_cloud() {
        boolean[][] new_cloud = new boolean[N+1][N+1];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(map[i][j] >= 2 && !cloud[i][j]) {
                    map[i][j] -= 2;
                    new_cloud[i][j] = true;
                }
            }
        }

        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                cloud[i][j] = new_cloud[i][j];
    }

    private static void watercopybug() {
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++) {
                if(cloud[i][j]) {
                    int num = 0;
                    for(int d = 1 ; d <= 4 ; d++) {
                        int ny = i + diagonal[d][0];
                        int nx = j + diagonal[d][1];

                        if(ny < 1 || nx < 1 || ny > N || nx > N) continue;
                        if(map[ny][nx] > 0) num++;
                    }

                    map[i][j] += num;
                }
            }
    }

    private static void rain() {
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++) {
                if(cloud[i][j]) {
                    map[i][j]++;
                }
            }
    }

    private static void move_cloud(int o) {
        boolean[][] new_cloud = new boolean[N+1][N+1];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(cloud[i][j]) {
                    int ny = i + dir[move[o][0]][0]*move[o][1];
                    int nx = j + dir[move[o][0]][1]*move[o][1];

                    while(ny < 1) ny += N;
                    while(ny > N) ny -= N;
                    while(nx < 1) nx += N;
                    while(nx > N) nx -= N;

                    new_cloud[ny][nx] = true;
                }
            }
        }
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                cloud[i][j] = new_cloud[i][j];
    }
}