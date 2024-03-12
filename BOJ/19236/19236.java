import java.util.Scanner;

public class Main {
    static int[][] dir = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    static char[] dirp = {'↑', '↖', '←', '↙', '↓', '↘', '→', '↗'};
    static int max_ans = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] map = new int[4][4];
        Fish[] fishes = new Fish[17];
        fishes[0] = new Fish(-1,-1,-1);
        int num, dir;

        // 초기 물고기 상태
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                num = sc.nextInt();
                dir = sc.nextInt();

                map[i][j] = num;
                fishes[num] = new Fish(i, j, dir - 1);
            }
        }


        Pair next = copy(map, fishes);
        go_shark(0, 0, 0, next.arr, next.fs, 0);

        System.out.println(max_ans);

    }

    private static void go_shark(int shark_x, int shark_y, int sum, int[][] map, Fish[] fishes, int depth) {
        int nx, ny, num_fish, shark_dir;

        // 잡아먹기
        num_fish = map[shark_x][shark_y]; // 잡아먹은 물고기
        map[shark_x][shark_y] = 0;      // 물고기 맵에서 삭제
        shark_dir = fishes[num_fish].dir;   // 상어가 잡아먹은 물고기의 방향 획득
        fishes[num_fish].isDead = true;     // 물고기 사망 확인
        sum += num_fish;

        /*System.out.println("after_eat shark = " + " " + shark_x + " " + shark_y + " " + shark_dir);
        System.out.println("depth = " + depth);
        System.out.println("sum = " + sum);*/

        Pair newPair = move_fishes(shark_x, shark_y, map, fishes);
        Pair next;
        for(int i = 1 ; i <= 3 ; i++) {
            nx = shark_x + dir[shark_dir][0]*i;
            ny = shark_y + dir[shark_dir][1]*i;

            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if(newPair.arr[nx][ny] == 0) continue;

            next = null;
            next = copy(newPair.arr, newPair.fs);

            /*System.out.println("depth = " + depth);*/
            //print_map_detail(next.arr, next.fs);
            go_shark(nx, ny, sum, next.arr, next.fs, depth + 1);
        }
        max_ans = Math.max(max_ans, sum);
    }



    private static Pair move_fishes(int shark_x, int shark_y, int[][] map, Fish[] fishes) {
        int ny = 0, nx = 0, nd, nn;
        int cy, cx, cd;

        int[][] newMap = new int[4][4];
        Fish[] newFishes = new Fish[17];
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                newMap[i][j] = map[i][j];
                newFishes[i * 4 + j + 1] = fishes[i * 4 + j + 1];
            }
        }

        /*System.out.println("before move fish");
        print_map(newMap);
        print_map_detail(newMap, newFishes);*/
        //print_fishes(newFishes);

        for(int i = 1 ; i <= 16 ; i++) {
            if(newFishes[i].isDead) continue;
            cx = newFishes[i].x;
            cy = newFishes[i].y;
            cd = newFishes[i].dir;

            int d;
            for(d = cd ; d < cd + 8 ; d++) {
                nx = cx + dir[d % 8][0];
                ny = cy + dir[d % 8][1];

                if(ny == shark_y && nx == shark_x) continue;
                if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;

                break;
            }

            //System.out.println(i + "번 " + "cxcy " + cx + " " + cy + " " + dirp[cd] + " -> " + nx + " " + ny + " " + dirp[d%8]);
            cd = d % 8;
            //if(newMap[nx][ny] != 0 && newFishes[newMap[ny][nx]] != null && !newFishes[newMap[ny][nx]].isDead) {
            if(newMap[nx][ny] > 0) {
                //System.out.println(i);
                nn = newMap[nx][ny];
                nd = newFishes[nn].dir;

                newFishes[nn].y = cy;
                newFishes[nn].x = cx;
                newFishes[nn].dir = nd;

                newFishes[i].x = nx;
                newFishes[i].y = ny;
                newFishes[i].dir = cd;

                newMap[nx][ny] = i;
                newMap[cx][cy] = nn;
            } else {
                //System.out.println(i + " 2");
                newMap[nx][ny] = i;
                newMap[cx][cy] = 0;

                newFishes[i].y = ny;
                newFishes[i].x = nx;
                newFishes[i].dir = cd;
            }
            //print_map_detail(newMap, newFishes);
            //print_fishes(newFishes);
        }

        /*System.out.println("after move fish");
        print_map(newMap);
        print_map_detail(newMap, newFishes);*/
        //print_fishes(newFishes);
        return new Pair(newMap, newFishes);
    }

    private static void print_fishes(Fish[] newFishes) {
        for(int i = 1 ; i <= 16 ; i++) {
            System.out.println(newFishes[i].x + " " + newFishes[i].y + " " + newFishes[i].dir + " " + newFishes[i].isDead);

        }
    }

    private static Pair copy(int[][] map, Fish[] fishes) {
        int[][] newMap = new int[4][4];
        Fish[] newFishes = new Fish[17];
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                newMap[i][j] = map[i][j];
                newFishes[i * 4 + j + 1] = new Fish(fishes[i * 4 + j + 1].x, fishes[i * 4 + j + 1].y, fishes[i * 4 + j + 1].dir);
                newFishes[i * 4 + j + 1].isDead = fishes[i * 4 + j + 1].isDead;
            }
        }

        return new Pair(newMap, newFishes);
    }

    private static void print_map(int[][] map) {
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void print_map_detail(int[][] map, Fish[] fishes) {
        System.out.println();
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) {
                if(map[i][j] == 0)
                    System.out.print(map[i][j] + " " + "X ");
                else
                    System.out.print(map[i][j] + " " + dirp[fishes[map[i][j]].dir] + " ");
            }
            System.out.println();
        }
    }

    private static class Fish {
        int x,y;
        int dir;
        boolean isDead = false;

        public Fish(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        @Override
        public String toString() {
            return "Fish{" +
                    "x=" + x +
                    ", y=" + y +
                    ", dir=" + dir +
                    ", isDead=" + isDead +
                    '}';
        }
    }

    private static class Pair {
        int[][] arr;
        Fish[] fs;

        public Pair(int[][] arr, Fish[] fs) {
            this.arr = arr;
            this.fs = fs;
        }
    }
}