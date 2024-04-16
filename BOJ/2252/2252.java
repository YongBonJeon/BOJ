import java.util.*;
public class Main {
    static int N, M;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        List<List<Integer>> map = new ArrayList<>();
        int[] indegree = new int[N+1];
        for(int i = 0 ; i <= N ; i++)
            map.add(new ArrayList<>());

        for(int i = 0 ; i < M ; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            map.get(A).add(B);
            indegree[B]++;
        }

        Queue<Integer> q = new ArrayDeque<>();

        for(int i = 1 ; i <= N ; i++) {
            if(indegree[i] == 0) {
                q.add(i);
            }
        }

        while(!q.isEmpty()) {
            int cur = q.poll();

            System.out.print(cur + " ");

            for(Integer next : map.get(cur)) {
                indegree[next]--;
                if(indegree[next] == 0)
                    q.add(next);
            }
        }
    }
}