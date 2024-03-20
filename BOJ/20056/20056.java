import java.util.*;

public class Main {
    static int N, M, K, idx = 0;
    static int[][] dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    static int[][] map;
    static Fireball[] fireballs;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        map = new int[N+1][N+1];
        fireballs = new Fireball[N*N*N];

        for(idx = 1 ; idx <= M ; idx++) {
            fireballs[idx] = new Fireball(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        while(K-- > 0) {
            move_fireballs();

            combine_fireballs();
        }

        int ans = 0;
        for(int i = 1 ; i < idx ; i++) {
            if(fireballs[i].on)
                ans += fireballs[i].ms;
        }
        System.out.println(ans);

    }

    private static void combine_fireballs() {
        for(int i = 1 ; i < idx ; i++) {
            if(!fireballs[i].on) continue;
            for(int j = i + 1 ; j < idx ; j++) {
                if(!fireballs[j].on) continue;
                if(fireballs[i].y == fireballs[j].y && fireballs[i].x == fireballs[j].x) {
                    fireballs[i].ms += fireballs[j].ms;
                    fireballs[i].sp += fireballs[j].sp;
                    fireballs[j].on = false;
                    fireballs[i].needDivision = true;
                    fireballs[i].num_combine++;
                    if(fireballs[i].dir % 2 != fireballs[j].dir % 2)
                        fireballs[i].allDir = false;
                }
            }
        }

        int newIdx = 1;
        Fireball[] newFireballs = new Fireball[N*N*N];
        for(int i = 1 ; i < idx ; i++) {
            if(!fireballs[i].on) continue;
            if(!fireballs[i].needDivision) {
                //System.out.println("i = " + i);
                newFireballs[newIdx++] = new Fireball(fireballs[i].y, fireballs[i].x, fireballs[i].ms, fireballs[i].sp, fireballs[i].dir);
            }
            else {
                if(fireballs[i].allDir && fireballs[i].ms >= 5) {
                    for (int j = 0; j < 4; j++) {
                        newFireballs[newIdx++] = new Fireball(fireballs[i].y, fireballs[i].x, fireballs[i].ms/5, fireballs[i].sp/fireballs[i].num_combine, j*2);
                    }
                } else if(!fireballs[i].allDir && fireballs[i].ms >= 5) {
                    for (int j = 0; j < 4; j++) {
                        newFireballs[newIdx++] = new Fireball(fireballs[i].y, fireballs[i].x, fireballs[i].ms/5, fireballs[i].sp/fireballs[i].num_combine, j*2+1);
                    }
                }
            }
        }

        idx = newIdx;
        fireballs = newFireballs;

        /*System.out.println("after combine");
        for(int i = 1 ; i < idx ; i++) {
            System.out.println(fireballs[i].y + " " + fireballs[i].x + " " + fireballs[i].ms + " " + fireballs[i].sp + " " + fireballs[i].dir);
        }*/
    }

    private static void move_fireballs() {
        for(int i = 1 ; i < idx ; i++) {
            fireballs[i].y += dir[fireballs[i].dir][0]*fireballs[i].sp;
            while(fireballs[i].y <= 0)
                fireballs[i].y += N;
            while(fireballs[i].y > N)
                fireballs[i].y -= N;
            fireballs[i].x += dir[fireballs[i].dir][1]*fireballs[i].sp;
            while(fireballs[i].x <= 0)
                fireballs[i].x += N;
            while(fireballs[i].x > N)
                fireballs[i].x -= N;
        }

        /*System.out.println("after move");
        for(int i = 1 ; i < idx ; i++) {
            System.out.println(fireballs[i].y + " " + fireballs[i].x + " " + fireballs[i].ms + " " + fireballs[i].sp + " " + fireballs[i].dir);
        }*/
    }

    static class Fireball {
        int y, x;
        int dir, sp , ms;
        boolean on = true;
        boolean needDivision = false;
        boolean allDir = true;
        int num_combine = 1;

        public Fireball(int y, int x, int ms, int sp, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
            this.sp = sp;
            this.ms = ms;
        }
    }
}