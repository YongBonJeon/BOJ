import java.awt.*;
import java.util.*;
import java.util.List;

public class Main {

    static int N;
    static int[] parent;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) parent[y] = x;
    }

    static class Edge {
        int from, to, weight;
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        parent = new int[N+1];
        List<Edge> edges = new ArrayList<>();
        int totalLength = 0;

        String temp;
        for(int i = 1; i <= N; i++) {
            parent[i] = i;

            temp = sc.next();
            for(int j = 1; j <= N; j++) {
                int weight;
                if(temp.charAt(j-1) == '0') continue;
                else if(temp.charAt(j-1) <= 'z' && temp.charAt(j-1) >= 'a') {
                    weight = temp.charAt(j-1) - 'a' + 1;
                    edges.add(new Edge(i, j, weight));
                } else {
                    weight = temp.charAt(j-1) - 'A' + 27;
                    edges.add(new Edge(i, j, weight));
                }
                totalLength += weight;
            }
        }

        Collections.sort(edges, (a, b) -> a.weight - b.weight);

        for(Edge edge : edges) {
            if(find(edge.from) != find(edge.to)) {
                union(edge.from, edge.to);
                totalLength -= edge.weight;
            }
        }

        if(checkConnection())
            System.out.println(totalLength);
        else
            System.out.println(-1);


    }

    private static boolean checkConnection() {
        int root = find(1);
        for(int i = 2; i <= N; i++) {
            if(root != find(i)) {
                return false;
            }
        }
        return true;
    }



}
