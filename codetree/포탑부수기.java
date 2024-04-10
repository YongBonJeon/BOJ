import java.util.*;
public class Main {
    static int N, M, K;
    static Tower[][] map;
    static int[][] dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    static int[][] at = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    static List<Pair> route, min_route;
    static boolean[][] visited;
    static boolean find;

    static class Tower {
        int ad = 0;
        int recent_attack = 0;

        Tower() {

        }
    }
    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        map = new Tower[N+1][M+1];
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= M ; j++) {
                map[i][j] = new Tower();
                map[i][j].ad = sc.nextInt();
            }
        }

        int idx = 0;
        while(K-- > 0){
            if(check()) break;
            idx++;
            // 공격자 선정
            Pair attacker = select_attack();
            //System.out.println(attacker.y + " " + attacker.x);

            // 공격자의 공격
            Pair defender = select_defend(attacker);
            //System.out.println(defender.y + " " + defender.x);

            // 레이저 공격
            int min_distance = attack_lazor(attacker, defender);
            //System.out.println(min_distance);
            route = new ArrayList<Pair>();
            min_route = null;
            visited = new boolean[N+1][M+1];
            visited[attacker.y][attacker.x] = true;
            find = false;
            if(min_distance != 0)
                find_route(attacker, defender, min_distance);
            //if(min_route != null)
            //    for(Pair pp : min_route)
            //        System.out.println(pp.y + " " + pp.x);
            if(min_route != null) {
                for(Pair p : min_route) {
                    map[p.y][p.x].ad -= map[attacker.y][attacker.x].ad/2;
                    map[p.y][p.x].ad = Math.max(map[p.y][p.x].ad, 0);
                }
                map[defender.y][defender.x].ad -= map[attacker.y][attacker.x].ad;
                map[defender.y][defender.x].ad = Math.max(map[defender.y][defender.x].ad, 0);
            }
            // 포탄 공격
            else {
                min_route = new ArrayList<>();
                for(int d = 0 ; d < 8 ; d++) {
                    int ny = defender.y + at[d][0];
                    int nx = defender.x + at[d][1];
                    if(ny > N) ny -= N;
                    if(nx > M) nx -= M;
                    if(ny == 0) ny = N;
                    if(nx == 0) nx = M;

                    if(ny == attacker.y && nx == attacker.x) continue;

                    min_route.add(new Pair(ny, nx));

                    map[ny][nx].ad -= map[attacker.y][attacker.x].ad/2;
                    map[ny][nx].ad = Math.max(map[ny][nx].ad, 0);
                }
                map[defender.y][defender.x].ad -= map[attacker.y][attacker.x].ad;
                map[defender.y][defender.x].ad = Math.max(map[defender.y][defender.x].ad, 0);
            }
            map[attacker.y][attacker.x].recent_attack = idx;

            //print_map();

            // 포탑 정비
            boolean[][] X = new boolean[N+1][M+1];
            if(min_route != null)
                for(Pair p : min_route)
                    X[p.y][p.x] = true;
            X[attacker.y][attacker.x] = true;
            X[defender.y][defender.x] = true;

            for(int i = 1 ; i <= N ; i++) {
                for(int j = 1 ; j <= M ; j++) {
                    if(!X[i][j] && map[i][j].ad != 0) {
                        map[i][j].ad++;
                    }
                }
            }

            //print_map();
        }
        Pair answer = select_defend(new Pair(0,0));
        System.out.println(map[answer.y][answer.x].ad);
    }


    private static void find_route(Pair p, Pair target, int min_distance) {
        if(route.size() == min_distance) {
            if(p.y == target.y && p.x == target.x && !find) {
                min_route = new ArrayList<>();
                for(int i = 0 ; i < route.size() -1 ; i++)
                    min_route.add(route.get(i));
                find = true;
            }
            return ;
        }

        for(int d = 0 ; d < 4; d++) {
            int ny = p.y + dir[d][0];
            int nx = p.x + dir[d][1];
            if(ny > N) ny -= N;
            if(nx > M) nx -= M;
            if(ny == 0) ny = N;
            if(nx == 0) nx = M;

            if(map[ny][nx].ad == 0 || visited[ny][nx]) continue;

            route.add(new Pair(ny, nx));
            visited[ny][nx] = true;
            find_route(new Pair(ny, nx), target, min_distance);
            visited[ny][nx] = false;
            route.remove(route.size()-1);
        }
    }

    private static int attack_lazor(Pair attacker, Pair defender) {
        int[][] visited = new int[N+1][M+1];
        Queue<Pair> q = new ArrayDeque<>();
        visited[attacker.y][attacker.x] = 1;
        q.add(new Pair(attacker.y, attacker.x));

        while(!q.isEmpty()) {
            Pair p = q.poll();

            for(int d = 0 ; d < 4 ; d++) {
                int ny = p.y + dir[d][0];
                int nx = p.x + dir[d][1];
                if(ny > N) ny -= N;
                if(nx > M) nx -= M;
                if(ny == 0) ny = N;
                if(nx == 0) nx = M;

                if(ny == defender.y && nx == defender.x)
                    return visited[p.y][p.x];

                if(visited[ny][nx] == 0 && map[ny][nx].ad != 0) {
                    q.add(new Pair(ny, nx));
                    visited[ny][nx] = visited[p.y][p.x] + 1;
                }
            }
        }
        return 0;
    }

    private static boolean check() {
        int num = 0;
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= M ; j++)
                if(map[i][j].ad > 0) num++;
        if(num == 1) return true;
        return false;
    }

    private static Pair select_attack() {
        int min_ad = Integer.MAX_VALUE;
        int max_recent = 0;
        int y = 0, x = 0;

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= M ; j++) {
                if(map[i][j].ad == 0) continue;
                if(min_ad > map[i][j].ad) {
                    min_ad = map[i][j].ad;
                    max_recent = map[i][j].recent_attack;
                    y = i;
                    x = j;
                } else if(min_ad == map[i][j].ad) {
                    if(max_recent < map[i][j].recent_attack) {
                        max_recent = map[i][j].recent_attack;
                        y = i;
                        x = j;
                    } else if(max_recent == map[i][j].recent_attack) {
                        if(y + x < i + j) {
                            y = i;
                            x = j;
                        } else if(y + x == i + j) {
                            if(x < j) {
                                y = i;
                                x = j;
                            }
                        }
                    }
                }
            }
        }
        map[y][x].ad += N+M;
        return new Pair(y, x);
    }

    private static Pair select_defend(Pair attacker) {
        int max_ad = 0;
        int min_recent = Integer.MAX_VALUE;
        int y = 0, x = 0;

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= M ; j++) {
                if(map[i][j].ad == 0 || (i== attacker.y && j == attacker.x)) continue;
                if(max_ad < map[i][j].ad) {
                    max_ad = map[i][j].ad;
                    min_recent = map[i][j].recent_attack;
                    y = i;
                    x = j;
                } else if(max_ad == map[i][j].ad) {
                    if(min_recent > map[i][j].recent_attack) {
                        min_recent = map[i][j].recent_attack;
                        y = i;
                        x = j;
                    } else if(min_recent == map[i][j].recent_attack) {
                        if(y + x > i + j) {
                            y = i;
                            x = j;
                        } else if(y + x == i + j) {
                            if(x > j) {
                                y = i;
                                x = j;
                            }
                        }
                    }
                }
            }
        }
        return new Pair(y, x);
    }

    private static void print_map() {
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= M ; j++) {
                System.out.print(map[i][j].ad + " " );
            }
            System.out.println();
        }
    }
}