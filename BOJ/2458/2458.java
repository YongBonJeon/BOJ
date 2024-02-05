import java.util.*;

public class Main {
    static int N, M;
    static int[][] dist;
    static int INF = 1000000000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        dist = new int[N+1][N+1];

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        for(int i = 0 ; i < M ; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            dist[a][b] = 1;
        }

        for(int k= 1 ; k <= N ; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1 ; j <= N ; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = 0;
        for(int i = 1 ; i <= N ; i++){
            boolean flag = true;
            for(int j = 1 ; j <= N ; j++){
                if(dist[i][j] != INF || dist[j][i] != INF) continue;
                flag = false;
                break;
            }
            if (flag) ans++;
        }
        System.out.println(ans);
    }






}