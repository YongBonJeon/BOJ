import java.util.*;

public class Main {
    static int N, M, P, C, D;
    static int ru_y, ru_x;
    static Santa[] santas;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        P = sc.nextInt();
        C = sc.nextInt();
        D = sc.nextInt();

        santas = new Santa[P + 1];
        ru_y = sc.nextInt();
        ru_x = sc.nextInt();
        for(int i = 1 ; i <= P ; i++) {
            santas[sc.nextInt()] = new Santa(sc.nextInt(), sc.nextInt());
        }
        // M개의 턴
        while(M-- > 0) {
            // 루돌프 움직임
            move_ru();

            //System.out.println("ru " + ru_y + " " + ru_x);

            // 산타 움직임
            move_santa();

            // 스턴 풀기
            not_stun();

            // 종료 체크
            if(check())
                break;
        }

        for(int i = 1 ; i <= P ; i++) {
            System.out.print(santas[i].score + " ");
        }
    }

    private static boolean check() {
        boolean lives = true;
        for(int i = 1 ; i <= P ; i++) {
            if(santas[i].life) lives = false;
        }
        return lives;
    }

    private static void not_stun() {
        for(int i = 1 ; i <= P ; i++) {
            if(santas[i].life) santas[i].score++;
            santas[i].stun = Math.max(santas[i].stun - 1 , 0);
        }
    }

    private static int distance(int y, int x) {
        return (y - ru_y)*(y - ru_y)
                + (x - ru_x)*(x - ru_x);
    }

    private static void move_santa() {
        int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int santa_idx = 1 ; santa_idx <= P ; santa_idx++) {
            // 탈락 or 기절 산타 제외
            if(!santas[santa_idx].life || santas[santa_idx].stun > 0) {
                //System.out.println(santa_idx + " 못 움직여 ");
                continue;
            }

            // 산타 돌진
            int min_distance = distance(santas[santa_idx].y, santas[santa_idx].x);
            int nd = -1;
            for(int d = 0 ; d < 4 ; d++) {
                int ny = santas[santa_idx].y + dir[d][0];
                int nx = santas[santa_idx].x + dir[d][1];


                if(ny <= 0 || nx <= 0 || ny > N || nx > N) continue;

                boolean flag = false;
                for(int i = 1 ; i <= P ; i++) {
                    if(i == santa_idx) continue;
                    if(santas[i].life && (ny == santas[i].y && nx == santas[i].x))
                        flag = true;
                }
                if(flag) continue;

                if(distance(ny, nx) < min_distance) {
                    min_distance = distance(ny, nx);
                    nd = d;
                }
            }
            if(nd == -1) {
                //System.out.println(santa_idx + " 갈 곳 없어");
                continue;
            }

            santas[santa_idx].y += dir[nd][0];
            santas[santa_idx].x += dir[nd][1];

            //System.out.println(santa_idx + " 산타 이동 " + santas[santa_idx].y + " " + santas[santa_idx].x);

            // 충돌
            if(santas[santa_idx].y == ru_y && santas[santa_idx].x == ru_x) {
                santas[santa_idx].score += D;

                // 밀려남
                int rd = (nd + 2) % 4;

                santas[santa_idx].y += dir[rd][0]*D;
                santas[santa_idx].x += dir[rd][1]*D;

                //System.out.println(santa_idx + " 루돌프와 충돌 " + santas[santa_idx].y + " " + santas[santa_idx].x);

                // 산타 탈락
                if(santas[santa_idx].y <= 0 || santas[santa_idx].x <= 0 ||
                        santas[santa_idx].y > N || santas[santa_idx].x > N)
                    santas[santa_idx].life = false;

                //System.out.println("상호작용 전");
                // 상호 작용
                interaction(santa_idx, dir[rd][0], dir[rd][1]);
                //System.out.println("상호작용 후");
                // 기절
                santas[santa_idx].stun = 2;
            }
        }
    }

    private static void move_ru() {
        // 가장 가까운 산타 찾기
        int santa_idx = 0, min_distance = Integer.MAX_VALUE;

        for(int i = 1 ; i <= P ; i++) {
            // 탈락한 산타 제외
            if(!santas[i].life) continue;

            if(distance(santas[i].y, santas[i].x) < min_distance) {
                santa_idx = i;
                min_distance = distance(santas[i].y, santas[i].x);
            } else if(distance(santas[i].y, santas[i].x) == min_distance) {
                if(santas[i].y > santas[santa_idx].y) {
                    santa_idx = i;
                } else if(santas[i].y == santas[santa_idx].y) {
                    if(santas[i].x > santas[santa_idx].x) {
                        santa_idx = i;
                    }
                }
            }
        }

        //System.out.println("가장 가까운 산타 idx " + santa_idx);

        // 루돌프 돌진
        int dy = 0, dx = 0;
        if(santas[santa_idx].y > ru_y) {dy = 1; ru_y += 1;}
        else if(santas[santa_idx].y < ru_y) {dy = -1; ru_y -= 1; }

        if(santas[santa_idx].x > ru_x) {dx = 1; ru_x += 1; }
        else if(santas[santa_idx].x < ru_x) {dx = -1; ru_x -= 1; }

        // 충돌
        if(santas[santa_idx].y == ru_y && santas[santa_idx].x == ru_x) {
            santas[santa_idx].score += C;
            santas[santa_idx].y += dy*C;
            santas[santa_idx].x += dx*C;

           // System.out.println(santa_idx + " 루돌프와 충돌 " + santas[santa_idx].y + " " + santas[santa_idx].x);

            // 산타 탈락
            if(santas[santa_idx].y <= 0  || santas[santa_idx].x <= 0 ||
                    santas[santa_idx].y > N || santas[santa_idx].x > N)
                santas[santa_idx].life = false;


            // 상호 작용
            interaction(santa_idx, dy, dx);

            // 기절
            santas[santa_idx].stun = 2;
        }
    }

    private static void interaction(int santa_idx, int dy, int dx) {
        for(int i = 1 ; i <= P ; i++) {
            if(santa_idx == i || !santas[i].life) continue;
            if(santas[santa_idx].y == santas[i].y && santas[santa_idx].x == santas[i].x) {
                santas[i].y += dy;
                santas[i].x += dx;
                if(santas[i].y <= 0 || santas[i].x <= 0 || santas[i].y > N || santas[i].x > N)
                    santas[i].life = false;

                //System.out.println(santa_idx + "와 " + i + " 충돌 " + santas[i].y + " " + santas[i].x);

                interaction(i, dy, dx);
                break;
            }
        }
    }

    static class Santa {
        int y, x;
        boolean life = true;
        int stun = 0;
        int score = 0;

        Santa (int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}