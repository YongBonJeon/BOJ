import java.sql.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N, M;
        N = sc.nextInt();
        M = sc.nextInt();

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
        int[] indegree = new int[N+1];

        for(int i = 0 ; i < M ; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            graph.get(A).add(B);
            indegree[B]++;
        }

        int[] dp = new int[N+1];
        Queue<Integer> q = new ArrayDeque<>();

        for(int i = 1 ; i <= N ; i++) {
            if(indegree[i] == 0) {
                q.add(i);
                dp[i] = 1;
            }
        }

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(Integer next : graph.get(cur)) {
                indegree[next]--;

                if(indegree[next] == 0) {
                    dp[next] = dp[cur] + 1;
                    q.add(next);
                }
            }

        }

        for(int i = 1 ; i <= N ; i++)
            System.out.print(dp[i] + " ");



    }

}