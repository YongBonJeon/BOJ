import java.util.*;

public class Main {

    static int T, N, M, W;

    static class Edge {
        int from;
        int to;
        int cost;

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public String toString() {
            return "Edge{" +
                    "from=" + from +
                    ", to=" + to +
                    ", cost=" + cost +
                    '}';
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();

        for(int i = 0; i < T; i++) {
            N = sc.nextInt();
            M = sc.nextInt();
            W = sc.nextInt();

            List<Edge> graph = new ArrayList<>();

            for(int j = 0; j < M; j++) {
                int s = sc.nextInt();
                int e = sc.nextInt();
                int t = sc.nextInt();
                graph.add(new Edge(s, e, t));
                graph.add(new Edge(e, s, t));
            }
            for (int j = 0; j < W; j++) {
                int s = sc.nextInt();
                int e = sc.nextInt();
                int t = sc.nextInt();
                graph.add(new Edge(s, e, -1*t));
            }

            boolean isMinusCycle = false;
            if(isMinusCycle(graph)) {
                isMinusCycle = true;
            }
            System.out.println(isMinusCycle ? "YES" : "NO");
        }
    }

    private static boolean isMinusCycle(List<Edge> graph) {
        int[] dist = new int[N + 1];

        boolean update = false;
        for(int i = 0; i < N; i++) {
            update = false;
            for(int j = 0; j < M*2+W; j++) {
                Edge edge = graph.get(j);

                if(dist[edge.to] > dist[edge.from] + edge.cost) {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                    update = true;
                    if(i == N-1) {
                        return true;
                    }
                }
            }
            if(!update) {
                break;
            }
        }
        return false;
    }


}