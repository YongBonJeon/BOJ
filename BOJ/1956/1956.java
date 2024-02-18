import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int V, E;
    static int[][] graph;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        V = sc.nextInt();
        E = sc.nextInt();

        graph = new int[V+1][V+1];
        for(int i=0; i<E; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            graph[a][b] = c;
        }

        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                if(graph[i][j] == 0){
                    graph[i][j] = 1000000000;
                }
            }
        }

        for(int k=1; k<=V; k++){
            for(int i=1; i<=V; i++){
                for(int j=1; j<=V; j++){
                    graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int ans = 1000000000;
        for(int i = 1 ; i <= V ; i++) {
            ans = Math.min(ans, graph[i][i]);
        }

        System.out.println(ans == 1000000000 ? -1 : ans);




    }

}
