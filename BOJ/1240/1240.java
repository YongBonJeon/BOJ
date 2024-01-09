import java.util.*;

public class Main {
    static int[] visited;
    static int ans;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Integer N = sc.nextInt();
        Integer M = sc.nextInt();

        List<List<int[]>> tree = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            tree.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; i++) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            int dist = sc.nextInt();

            tree.get(n1-1).add(new int[]{n2-1, dist});
            tree.get(n2-1).add(new int[]{n1-1, dist});
        }

        for (int i = 0; i < M; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();

            visited = new int[N+1];
            ans = 0;
            dfs(tree, from - 1, to - 1, 0);
            System.out.println(ans);
        }
    }

    private static void dfs(List<List<int[]>> tree, int from, int to, int dist) {
        if (from == to) {
            ans = dist;
            return ;
        }
        //System.out.println(from + " " + dist);
        visited[from] = 1;

        for (int[] ints : tree.get(from)) {
            if(visited[ints[0]] == 0)
                dfs(tree, ints[0], to, dist + ints[1]);
        }
    }


}