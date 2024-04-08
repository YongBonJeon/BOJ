import java.util.*;

public class Main {
    static int L, N, Q;
    static int[][] map;
    static int[][] knights_map;
    static Knight[] knights;
    // 상우하좌
    static int[][] dir = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    static Set<Integer> push_knights;

    static class Knight {
        int y, x;
        int h, w;
        int k;
        int sum = 0;
        boolean live = true;

        Knight(int y, int x, int h, int w, int k) {
            this.y = y;
            this.x = x;
            this.h = h;
            this.w = w;
            this.k = k;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        L = sc.nextInt();
        N = sc.nextInt();
        Q = sc.nextInt();

        map = new int[L+1][L+1];
        for(int i = 1 ; i <= L ; i++) {
            for(int j = 1 ; j <= L ; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        knights = new Knight[N+1];
        knights_map = new int[L+1][L+1];
        for(int i = 1 ; i <= N ; i++) {
            int y = sc.nextInt();
            int x = sc.nextInt();
            int h = sc.nextInt();
            int w = sc.nextInt();
            int k = sc.nextInt();
            knights[i] = new Knight(y, x, h, w, k);
            for(int j = y ; j < y + h ; j++) {
                for(int l = x ; l < x + w ; l++) {
                    knights_map[j][l] = i;
                }
            }
        }

        while(Q-- > 0) {
            int num, d;
            num = sc.nextInt();
            d = sc.nextInt();

            push_knights = new HashSet<>();
            //System.out.println("cmd " + num + " " + d);

            if(!knights[num].live) continue;
            if(test_push(num, d)) {
                push(d);

                score(num);

                //print_knights();

                //print_knights_map();
            }
        }

        int answer = 0;
        for(int i = 1 ; i <= N ; i++)
            if(knights[i].live)
                answer += knights[i].sum;

        System.out.println(answer);
    }

    private static void dead(int n) {
        for(int i = knights[n].y ; i < knights[n].y + knights[n].h ; i++) {
            for(int j = knights[n].x ; j < knights[n].x + knights[n].w ; j++) {
                knights_map[i][j] = 0;
            }
        }
        knights[n].live = false;
    }

    private static void score(int num) {
        for(int n : push_knights) {
            if(n == num) continue;
            for(int i = knights[n].y ; i < knights[n].y + knights[n].h ; i++) {
                for(int j = knights[n].x ; j < knights[n].x + knights[n].w ; j++) {
                    if(map[i][j] == 1) {
                        knights[n].k--;
                        knights[n].sum++;
                        if(knights[n].k == 0)
                            dead(n);
                    }
                }
            }
        }
    }

    private static void push(int d) {
        for(int n : push_knights) {
            for(int i = 1 ; i <= L ; i++) {
                for(int j = 1 ; j <= L ; j++) {
                    if(knights_map[i][j] == n)
                        knights_map[i][j] = 0;
                }
            }
        }
        for(int n : push_knights) {
            knights[n].y += dir[d][0];
            knights[n].x += dir[d][1];

            for(int i = knights[n].y ; i < knights[n].y + knights[n].h ; i++) {
                for(int j = knights[n].x ; j < knights[n].x + knights[n].w ; j++) {
                    knights_map[i][j] = n;
                }
            }
        }
    }

    private static boolean test_push(int num, int d) {
        Knight cur = knights[num];
        push_knights.add(num);

        boolean answer = true;

        Set<Integer> next = new HashSet<>();

        for(int i = cur.y ; i < cur.y + cur.h ; i++) {
            for(int j = cur.x ; j < cur.x + cur.w ; j++) {
                //System.out.println(i + " " + j);
                int ny = i + dir[d][0];
                int nx = j + dir[d][1];

                if(ny <= 0 || nx <= 0 || ny > L || nx > L || map[ny][nx] == 2)
                    return false;

                if(knights_map[ny][nx] != 0 && knights_map[ny][nx] != num) {
                    next.add(knights_map[ny][nx]);
                }
            }
        }

        for(int n : next) {
            //System.out.println("n " + n);
            answer = answer && test_push(n, d);
        }

        return answer;
    }

    private static void print_knights_map() {
        for(int i = 1 ; i <= L ; i++) {
            for(int j = 1 ; j <= L ; j++) {
                System.out.print(knights_map[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void print_knights() {
        for(int i = 1 ; i <= N ; i++) {
            System.out.println(i + " 번 기사");
            System.out.println("k " + knights[i].k);
            System.out.println("sum " + knights[i].sum);
        }
    }
}