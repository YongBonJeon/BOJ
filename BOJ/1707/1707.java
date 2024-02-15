import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int T, V, E;

    static List<List<Integer>> graph;
    static int[] color;
    static int[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();

        while(T > 0) {
            V = sc.nextInt();
            E = sc.nextInt();
            boolean isBipartite = true;

            graph = new ArrayList<>();
            for(int i = 0; i <= V; i++) {
                graph.add(new ArrayList<>());
            }

            for(int i = 0; i < E; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();

                graph.get(a).add(b);
                graph.get(b).add(a);

                if(a == b) {
                    isBipartite = false;
                }
            }


            color = new int[V+1];
            visited = new int[V+1];
            for(int i = 1; i <= V; i++) {
                if(color[i] == 0) {
                    if(!bfs(i)) {
                        isBipartite = false;
                        System.out.println("NO");
                        break;
                    }
                }
            }
            if(isBipartite)
                System.out.println("YES");
            T--;
        }

    }

    private static boolean bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        color[start] = 1;
        visited[start] = 1;

        while(!q.isEmpty()) {
            int cur = q.poll();
            int curColor = color[cur];
            //System.out.println("cur: " + cur + " curColor: " + curColor);

            for(int next : graph.get(cur)) {
                // 미방문 노드
                if(visited[next] == 0) {
                    color[next] = -curColor;
                    visited[next] = 1;
                    q.add(next);
                }
                // 인접한 노드가 같은 색상
                else if(visited[next] == 1 && color[next] == curColor) {
                    return false;
                }
            }
        }
        return true;
    }


}
