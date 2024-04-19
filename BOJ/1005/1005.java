import java.util.*;

public class Main {
    static int T, N, K, target;
    static int[] cost, indegree;
    static List<List<Integer>> graph;

    static class Node {
        int num, time;

        Node(int num, int time) {
            this.num = num;
            this.time = time;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();

        while(T-- > 0) {
            N = sc.nextInt();
            K = sc.nextInt();

            int[] answer = new int[N+1];

            cost = new int[N+1];
            for(int i = 1 ; i <= N ; i++) {
                cost[i] = sc.nextInt();
                answer[i] = cost[i];
            }

            indegree = new int[N+1];
            graph = new ArrayList<>();
            for(int i = 0 ; i <= N ; i++)
                graph.add(new ArrayList<>());

            for(int i = 0 ; i < K ; i++) {
                int X = sc.nextInt();
                int Y = sc.nextInt();
                graph.get(X).add(Y);
                indegree[Y]++;
            }

            target = sc.nextInt();

            PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> {
                return o1.time - o2.time;
            });
            for(int i = 1 ; i <= N ; i++)
                if(indegree[i] == 0)
                    pq.add(new Node(i, 0));

            while(!pq.isEmpty()) {
                Node cur = pq.poll();

                for(Integer next : graph.get(cur.num)) {
                    answer[next] = Math.max(answer[next], answer[cur.num] + cost[next]);
                    //System.out.println(answer[next]);
                    indegree[next]--;
                    if(indegree[next] == 0)
                        pq.add(new Node(next, cur.time + 1));
                }
            }

            System.out.println(answer[target]);
        }


    }

}