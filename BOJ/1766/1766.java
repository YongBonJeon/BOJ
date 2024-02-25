import java.awt.*;
import java.util.*;
import java.util.List;

public class Main {

    static int N, M;
    static List<List<Integer>> graph = new ArrayList<>();
    static int[] inDegree;
    static List<Integer> result = new ArrayList<>();


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        inDegree = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b);
            inDegree[b]++;
        }

        topologicalSort();

        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + " ");
        }

    }

    private static void topologicalSort() {
        PriorityQueue<Integer> pq = new PriorityQueue<>();


        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) {
                pq.offer(i);
            }
        }

        while (!pq.isEmpty()) {
            int now = pq.poll();
            result.add(now);

            for (int i = 0; i < graph.get(now).size(); i++) {
                int next = graph.get(now).get(i);
                inDegree[next]--;

                if (inDegree[next] == 0) {
                    pq.offer(next);
                }
            }
        }
    }

}
