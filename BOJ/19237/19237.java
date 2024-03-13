import java.util.Scanner;

public class Main {
    static int N, M, K;
    static int[][] map;
    static Smell[][] smell_map;
    static int dir[][] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 상어 번호 / 현재 방향 / 각 방향
    static int[][][] shark_dir;
    static Shark[] sharks;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        map = new int[N + 1][N + 1];
        smell_map = new Smell[N + 1][N + 1];
        for(int i =  1; i <= N ; i++)
            for (int j = 1; j <= N; j++)
                smell_map[i][j] = new Smell(0, 0);

        shark_dir = new int[M+1][5][5];
        sharks = new Shark[M+1];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = sc.nextInt();
                if(map[i][j] > 0) {
                    sharks[map[i][j]] = new Shark(i, j, 0);
                    smell_map[i][j].shark_num = map[i][j];
                    smell_map[i][j].life = K;
                }
            }
        }
        for(int i = 1 ; i <= M ; i++) {
            sharks[i].dir = sc.nextInt();
        }

        for(int shark_num = 1 ; shark_num <= M ; shark_num++) {
            for(int dir = 1 ; dir <= 4 ; dir++) {
                for(int i = 1 ; i <= 4 ; i++) {
                    shark_dir[shark_num][dir][i] = sc.nextInt();
                }
            }
        }

        int sec = 0;

        while(sec <= 1000) {
            //System.out.println("before shark move");
            //print_shark_map();
            // 상어 이동하기
            move_shark();

            //System.out.println("after shark move");
            //print_shark_map();

            // 상어 삭제
            remove_shark();

            //System.out.println("after shark remove");
            //print_shark_map();

            // 냄새 수명 낮추기
            minus_smell();

            // 냄새 뿌리기
            spray_smell();
            //System.out.println("after smell");
            //print_smell_map();

            sec++;
            if (check_end()) {
                break;
            }
        }
        if(sec == 1001)
            System.out.println(-1);
        else
            System.out.println(sec);
    }

    private static boolean check_end() {
        int allExit = 0;

        for (int shark_num = 2; shark_num <= M; shark_num++) {
            if(sharks[shark_num].isExit)
                allExit++;
        }
        return allExit == M-1;
    }

    private static void minus_smell() {
        for(int i = 1 ; i <= N ;i++) {
            for (int j = 1; j <= N; j++) {
                smell_map[i][j].life = Math.max(smell_map[i][j].life - 1, 0);
                if(smell_map[i][j].life == 0)
                    smell_map[i][j].shark_num = 0;
            }
        }
    }

    private static void print_shark_map() {
        char[] dirp = {'X', '↑', '↓', '←', '→'};
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(map[i][j] > 0)
                    System.out.print(map[i][j] + " " + dirp[sharks[map[i][j]].dir] + " ");
                else
                    System.out.print(map[i][j] + " X ");
            }
            System.out.println();
        }
    }

    private static void print_smell_map() {
        System.out.println("print_smell_map");
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                System.out.print(smell_map[i][j].shark_num + "/" + smell_map[i][j].life + " ");
            }
            System.out.println();
        }
    }

    private static void remove_shark() {
        for(int i = 1 ; i <= M ; i++) {
            if(sharks[i].isExit) continue;
            for (int j = i + 1; j <= M; j++) {
                if(sharks[j].isExit) continue;
                if(sharks[i].y == sharks[j].y && sharks[i].x == sharks[j].x) {
                    sharks[j].isExit = true;
                }
            }
            map[sharks[i].y][sharks[i].x] = i;
        }
    }

    private static void spray_smell() {
        for (int shark_num = 1; shark_num <= M; shark_num++) {
            if(sharks[shark_num].isExit) continue;
            int y = sharks[shark_num].y;
            int x = sharks[shark_num].x;

            smell_map[y][x] = new Smell(shark_num, K);
        }
    }

    private static void move_shark() {
        for (int shark_num = 1; shark_num <= M; shark_num++) {
            if(sharks[shark_num].isExit) continue;
            /*System.out.println("shark_num = " + shark_num);
            System.out.println("sharks[shark_num].dir = " + sharks[shark_num].dir);*/
            int[] cur_dir = shark_dir[shark_num][sharks[shark_num].dir];
            /*for(int i = 1 ; i <= 4 ; i++)
                System.out.print(cur_dir[i] + " ");*/
            int y = sharks[shark_num].y, ny = 0;
            int x = sharks[shark_num].x, nx = 0;

            boolean isMoved = false;
            // 아무 냄새 없는 곳 우선
            for(int i = 1 ; i <= 4 ; i++) {
                ny = y + dir[cur_dir[i]][0];
                nx = x + dir[cur_dir[i]][1];

                if(ny < 1 || nx < 1 || ny > N || nx > N) continue;
                if(smell_map[ny][nx].life > 0) continue;

                // 이동
                isMoved = true;
                sharks[shark_num].y = ny;
                sharks[shark_num].x = nx;
                sharks[shark_num].dir = cur_dir[i];

                map[ny][nx] = shark_num;
                map[y][x] = 0;
                /*System.out.println();
                System.out.println(y + " " + x + " -> " + ny + " " + nx);*/
                break;
            }

            // 자신의 냄새가 있는 곳 이동
            if(!isMoved) {
                for(int i = 1 ; i <= 4 ; i++) {
                    ny = y + dir[cur_dir[i]][0];
                    nx = x + dir[cur_dir[i]][1];

                    if(ny < 1 || nx < 1 || ny > N || nx > N) continue;
                    if(smell_map[ny][nx].shark_num != shark_num) continue;

                    // 이동
                    sharks[shark_num].y = ny;
                    sharks[shark_num].x = nx;
                    sharks[shark_num].dir = cur_dir[i];

                    map[ny][nx] = shark_num;
                    map[y][x] = 0;

                    break;
                }
            }
        }

    }

    private static class Smell {
        int shark_num;
        int life;

        public Smell(int shark_num, int life) {
            this.shark_num = shark_num;
            this.life = life;
        }

    }

    private static class Shark {
        int y, x, dir;
        boolean isExit = false;

        public Shark(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }
}