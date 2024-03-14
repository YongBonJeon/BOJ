import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static int[][] status;
    static int[] order;
    static int[][] dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        map = new int[N+1][N+1];
        status = new int[N*N+1][4];
        order = new int[N * N + 1];

        int num;
        for(int i = 0 ; i < N*N ; i++) {
            num = sc.nextInt();
            order[i+1] = num;
            for(int j = 0 ; j < 4 ; j++) {
                status[num][j] = sc.nextInt();
            }
        }

        place_student();

        /*for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++)
                System.out.print(map[i][j] + " ");
            System.out.println();
        }*/

        int ans = 0;
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                int local_ans = 0;

                for(int d = 0 ; d < 4 ; d++) {
                    int ny = i + dir[d][0];
                    int nx = j + dir[d][1];

                    if (ny < 1 || ny > N || nx < 1 || nx > N) continue;

                    for(int k = 0 ; k < 4 ; k++) {
                        if(status[map[i][j]][k] == map[ny][nx])
                            local_ans++;
                    }
                }
                if(local_ans > 0)
                    ans += Math.pow(10, local_ans - 1);
            }
        }
        System.out.println(ans);
    }

    private static void place_student() {
        for(int i = 1 ; i <= N*N ; i++) {
            int cur = order[i];

            //System.out.println("cur = " + cur);
            // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸
            int max_y = N+1, max_x = N+1, max_good = 0, max_empty = 0;

            for(int y = 1 ; y <= N ; y++) {
                for(int x = 1 ; x <= N ; x++) {
                    if(map[y][x] != 0) continue;

                    int local_good = 0, local_empty = 0;
                    for(int d = 0 ; d < 4 ; d++) {
                        int ny = y + dir[d][0], nx = x + dir[d][1];
                        if (ny < 1 || ny > N || nx < 1 || nx > N) continue;

                        for(int k = 0 ; k < 4 ; k++)
                            if(status[cur][k] == map[ny][nx])
                                local_good++;
                        if(map[ny][nx] == 0)
                            local_empty++;
                    }
                    /*System.out.print("y = " + y); System.out.println(" x = " + x);
                    System.out.println("local_good = " + local_good);
                    System.out.println("local_empty = " + local_empty);*/

                    if(local_good > max_good) {
                        max_y = y;
                        max_x = x;
                        max_good = local_good;
                        max_empty = local_empty;
                    } else if(local_good == max_good) {
                        if(local_empty > max_empty) {
                            max_y = y;
                            max_x = x;
                            max_empty = local_empty;
                        } else if(local_empty == max_empty) {
                            if(y < max_y) {
                                max_y = y;
                                max_x = x;
                            } else if(y == max_y) {
                                if(x < max_x) {
                                    max_x = x;
                                }
                            }
                        }
                    }
                }
            }
            map[max_y][max_x] = cur;
            //System.out.println(cur + " " + max_y + " " + max_x);
        }
    }
}