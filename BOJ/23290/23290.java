import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int[][] fish_dead = new int[4][4];
    static Fish[][] fishes = new Fish[4][4];
    static int[][] dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
            {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    static List<F> fs = new ArrayList<>();

    static int num_fishes, num_order, shark_x, shark_y;

    static class Fish {
        int num;
        int[] dir = new int[9];
    }

    static class F {
        int x;
        int y;
        int dir;

        public F(int x, int y, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }

    static class FF {
        int x, nx;
        int y, ny;
        int d, nd;

        public FF(int x, int y, int nx, int ny, int d, int nd) {
            this.y = y;
            this.ny = ny;
            this.x = x;
            this.nx = nx;
            this.d = d;
            this.nd = nd;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        num_fishes = sc.nextInt();
        num_order = sc.nextInt();

        for(int i = 0 ; i < 4 ; i++)
            for (int j = 0; j < 4; j++)
                fishes[i][j] = new Fish();

        int xx, yy, dd;
        for(int i = 0; i < num_fishes ; i++) {
            xx = sc.nextInt();
            yy = sc.nextInt();
            dd = sc.nextInt();

            fishes[xx-1][yy-1].num++;
            fishes[xx-1][yy-1].dir[dd - 1]++;
        }

        shark_x = sc.nextInt()-1;
        shark_y = sc.nextInt()-1;

        //debug0();

        for(int od = 0 ; od < num_order ; od++) {

            // 복제 시도
            try_copy();

            //debug1();

            // 물고기 이동
            move_fishes();

            //debug2();

            // 상어 이동
            move_shark();

            // 수명이 다 된 물고기 냄새 삭제
            delete_deadFishes();

            // 복제 성공
            success_copy();
        }

        int answer = 0;
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                answer += fishes[i][j].num;
            }
        }
        System.out.println(answer);
    }

    private static void debug5() {
        System.out.println("debug5");
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                System.out.print(fishes[i][j].num + " ");
            }
            System.out.println();
        }
    }

    private static void debug4() {
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                System.out.print(fish_dead[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void debug2() {
        System.out.println("debug2");
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                System.out.print(fishes[i][j].num + " ");
            }
            System.out.println();
        }
    }

    private static void debug1() {
        System.out.println("debug1");
        for (F f : fs) {
            System.out.println(f.x + " " + f.y + " " + f.dir);
        }
    }

    private static void debug0() {
        System.out.println("debug0");
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                System.out.print(fishes[i][j].num + " ");
            }
            System.out.println();
        }
    }



    private static void delete_deadFishes() {
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                fish_dead[i][j]--;
            }
        }
    }

    private static void try_copy() {
        fs = new ArrayList<>();

        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                for (int d = 0; d < 8; d++) {
                    for (int n = 0; n < fishes[i][j].dir[d]; n++) {
                        fs.add(new F(i, j, d));
                    }
                }
            }
        }
    }
    private static void success_copy() {
        for (F f : fs) {
            fishes[f.x][f.y].num++;
            fishes[f.x][f.y].dir[f.dir]++;
        }
    }

    private static void move_shark() {
        int[][] d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        StringBuilder path = new StringBuilder();

        int final_num = 0;
        String final_path = "333";

        int num = 0;
        int x = shark_x, y = shark_y;

        for(int i = 0 ; i < 4 ; i++) {
            if(x + d[i][0] < 0 || y + d[i][1] < 0 || x + d[i][0] >= 4 || y + d[i][1]>= 4) continue;
            path.append(i);
            x += d[i][0]; y += d[i][1];
            int curi = fishes[x][y].num;
            fishes[x][y].num = 0;
            num += curi;
            for(int j = 0 ; j < 4 ; j++) {
                if(x + d[j][0] < 0 || y + d[j][1] < 0 || x + d[j][0] >= 4 || y + d[j][1]>= 4) continue;
                path.append(j);
                x += d[j][0]; y += d[j][1];
                int curj = fishes[x][y].num;
                fishes[x][y].num = 0;
                num += curj;
                for(int k = 0 ; k < 4 ; k++) {
                    if(x + d[k][0] < 0 || y + d[k][1] < 0 || x + d[k][0] >= 4 || y + d[k][1]>= 4) continue;
                    path.append(k);
                    x += d[k][0]; y += d[k][1];
                    int curk = fishes[x][y].num;
                    fishes[x][y].num = 0;
                    num += curk;

                    if(num > final_num) {
                        final_num = num;
                        final_path = path.toString();
                    } else if(num == final_num) {
                        if(path.toString().compareTo(final_path) < 0) {
                            final_path = path.toString();
                        }
                    }

                    path.deleteCharAt(2);
                    num -= curk;
                    fishes[x][y].num = curk;
                    x -= d[k][0]; y -= d[k][1];
                }
                path.deleteCharAt(1);
                num -= curj;
                fishes[x][y].num = curj;
                x -= d[j][0]; y -= d[j][1];
            }
            path.deleteCharAt(0);
            num -= curi;
            fishes[x][y].num = curi;
            x -= d[i][0]; y -= d[i][1];
        }

        for(int i = 0 ; i < 3 ; i++) {
            shark_x += d[final_path.charAt(i) - '0'][0];
            shark_y += d[final_path.charAt(i) - '0'][1];

            if(fishes[shark_x][shark_y].num > 0)
                fish_dead[shark_x][shark_y] = 3;

            fishes[shark_x][shark_y].num = 0;
            for(int n = 0 ; n < 8 ; n++) {
                fishes[shark_x][shark_y].dir[n] = 0;
            }
        }
    }

    private static void move_fishes() {
        Fish[][] new_fishes = new Fish[4][4];
        for(int i = 0 ; i < 4 ; i++)
            for(int j = 0 ; j < 4 ; j++) {
                new_fishes[i][j] = new Fish();
                new_fishes[i][j].num = fishes[i][j].num;
                new_fishes[i][j].dir = Arrays.copyOf(fishes[i][j].dir, 8);
            }

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if(fishes[x][y].num == 0) continue;
                for(int d = 0; d < 8 ; d++) {
                    if(fishes[x][y].dir[d] == 0) continue;
                    for (int nd = d + 8; nd > d; nd--) {
                        int nx = x + dir[nd % 8][0];
                        int ny = y + dir[nd % 8][1];

                        // 격자 바깥 이동 불가
                        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
                            continue;
                        }
                        // 상어가 있는 칸 이동 불가
                        if (nx == shark_x && ny == shark_y) {
                            continue;
                        }
                        // 물고기 냄새가 있는 칸 이동 불가
                        if (fish_dead[nx][ny] > 0) {
                            continue;
                        }


                        new_fishes[nx][ny].dir[nd % 8] += fishes[x][y].dir[d];
                        new_fishes[nx][ny].num += fishes[x][y].dir[d];
                        new_fishes[x][y].num -= fishes[x][y].dir[d];
                        new_fishes[x][y].dir[d] -= fishes[x][y].dir[d];

                        break;
                    }
                }
            }
        }
        for(int i = 0 ; i < 4 ; i++)
            for(int j = 0 ; j < 4 ; j++) {
                fishes[i][j].num = new_fishes[i][j].num;
                for(int k = 0 ; k < 8 ; k++)
                    fishes[i][j].dir[k] = new_fishes[i][j].dir[k];
            }
    }
}