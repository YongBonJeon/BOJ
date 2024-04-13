import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static int[][] visited, near_group;
    static int[] count_group, groupToNum;
    static int[][] dir = {{-1,0}, {0, 1}, {0, -1}, {1, 0}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        map = new int[N][N];
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        int answer = 0;
        answer += calculate();

        rotate();
        answer += calculate();

        rotate();
        answer += calculate();

        rotate();
        answer += calculate();

        System.out.println(answer);
    }

    private static void rotate() {
        int[][] newMap = new int[N][N];

        for(int i = 0 ; i < N ; i++) {
            newMap[N-1-i][N/2] = map[N/2][i];
        }
        for(int i = 0 ; i < N ; i++) {
            newMap[N/2][i] = map[i][N/2];
        }

        for(int i = 0 ; i < N/2 ; i++) {
            for(int j = 0 ; j < N/2 ; j++) {
                newMap[j][N/2-1-i] = map[i][j];
            }
        }

        for(int i = 0 ; i < N/2 ; i++) {
            for(int j = 0 ; j < N/2 ; j++) {
                newMap[j][N/2-1-i+N/2+1] = map[i][j+N/2+1];
            }
        }

        for(int i = 0 ; i < N/2 ; i++) {
            for(int j = 0 ; j < N/2 ; j++) {
                newMap[j+N/2+1][N/2-1-i] = map[i+N/2+1][j];
            }
        }

        for(int i = 0 ; i < N/2 ; i++) {
            for(int j = 0 ; j < N/2 ; j++) {
                newMap[j+N/2+1][N/2-1-i+N/2+1] = map[i+N/2+1][j+N/2+1];
            }
        }

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                //System.out.print(newMap[i][j] + " ");
                map[i][j] = newMap[i][j];
            }
            //System.out.println();
        }
    }

    private static void grouping(int y, int x, int group_num) {
        visited[y][x] = group_num;


        for(int d = 0 ; d < 4 ; d++) {
            int ny = y + dir[d][0];
            int nx = x + dir[d][1];

            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

            if(map[ny][nx] == map[y][x] && visited[ny][nx] == 0) {
                grouping(ny, nx, group_num);
            }
        }
    }

    private static int calculate() {
        visited = new int[N][N];
        int group_num = 1;
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(visited[i][j] == 0) {
                    grouping(i, j, group_num++);
                }
            }
        }
        group_num--;
        count_group = new int[group_num+1];
        near_group = new int[group_num+1][group_num+1];
        groupToNum = new int[group_num+1];

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                count_group[visited[i][j]]++;
                groupToNum[visited[i][j]] = map[i][j];

                for(int d = 0 ; d < 4 ; d++) {
                    int ny = i + dir[d][0];
                    int nx = j + dir[d][1];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                    near_group[visited[i][j]][visited[ny][nx]]++;
                }
            }
        }

        int answer = 0;

        for(int i = 1 ; i <= group_num ; i++) {
            for(int j = i+1 ; j <= group_num ; j++) {
                int temp = 1;

                temp *= (count_group[i]+count_group[j]);
                temp *= groupToNum[i];
                temp *= groupToNum[j];
                temp *= near_group[i][j];

                //System.out.println("count " + count_group[i] + " " + count_group[j]);
                //System.out.println("groupToNum " + groupToNum[i] + " " + groupToNum[j]);
                //System.out.println("group " + i + " " + j + " " + temp);
                answer += temp;
            }
        }

        //System.out.println(answer);
        return answer;
    }

}