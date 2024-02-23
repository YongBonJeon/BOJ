import java.awt.*;
import java.util.*;

public class Main {

    static int N, K, S;
    static int[][] graph;
    static int[] inDegree;
    static int[][] topology;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        graph = new int[N+1][N+1];
        inDegree = new int[N+1];

        for(int i=0; i<K; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a][b] = 1;
        }

        for(int k = 1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(graph[i][k] == 1 && graph[k][j] == 1){
                        graph[i][j] = 1;
                    }
                }
            }
        }

        S = sc.nextInt();
        for(int i=0; i<S; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(graph[a][b] == 1){
                System.out.println("-1");
            }else if(graph[b][a] == 1){
                System.out.println("1");
            }else{
                System.out.println("0");
            }
        }



    }




}
