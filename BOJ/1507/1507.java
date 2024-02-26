import java.awt.*;
import java.util.*;
import java.util.List;

public class Main {

    static int N;
    static int[][] graph, dist;




    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        graph = new int[N+1][N+1];
        int[][] cur = new int[N+1][N+1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = sc.nextInt();
                cur[i][j] = graph[i][j];
            }
        }

        for(int k = 1 ; k <= N ; k++) {
            for(int i = 1 ; i <= N ; i++) {
                for(int j = 1 ; j <= N ; j++) {
                    if(i == j || i == k || j == k) continue;

                    if(graph[i][j] > graph[i][k] + graph[k][j]) {
                        System.out.println(-1);
                        return;
                    }

                    if(graph[i][j] == graph[i][k] + graph[k][j]) {
                        cur[i][j] = 0;
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(cur[i][j] != 0) {
                    ans += cur[i][j];
                }
            }
        }
        System.out.println(ans/2);
    }


}
