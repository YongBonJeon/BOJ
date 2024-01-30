import java.lang.reflect.Array;
import java.util.*;

public class Main {

    static class Edge {
        int node;
        int weight;

        public Edge(int node, int weight){
            this.node = node;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "Edge{" +
                    "node=" + node +
                    ", weight=" + weight +
                    '}';
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();


        List<List<Edge>> graph = new ArrayList<>();
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < M; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            graph.get(u).add(new Edge(v, w));
            graph.get(v).add(new Edge(u, w));
        }
        int start = sc.nextInt();
        int end = sc.nextInt();

        int[] dist = new int[N+1];

        dist[start] = Integer.MAX_VALUE;

        PriorityQueue<Edge> q = new PriorityQueue<>((a, b) -> b.weight - a.weight);

        q.add(new Edge(start, Integer.MAX_VALUE));

        while(!q.isEmpty()){
            Edge edge = q.poll();
            if(edge.weight < dist[edge.node]) continue;

            for(Edge next : graph.get(edge.node)){
                if(dist[next.node] < Math.min(edge.weight, next.weight)){
                    dist[next.node] = Math.min(edge.weight, next.weight);
                    q.add(new Edge(next.node, dist[next.node]));
                }
            }
        }
        System.out.println(dist[end]);
    }
}