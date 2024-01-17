import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int[][] lecture = new int[N][2];
        for (int i = 0; i < N; i++) {
            lecture[i][0] = sc.nextInt();
            lecture[i][1] = sc.nextInt();
        }
        Arrays.sort(lecture, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] != o2[0] ? o1[0] - o2[0] : o1[1] - o2[0];
            }
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(lecture[0][1]);

        for (int i = 1; i < N; i++) {
            if (pq.peek() <= lecture[i][0]) {
                pq.poll();
            }
            pq.add(lecture[i][1]);
        }


        System.out.println(pq.size());
    }

}