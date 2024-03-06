import java.awt.*;
import java.util.*;
import java.util.List;

public class Main {
    static char[][] map;
    static int N, M, hole_y, hole_x;

    public static void main(String args[]) throws InterruptedException {
        Scanner sc = new Scanner(System.in);
        int rx = 0, ry = 0, bx = 0, by = 0;
        N = sc.nextInt();
        M = sc.nextInt();

        map = new char[N+1][M+1];
        for(int i = 0 ; i < N ; i++) {
            String input = sc.next();
            for(int j = 0 ; j < M ; j++) {
                map[i][j] = input.charAt(j);
                if(map[i][j] == 'R') {
                    ry = i; rx = j;
                } else if(map[i][j] == 'B') {
                    by = i; bx = j;
                } else if(map[i][j] == 'O') {
                    hole_y = i; hole_x = j;
                }
            }
        }
        //System.out.println(hole_y + " " + hole_x);

        System.out.println(bfs(ry, rx, by, bx));

        //printMap();
    }

    private static int bfs(int ry, int rx, int by, int bx) throws InterruptedException {
        boolean[][][][] visited = new boolean[N][M][N][M];

        Queue<Bead> q = new ArrayDeque<>();
        q.add(new Bead(ry, rx, by, bx, 0));
        visited[ry][rx][by][bx] = true;

        while (!q.isEmpty()) {
            Bead cur = q.poll();

            //System.out.println(cur);

            if(cur.cost >= 10) return -1;

            // 동쪽 기울이기
            boolean blueIsHole = false;
            boolean redIsHole = false;
            Bead next = new Bead(cur.ry, cur.rx, cur.by, cur.bx, cur.cost);
            //System.out.println("동쪽");
            if(next.bx > next.rx) {
                while(next.bx + 1 < M && map[next.by][next.bx + 1] != '#') {
                    next.bx++;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.by = 0;
                        next.bx = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while (next.rx + 1 < M && map[next.ry][next.rx + 1] != '#' &&
                        !(next.rx + 1 == next.bx && next.ry == next.by)) {
                    next.rx++;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.ry = 0;
                        next.rx = 0;
                        break;
                    }
                }
                //System.out.println(next);

                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if (!visited[next.ry][next.rx][next.by][next.bx] && !next.equals(cur) && !blueIsHole) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            } else {
                while (next.rx + 1 < M && map[next.ry][next.rx + 1] != '#') {
                    next.rx++;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.ry = 0;
                        next.rx = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while(next.bx + 1 < M && map[next.by][next.bx + 1] != '#' &&
                        !(next.bx + 1 == next.rx && next.by == next.ry)) {
                    next.bx++;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.by = 0;
                        next.bx = 0;
                        break;
                    }
                }
                //System.out.println(next);
                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if(!visited[next.ry][next.rx][next.by][next.bx] && !next.equals(cur) && !blueIsHole) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            }

            // 서쪽 기울이기
            blueIsHole = false;
            redIsHole = false;
            next = new Bead(cur.ry, cur.rx, cur.by, cur.bx, cur.cost);
            //System.out.println("서쪽");
            if(next.bx < next.rx) {
                while(next.bx-1 >= 0 && map[next.by][next.bx - 1] != '#') {
                    next.bx--;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.bx = 0;
                        next.by = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while (next.rx-1 >= 0 && map[next.ry][next.rx - 1] != '#' &&
                        !(next.rx - 1 == next.bx && next.ry == next.by)) {
                    next.rx--;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.rx = 0;
                        next.ry = 0;
                        break;
                    }
                }
                //System.out.println(next);

                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if (!visited[next.ry][next.rx][next.by][next.bx] && !next.equals(cur) && !blueIsHole) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            } else {
                while (next.rx -1 >= 0 && map[next.ry][next.rx - 1] != '#') {
                    next.rx--;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.rx = 0;
                        next.ry = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while(next.bx-1 >= 0 && map[next.by][next.bx - 1] != '#' &&
                        !(next.bx - 1 == next.rx && next.by == next.ry)) {
                    next.bx--;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.bx = 0;
                        next.by = 0;
                        break;
                    }
                }
                //System.out.println(next);
                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if(!visited[next.ry][next.rx][next.by][next.bx] && !blueIsHole && !next.equals(cur)) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            }

            // 북쪽 기울이기
            blueIsHole = false;
            redIsHole = false;
            next = new Bead(cur.ry, cur.rx, cur.by, cur.bx, cur.cost);
            //System.out.println("북쪽");
            if(next.by < next.ry) {
                while(next.by - 1 >= 0 && map[next.by - 1][next.bx] != '#') {
                    next.by--;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.bx = 0;
                        next.by = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while (next.ry -1 >= 0 && map[next.ry - 1][next.rx] != '#' &&
                        !(next.ry - 1 == next.by && next.rx == next.bx)) {
                    next.ry--;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.bx = 0;
                        next.by = 0;
                        break;
                    }
                }
                //System.out.println(next);

                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if (!visited[next.ry][next.rx][next.by][next.bx] && !next.equals(cur) && !blueIsHole) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            } else {
                while (next.ry-1 >= 0 && map[next.ry - 1][next.rx] != '#') {
                    next.ry--;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.ry = 0;
                        next.rx = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while(next.by-1 >= 0 && map[next.by - 1][next.bx] != '#' &&
                        !(next.by - 1 == next.ry && next.bx == next.rx)) {
                    next.by--;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.by = 0;
                        next.bx = 0;
                        break;
                    }
                }
                //System.out.println(next);

                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if(!visited[next.ry][next.rx][next.by][next.bx] && !blueIsHole && !next.equals(cur)) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            }

            // 남쪽 기울이기
            blueIsHole = false;
            redIsHole = false;
            next = new Bead(cur.ry, cur.rx, cur.by, cur.bx, cur.cost);
            //System.out.println("남쪽");
            if(next.by > next.ry) {
                while(next.by+1 < N && map[next.by + 1][next.bx] != '#') {
                    next.by++;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        next.bx = 0;
                        next.by = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while (next.ry+1 < N && map[next.ry + 1][next.rx] != '#' &&
                        !(next.ry + 1 == next.by && next.rx == next.bx)) {

                    next.ry++;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.rx = 0;
                        next.ry = 0;
                        break;
                    }
                }
                //System.out.println(next);
                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if (!visited[next.ry][next.rx][next.by][next.bx] && !next.equals(cur) && !blueIsHole) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            } else {
                while (next.ry+1 < N && map[next.ry + 1][next.rx] != '#') {
                    next.ry++;
                    if (hole_y == next.ry && hole_x == next.rx) {
                        redIsHole = true;
                        next.rx = 0;
                        next.ry = 0;
                        break;
                    }
                }
                //System.out.println(next);
                while(next.by+1 < N && map[next.by + 1][next.bx] != '#' &&
                        !(next.by + 1 == next.ry && next.bx == next.rx)) {
                    next.by++;
                    if(hole_y == next.by && hole_x == next.bx) {
                        blueIsHole = true;
                        break;
                    }
                }
                //System.out.println(next);
                if(!blueIsHole && redIsHole) return cur.cost + 1;
                else if(blueIsHole && redIsHole) {}
                else if(!visited[next.ry][next.rx][next.by][next.bx] && !blueIsHole && !next.equals(cur)) {
                    //System.out.println("add");
                    next.cost++;
                    q.add(next);
                    visited[next.ry][next.rx][next.by][next.bx] = true;
                }
            }
            //Thread.sleep(1000);
        }

        return -1;
    }

    private static void printMap() {
        for(int i = 0 ; i < map.length ; i++) {
            for(int j = 0 ; j < map[0].length ; j++) {
                //System.out.print(map[i][j]);
            }
            //System.out.println();
        }
    }


    private static class Bead {
        int ry, rx, by, bx, cost;

        public Bead(int ry, int rx, int by, int bx, int cost) {
            this.ry = ry;
            this.rx = rx;
            this.by = by;
            this.bx = bx;
            this.cost = cost;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Bead bead = (Bead) o;
            return ry == bead.ry && rx == bead.rx && by == bead.by && bx == bead.bx;
        }


        @Override
        public String toString() {
            return "Bead{" +
                    "ry=" + ry +
                    ", rx=" + rx +
                    ", by=" + by +
                    ", bx=" + bx +
                    ", cost=" + cost +
                    '}';
        }
    }
}
