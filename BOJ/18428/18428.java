import java.util.*;

public class Main {
    static int N;
    static String[][] map;
    static int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        map = new String[N][N];
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                map[i][j] = sc.next();
            }
        }

        for(int i = 0 ; i < N*N ; i++) {
            int one_y = i/N, one_x = i%N;
            if(!map[one_y][one_x].equals("X")) continue;
            for(int j = i + 1 ; j < N*N ; j++) {
                int two_y = j/N, two_x = j%N;
                if(!map[two_y][two_x].equals("X")) continue;
                for(int k = j + 1 ; k < N*N ; k++) {
                    int thr_y = k/N, thr_x = k%N;
                    if(!map[thr_y][thr_x].equals("X")) continue;
                    //System.out.println(one_y + " " + one_x);
                    //System.out.println(two_y + " " + two_x);
                    //System.out.println(thr_y + " " + thr_x);

                    map[one_y][one_x] = "O";
                    map[two_y][two_x] = "O";
                    map[thr_y][thr_x] = "O";

                    if(check()) {
                        System.out.println("YES");
                        return ;
                    }

                    map[one_y][one_x] = "X";
                    map[two_y][two_x] = "X";
                    map[thr_y][thr_x] = "X";
                }
            }
        }
        System.out.println("NO");
    }

    private static boolean check() {
        for (int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(map[i][j].equals("T")) {
                    for(int d = 0 ; d < 4 ; d++) {
                        int ny = i + dir[d][0];
                        int nx = j + dir[d][1];

                        while(ny >= 0 && nx >= 0 && ny < N && nx < N) {
                            if(map[ny][nx].equals("S")) return false;
                            if(map[ny][nx].equals("O")) break;
                            ny += dir[d][0];
                            nx += dir[d][1];
                        }
                    }
                }
            }
        }
        return true;
    }
}