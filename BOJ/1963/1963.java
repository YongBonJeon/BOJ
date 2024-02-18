import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int T;
    static String A, B;
    static int[] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            visited = new int[10000];

            int temp = sc.nextInt();
            A = String.valueOf(temp);
            temp = sc.nextInt();
            B = String.valueOf(temp);

            bfs(A, B);
        }




    }

    private static void bfs(String a, String b) {
        Queue<String> q = new LinkedList<>();
        q.add(a);
        visited[Integer.parseInt(a)] = 1;

        while(!q.isEmpty()) {
            String cur = q.poll();
            if(cur.equals(b)) {
                System.out.println(visited[Integer.parseInt(cur)] - 1);
                return;
            }

            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 10; j++) {
                    String next = cur.substring(0, i) + j + cur.substring(i+1);
                    if(next.charAt(0) == '0') continue;
                    if(isPrime(Integer.parseInt(next)) && visited[Integer.parseInt(next)] == 0) {
                        q.add(next);
                        visited[Integer.parseInt(next)] = visited[Integer.parseInt(cur)] + 1;
                    }
                }
            }
        }
        System.out.println("Impossible");
    }


    private static boolean isPrime(int parseInt) {
        if(parseInt == 1) return false;
        for(int i = 2; i <= Math.sqrt(parseInt); i++) {
            if(parseInt % i == 0) return false;
        }
        return true;
    }

}
