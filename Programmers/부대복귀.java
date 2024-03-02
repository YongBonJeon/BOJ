import java.util.*;
class Solution {

    List<List<Integer>> graph = new ArrayList<>();
    int[] dist;

    class Node {
        int dest;
        int weight;

        public Node(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];

        for(int i = 0 ; i <= n ; i++) {
            graph.add(new ArrayList<>());
        }

        for(int i = 0 ; i < roads.length ; i++) {
            graph.get(roads[i][0]).add(roads[i][1]);
            graph.get(roads[i][1]).add(roads[i][0]);
        }

        dijkstra(n, destination);

        int idx = 0;
        for(int i = 0 ; i < sources.length ; i++) {
            if(dist[sources[i]] == Integer.MAX_VALUE)
                answer[i] = -1;
            else
                answer[i] = dist[sources[i]];
        }

        return answer;
    }

    private void dijkstra(int n, int st) {
        dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.weight - o2.weight);
        pq.add(new Node(st, 0));
        dist[st] = 0;

        while(!pq.isEmpty()) {
            Node cur = pq.poll();

            if(dist[cur.dest] < cur.weight) continue;

            for(Integer next : graph.get(cur.dest)) {
                if(dist[next] > dist[cur.dest] + 1) {
                    dist[next] = dist[cur.dest] + 1;
                    pq.add(new Node(next, cur.weight + 1));
                }
            }
        }
    }
}