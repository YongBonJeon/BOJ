import java.util.*;

public class Main {

    static int N, M, min_ans = Integer.MAX_VALUE;
    static int[][] map;

    static List<Virus> viruses = new ArrayList<>();
    static int cnt = 0;

    static class Virus {
        int y, x;

        public Virus(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N][N];

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                map[i][j] = sc.nextInt();

                if(map[i][j] == 2) {
                    viruses.add(new Virus(i, j));
                } else if(map[i][j] == 0)
                    cnt++;
            }
        }
        //System.out.println("cnt = " + cnt);

        if(cnt == 0) {
            System.out.println(0);
            return;
        }

        select_virus(0, new StringBuilder());

        if(min_ans == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(min_ans-1);
    }

    private static void select_virus(int idx, StringBuilder sb) {
        if(sb.length() == M) {
            bfs(sb.toString());
        }
        for(int i = idx ; i < viruses.size() ; i++) {
            sb.append(i);
            select_virus(i+1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    private static void bfs(String start_virus) {
        int[][] dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int[][] visited = new int[N][N];
        Queue<Virus> q = new ArrayDeque<>();

        //System.out.println(start_virus);
        for(int i = 0 ; i < M ; i++) {
            Virus virus = viruses.get(start_virus.charAt(i) - '0');
            q.add(virus);
            visited[virus.y][virus.x] = 1;

            //System.out.println(virus.y + " " + virus.x);
        }
        //System.out.println();

        int local_ans = 0;
        int local_cnt = 0;
        while (!q.isEmpty()) {
            Virus cur = q.poll();

            for(int i = 0 ; i < 4 ; i++) {
                int ny = cur.y + dir[i][0];
                int nx = cur.x + dir[i][1];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                if(visited[ny][nx] == 0 && (map[ny][nx] == 0 || map[ny][nx] == 2)) {
                    if(map[ny][nx] == 0) {
                        local_cnt++;
                        if(local_cnt == cnt) {
                            min_ans = Math.min(visited[cur.y][cur.x] + 1, min_ans);
                            //System.out.println(min_ans);
                            return ;
                        }
                    }
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    q.add(new Virus(ny, nx));
                }
            }
        }
    }
}