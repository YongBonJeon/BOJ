import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;
    static Person[] people;
    static int[][] dir = {{-1,0},{0,-1},{0,1},{1,0}};

    static class Person {
        int y, x;
        int target_y, target_x;
        boolean on = false;

        Person(int target_y, int target_x) {
            this.target_y = target_y;
            this.target_x = target_x;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N+1][N+1];
        people = new Person[M+1];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        for(int i = 1 ; i <= M ; i++) {
            people[i] = new Person(sc.nextInt(), sc.nextInt());
        }

        int time = 1;

        while(checkFin(time)) {
            //System.out.println("time " + time);
            // 가고 싶은 편의점 방향으로 1칸 이동
            move_people();

            // 편의점 도착 확인
            check_people();

            // 새로운 인원 베이스 캠프로
            add_people(time);

            //print_map();
            time++;
        }
        System.out.println(time-1);
    }

    private static void move_people() {
        for(int i = 1 ; i <= M ; i++) {
            if(!people[i].on) continue;
            int min_distance = distance(i, people[i].y, people[i].x);

            int cur_distance, dd = 0;
            for(int d = 0 ; d < 4 ; d++) {
                int ny = people[i].y + dir[d][0];
                int nx = people[i].x + dir[d][1];

                if(ny <= 0 || nx <= 0 || ny > N || nx > N || map[ny][nx] == 2) continue;

                cur_distance = distance(i, ny, nx);

                if(cur_distance < min_distance) {
                    min_distance = cur_distance;
                    dd = d;
                }
            }

            //System.out.println(i + " 번 이동 " + people[i].y + " " + people[i].x + " " + (people[i].y+dir[dd][0]) + " " +  (people[i].x + dir[dd][1]));

            people[i].y += dir[dd][0];
            people[i].x += dir[dd][1];
        }
    }

    private static void check_people() {
        for(int i = 1 ; i <= M ; i++) {
            if(people[i].y == people[i].target_y &&
                    people[i].x == people[i].target_x) {
                map[people[i].y][people[i].x] = 2;
                people[i].on = false;
            }
        }
    }

    private static void add_people(int t) {
        if(t > M) return ;

        int y = 0, x = 0, min_distance = Integer.MAX_VALUE;
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(map[i][j] == 1) {
                    int cur_distance = distance(t, i, j);
                    //System.out.println(cur_distance);
                    if(min_distance > cur_distance) {
                        min_distance = cur_distance;
                        y = i;
                        x = j;
                    }
                }
            }
        }
        //System.out.println("add person " + y + " " + x);
        people[t].y = y;
        people[t].x = x;
        people[t].on = true;
        map[y][x] = 2;
    }

    private static int distance(int n, int y, int x) {
        int target_y = people[n].target_y;
        int target_x = people[n].target_x;

        int[][] visited = new int[N+1][N+1];
        Queue<Pair> q = new ArrayDeque<>();

        q.add(new Pair(y, x));
        visited[y][x] = 1;

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            if(cur.y == target_y && cur.x == target_x)
                return visited[cur.y][cur.x] - 1;

            for(int d = 0 ; d < 4 ; d++) {
                int ny = cur.y + dir[d][0];
                int nx = cur.x + dir[d][1];

                if(ny <= 0 || nx <= 0 || ny > N || nx > N || map[ny][nx] == 2) continue;

                if(visited[ny][nx] == 0) {
                    q.add(new Pair(ny, nx));
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    private static boolean checkFin(int time) {
        if(time <= M) return true;

        boolean flag = false;
        for(int i = 1 ; i <= M ; i++) {
            if(people[i].on) return true;
        }
        return flag;
    }

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    private static void print_map(){
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }

}