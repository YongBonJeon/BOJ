import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        PriorityQueue pq = new PriorityQueue();

        for (int i = 0; i < N; i++) {
            int num = sc.nextInt();
            pq.add(num);
        }

        int ans = 0;
        while (pq.size() != 1) {
            int a = (int) pq.poll();
            int b = (int) pq.poll();
            ans += a + b;
            pq.add(a + b);
        }

        System.out.println(ans);
    }

}