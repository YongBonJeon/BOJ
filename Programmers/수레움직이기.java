import java.util.*;

class Solution {
    int N, M;

    class Status {
        int blue_y, blue_x;
        int red_y, red_x;

        boolean[][] blue_visited;
        boolean[][] red_visited;

        Status(int blue_y, int blue_x, int red_y, int red_x, boolean[][] blue_visited, boolean[][] red_visited) {
            this.blue_y = blue_y;
            this.blue_x = blue_x;
            this.red_y = red_y;
            this.red_x = red_x;

            this.blue_visited = new boolean[blue_visited.length][blue_visited[0].length];
            this.red_visited = new boolean[red_visited.length][red_visited[0].length];


            for(int i = 0 ; i < blue_visited.length ; i++)
                for(int j = 0 ; j < blue_visited[0].length ; j++)
                    this.blue_visited[i][j] = blue_visited[i][j];
            for(int i = 0 ; i < red_visited.length ; i++)
                for(int j = 0 ; j < red_visited[0].length ; j++)
                    this.red_visited[i][j] = red_visited[i][j];

        }
    }

    public int solution(int[][] maze) {
        N = maze.length;
        M = maze[0].length;

        int[][] dir = {{0,-1},{0,1},{-1,0},{1,0}};

        int blue_y = 0, blue_x = 0, red_y = 0, red_x = 0;
        int target_blue_y = 0, target_blue_x = 0, target_red_y = 0, target_red_x = 0;
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                if(maze[i][j] == 1) {
                    red_y = i;
                    red_x = j;
                } else if(maze[i][j] == 2) {
                    blue_y = i;
                    blue_x = j;
                } else if(maze[i][j] == 3) {
                    target_red_y = i;
                    target_red_x = j;
                } else if(maze[i][j] == 4) {
                    target_blue_y = i;
                    target_blue_x = j;
                }
            }
        }

        int[][][][] visited = new int[N][M][N][M];

        //System.out.println("NM " + N + " " + M);
        //System.out.println("blue " + blue_y + " " + blue_x);
        //System.out.println("red " + red_y + " " + red_x);
        //System.out.println("target blue " + target_blue_y + " " + target_blue_x);
        //System.out.println("target red " + target_red_y + " " + target_red_x);


        Queue<Status> q = new ArrayDeque<>();
        Status start = new Status(blue_y, blue_x, red_y, red_x, new boolean[N][M], new boolean[N][M]);
        start.blue_visited[blue_y][blue_x] = true;
        start.red_visited[red_y][red_x] = true;
        q.add(start);
        visited[blue_y][blue_x][red_y][red_x] = 1;


        while(!q.isEmpty()) {
            Status cur = q.poll();

            //System.out.println("cur blue " + cur.blue_y + " " + cur.blue_x + " red " + cur.red_y + " " + cur.red_x);

            if((cur.blue_y == target_blue_y && cur.blue_x == target_blue_x) &&
                    (cur.red_y == target_red_y && cur.red_x == target_red_x)) {
                return visited[cur.blue_y][cur.blue_x][cur.red_y][cur.red_x] - 1;
            }

            int next_blue_y, next_blue_x, next_red_y, next_red_x;
            for(int rd = 0 ; rd < 4 ; rd++) {
                for(int bd = 0 ; bd < 4 ; bd++) {
                    // 도착 칸 위치 고정 예외 처리
                    if(!(cur.blue_y == target_blue_y && cur.blue_x == target_blue_x)) {
                        next_blue_y = cur.blue_y + dir[bd][0];
                        next_blue_x = cur.blue_x + dir[bd][1];
                    } else {
                        next_blue_y = cur.blue_y;
                        next_blue_x = cur.blue_x;
                    }
                    if(!(cur.red_y == target_red_y && cur.red_x == target_red_x)) {
                        next_red_y = cur.red_y + dir[rd][0];
                        next_red_x = cur.red_x + dir[rd][1];
                    } else {
                        next_red_y = cur.red_y;
                        next_red_x = cur.red_x;
                    }

                    //System.out.println("next blue " + next_blue_y + " " + next_blue_x + " red " + next_red_y + " " + next_red_x);

                    // 격자 밖 예외처리
                    if(next_blue_y < 0 || next_blue_y >= N || next_blue_x < 0 || next_blue_x >= M) {
                        //System.out.println("1");
                        continue;
                    }
                    if(next_red_y < 0 || next_red_y >= N || next_red_x < 0 || next_red_x >= M) {
                        //System.out.println("2");
                        continue;
                    }

                    // 자신이 방문했던 칸 예외 처리
                    if(!(next_blue_y == target_blue_y && next_blue_x == target_blue_y) &&
                            cur.blue_visited[next_blue_y][next_blue_x]) {
                        //System.out.println("3");
                        continue;
                    }
                    if(!(next_red_y == target_red_y && next_red_x == target_red_x) &&
                            cur.red_visited[next_red_y][next_red_x]) {
                        //System.out.println("4");
                        continue;
                    }

                    // 동시에 같은 칸 예외 처리
                    if(!(next_blue_y == target_blue_y && next_blue_x == target_blue_y) &&
                            !(next_red_y == target_red_y && next_red_x == target_red_x) &&
                            next_blue_y == next_red_y && next_blue_x == next_red_x) {
                        //System.out.println("5");
                        continue;
                    }

                    // 수레끼리 자리 바꾸기 예외 처리
                    if((next_blue_y == cur.red_y && next_blue_x == cur.red_x) &&
                            (cur.blue_y == next_red_y && cur.blue_x == next_red_x)) {
                        //System.out.println("6");
                        continue;
                    }

                    // 벽 예외 처리
                    if(maze[next_blue_y][next_blue_x] == 5 || maze[next_red_y][next_red_x] == 5) {
                        //System.out.println("7");
                        continue;
                    }




                    // 이동
                    if(visited[next_blue_y][next_blue_x][next_red_y][next_red_x] == 0) {
                        //System.out.println("next blue " + next_blue_y + " " + next_blue_x + " red " + next_red_y + " " + next_red_x);
                        visited[next_blue_y][next_blue_x][next_red_y][next_red_x] =
                                visited[cur.blue_y][cur.blue_x][cur.red_y][cur.red_x] + 1;
                        Status next = new Status(next_blue_y, next_blue_x, next_red_y, next_red_x, cur.blue_visited, cur.red_visited);

                        next.blue_visited[next_blue_y][next_blue_x] = true;
                        next.red_visited[next_red_y][next_red_x] = true;

                        q.add(next);
                    }
                }
            }

        }


        return 0;
    }
}