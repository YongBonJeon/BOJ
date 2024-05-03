import java.sql.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int[] indegree = new int[N+1];
        int[] time = new int[N+1];
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0 ; i <= N ; i++)
            graph.add(new ArrayList<>());

        for(int i = 1 ; i <= N ; i++) {
            time[i] = sc.nextInt();

            int num = sc.nextInt();
            for(int j = 0 ; j < num ; j++) {
                int prev = sc.nextInt();
                graph.get(prev).add(i);
                indegree[i]++;
            }
        }

        int[] dp = new int[N+1];
        //Arrays.fill(dp, Integer.MAX_VALUE);
        Queue<Integer> q = new ArrayDeque<>();
        for(int i = 1 ; i <= N ; i++)
            if(indegree[i] == 0) {
                q.add(i);
                dp[i] = time[i];
            }

        int answer = 0;
        while(!q.isEmpty()) {
            int cur = q.poll();

            answer = Math.max(answer, dp[cur]);
            for(int next : graph.get(cur)) {
                indegree[next]--;
                dp[next] = Math.max(dp[next], dp[cur] + time[next]);
                if(indegree[next] == 0) {
                    q.add(next);
                }
            }
        }

        /*for(int i = 1 ; i <= N ; i++) {
            System.out.print(dp[i] + " ");
        }
        System.out.println();*/
        System.out.println(answer);


    }
}