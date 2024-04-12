import java.util.*;

public class Main {
    static int N, M, K;
    static PriorityQueue[][] map;
    static int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};
    static Player[] players;
    static int[][] players_map;

    static class Player {
        int y, x;
        int dir;
        int ad;
        int plus_ad = 0;
        int score = 0;

        Player(int y, int x, int dir, int ad) {
            this.y = y;
            this.x = x;
            this.dir = dir;
            this.ad = ad;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        map = new PriorityQueue[N+1][N+1];
        players_map = new int[N+1][N+1];
        players = new Player[M+1];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = new PriorityQueue<Integer>(Collections.reverseOrder());
                int temp = sc.nextInt();
                if(temp > 0)
                    map[i][j].add(temp);
            }
        }

        for(int i = 1 ; i <= M ; i++) {
            players[i] = new Player(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
            players_map[players[i].y][players[i].x] = i;
        }

        while(K-- > 0) {
            // 플레이어 순차 이동
            move_players();
        }

        for(int i = 1 ; i <= M ; i++) {
            System.out.print(players[i].score + " ");
        }


    }

    private static void move_players() {
        for(int i = 1 ; i <= M ; i++) {
            int d = players[i].dir;
            int ny = players[i].y + dir[d][0];
            int nx = players[i].x + dir[d][1];

            // 격자를 벗어나는 경우 정반대 방향
            if(ny < 1 || nx < 1 || ny > N || nx > N) {
                d = (d+2) % 4;
                ny = players[i].y + dir[d][0];
                nx = players[i].x + dir[d][1];
                players[i].dir = d;
            }
            players_map[players[i].y][players[i].x] = 0;

            //System.out.println(i + " 번 이동 " + players[i].y + " " + players[i].x + " " + ny + " " + nx);

            players[i].y = ny;
            players[i].x = nx;

            // 이동 방향에 플레이어가 없는 경우
            if(players_map[ny][nx] == 0) {
                // 해당 칸에 총이 있는 경우
                if(map[ny][nx].size() != 0) {
                    int gun = (int) map[ny][nx].peek();
                    if(players[i].plus_ad < gun) {
                        if(players[i].plus_ad != 0)
                            map[ny][nx].add(players[i].plus_ad);
                        players[i].plus_ad = (int) map[ny][nx].poll();
                    }
                }

                players_map[ny][nx] = i;

                //System.out.println("이동 방향에 플레이어가 없는 경우");
                //System.out.println("갖고 있는 총의 공격력 " + players[i].plus_ad);
            }
            // 이동 방향에 플레이어가 있는 경우
            else {
                int enemy = players_map[ny][nx];
                int winner, loser;

                if(players[i].ad + players[i].plus_ad > players[enemy].ad + players[enemy].plus_ad) {
                    winner = i;
                    loser = enemy;
                } else if(players[i].ad + players[i].plus_ad == players[enemy].ad + players[enemy].plus_ad) {
                    if(players[i].ad > players[enemy].ad) {
                        winner = i;
                        loser = enemy;
                    } else {
                        winner = enemy;
                        loser = i;
                    }
                } else {
                    winner = enemy;
                    loser = i;
                }
                players_map[ny][nx] = winner;

                //System.out.println("이동 방향에 플레이어가 있는 경우");
                //System.out.println("승자 " + winner + " 패자 " + loser);

                // 이긴 플레이어 점수 획득
                players[winner].score += (players[winner].ad + players[winner].plus_ad) - (players[loser].ad + players[loser].plus_ad);

                //System.out.println("승자 " + winner + " 점수 획득 " + ((players[winner].ad + players[winner].plus_ad) - (players[loser].ad + players[loser].plus_ad)));

                // 진 플레이어 총 내려놈
                if(players[loser].plus_ad != 0) {
                    map[ny][nx].add(players[loser].plus_ad);
                    players[loser].plus_ad = 0;
                }

                // 진 플레이어 이동
                for(int ld = players[loser].dir ; ld < players[loser].dir + 4 ; ld++) {
                    int loser_y = players[loser].y + dir[ld%4][0];
                    int loser_x = players[loser].x + dir[ld%4][1];

                    if(loser_y < 1 || loser_x < 1 || loser_y > N || loser_x > N || players_map[loser_y][loser_x] > 0) continue;

                    players[loser].y = loser_y;
                    players[loser].x = loser_x;
                    players_map[loser_y][loser_x] = loser;
                    players[loser].dir = ld%4;

                    // 진 플레이어 이동 후 총 줍기
                    if(map[loser_y][loser_x].size() != 0) {
                        players[loser].plus_ad = (int) map[loser_y][loser_x].poll();
                    }

                    //System.out.println("패자 " + loser + " 이동 " + loser_y + " " + loser_x);
                    //System.out.println("패자 갖고 있는 총의 공격력 " + players[loser].plus_ad);
                    break;
                }

                // 이긴 플레이어 총 줍기
                if(map[ny][nx].size() != 0) {
                    int gun = (int) map[ny][nx].peek();
                    if(players[winner].plus_ad < gun) {
                        if(players[winner].plus_ad != 0)
                            map[ny][nx].add(players[winner].plus_ad);
                        players[winner].plus_ad = (int) map[ny][nx].poll();
                    }
                }
                //System.out.println("승자 갖고 있는 총의 공격력 " + players[winner].plus_ad);
            }
        }
    }
}
