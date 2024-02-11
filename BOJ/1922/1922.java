import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N, M;
    static int[] parent;
    static ArrayList<Edge> edges = new ArrayList<>();

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    private static class Edge {
        int a,b,cost;


        public Edge(int a, int b, int cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        parent = new int[N+1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int cost = sc.nextInt();
            edges.add(new Edge(a, b, cost));
        }

        edges.sort((o1, o2) -> o1.cost - o2.cost);

        int result = 0;

        for (Edge edge : edges) {
            int a = edge.a;
            int b = edge.b;
            int cost = edge.cost;

            if (find(a) != find(b)) {
                union(a, b);
                result += cost;
            }
        }
        System.out.println(result);
    }
}