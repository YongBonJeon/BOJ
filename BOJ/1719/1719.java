import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    static int N, M;
    static List<List<Edge>> graph = new ArrayList<>();
    static int[][] ans;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            int weight = sc.nextInt();
            graph.get(from).add(new Edge(to, weight));
            graph.get(to).add(new Edge(from, weight));
        }

        ans = new int[N + 1][N + 1];

        for(int i = 1; i <= N; i++) {
            dijkstra(i);
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) System.out.print("- ");
                else System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }

    }

    private static void dijkstra(int st) {
        int[] dist = new int[N + 1];

        for (int j = 1; j <= N; j++) {
            dist[j] = Integer.MAX_VALUE;
        }

        dist[st] = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.weight - b.weight);
        pq.add(new Edge(st, 0));

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();

            if (dist[edge.to] < edge.weight) continue;

            for (Edge next : graph.get(edge.to)) {
                int nextDist = edge.weight + next.weight;

                if (nextDist < dist[next.to]) {
                    dist[next.to] = nextDist;
                    ans[next.to][st] = edge.to;
                    pq.add(new Edge(next.to, nextDist));
                }
            }
        }
    }

    private static class Edge {
        int to, weight;
        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }
}
