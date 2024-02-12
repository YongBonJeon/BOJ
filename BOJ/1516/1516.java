import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N;
    static int[] time;
    static int[] degree;

    static List<List<Integer>> graph = new ArrayList<>();



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        time = new int[N+1];
        degree = new int[N+1];

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int a = 1; a <= N; a++) {
            time[a] = sc.nextInt();

            int b;
            while ((b = sc.nextInt()) != -1) {
                graph.get(b).add(a);
                degree[a]++;
            }
        }

        topologicalSort();
    }

    private static void topologicalSort() {
        Queue<Integer> queue = new LinkedList<>();
        int[] result = new int[N+1];

        for (int a = 1; a <= N; a++) {
            result[a] = time[a];

            // 선행 작업이 없는 작업을 큐에 삽입
            if (degree[a] == 0) {
                queue.add(a);
            }
        }

        while (!queue.isEmpty()) {
            int a = queue.poll();

            for (int b : graph.get(a)) {
                degree[b]--;
                result[b] = Math.max(result[b], result[a] + time[b]);
                if (degree[b] == 0) {
                    queue.add(b);
                }
            }
        }

        for (int a = 1; a <= N; a++) {
            System.out.println(result[a]);
        }
    }
}
