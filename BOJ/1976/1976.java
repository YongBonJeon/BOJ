import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {

    static int N, M;
    static int[][] graph;
    static int[] path;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        graph = new int[N+1][N+1];
        path = new int[M+1];

        for (int from = 1; from <= N; from++) {
            for(int to = 1 ; to <= N ; to++) {
                graph[from][to] = sc.nextInt();
                if(from == to) {
                    graph[from][to] = 1;
                }
            }
        }


        for(int i = 1 ; i <= M ; i++) {
            path[i] = sc.nextInt();
        }

        for(int k = 1 ; k <= N ; k++) {
            for(int i = 1 ; i <= N ; i++) {
                for(int j = 1 ; j <= N ; j++) {
                    if(graph[i][k] == 1 && graph[k][j] == 1) {
                        graph[i][j] = 1;
                    }
                }
            }
        }

        boolean ans = true;
        for(int i = 1 ; i < M ; i++) {
            if(graph[path[i]][path[i+1]] == 0) {
                ans = false;
                break;
            }
        }
        System.out.println(ans ? "YES" : "NO");
    }

}
