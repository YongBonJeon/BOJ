import java.util.*;
class Solution {
    class Edge {
        int v;
        int weight;

        Edge(int v, int weight) {
            this.v = v;
            this.weight = weight;
        }
    }
    List<List<Edge>> graph = new ArrayList<>();
    boolean[] isGate;
    boolean[] isSummit;

    int ans_summit;
    int ans_intensity = Integer.MAX_VALUE;
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {

        // 그래프 구성
        for(int i = 0 ; i <= n ; i++) {
            graph.add(new ArrayList<>());
        }
        for(int i = 0 ; i < paths.length ; i++) {
            graph.get(paths[i][0]).add(new Edge(paths[i][1], paths[i][2]));
            graph.get(paths[i][1]).add(new Edge(paths[i][0], paths[i][2]));
        }

        // 출입구, 산봉우리 간단 확인
        isGate = new boolean[n+1];
        isSummit = new boolean[n+1];
        for(int i = 0 ; i < gates.length ; i++)
            isGate[gates[i]] = true;
        for(int i = 0 ; i < summits.length ; i++)
            isSummit[summits[i]] = true;

        for(int i = 0 ; i < gates.length ; i++) {
            dijstra(n, gates[i]);
        }

        return new int[]{ans_summit, ans_intensity};
    }

    private void dijstra(int n, int st) {
        int[] dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> o1.weight - o2.weight);

        dist[st] = 0;
        pq.add(new Edge(st, 0));

        while(!pq.isEmpty()) {
            Edge cur = pq.poll();

            if(dist[cur.v] > ans_intensity || dist[cur.v] < cur.weight) continue;

            for(Edge next : graph.get(cur.v)) {
                if(isGate[next.v]) continue;

                if(dist[next.v] > Math.max(cur.weight, next.weight)) {
                    dist[next.v] = Math.max(cur.weight, next.weight);

                    if(dist[next.v] > ans_intensity) continue;

                    if(!isSummit[next.v])
                        pq.add(new Edge(next.v, dist[next.v]));
                    else {
                        if(ans_intensity > dist[next.v]) {
                            ans_intensity = dist[next.v];
                            ans_summit = next.v;
                        } else if(ans_intensity == dist[next.v]) {
                            ans_summit = Math.min(ans_summit, next.v);
                        }
                    }
                }
            }
        }
    }
}