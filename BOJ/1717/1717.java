import java.util.*;

public class Main {
    static int N, M;
    static int[] parent;

    static int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
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
            int op = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();

            if(op == 0)
                union(a, b);
            else if(op == 1)
                System.out.println(find(a) == find(b) ? "YES" : "NO");
        }
    }
}