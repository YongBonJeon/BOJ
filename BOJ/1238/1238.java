import java.util.*;

public class Main {

    static int N;
    static int M;
    static int X;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        X = sc.nextInt();

        List<List<Edge>> graph = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            int cost = sc.nextInt();
            graph.get(from).add(new Edge(to, cost));
        }

        int[] allToX = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            if(i != X)
                allToX[i] = dijkstra(graph, i, X);
        }
        int ans = 0;

        for (int i = 1; i <= N; i++) {
            if(i == X) continue;
            int fromX = dijkstra(graph, X, i);
            ans = Math.max(ans, allToX[i] + fromX);
        }

        System.out.println(ans);

    }

    private static int dijkstra(List<List<Edge>> graph, int i, int target) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[i] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.cost - b.cost);
        pq.add(new Edge(i, 0));

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int now = edge.to;
            int cost = edge.cost;

            if (dist[now] < cost) {
                continue;
            }

            for (Edge next : graph.get(now)) {
                int nextNode = next.to;
                int nextCost = cost + next.cost;

                if (dist[nextNode] > nextCost) {
                    dist[nextNode] = nextCost;
                    pq.add(new Edge(nextNode, nextCost));
                }
            }
        }
        return dist[target];
    }


    private static class Edge {
        int to;
        int cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
}