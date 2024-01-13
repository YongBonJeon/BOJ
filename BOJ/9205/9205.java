import java.util.*;

public class Main {

    static class Pair {
        int y;
        int x;
        boolean visited = false;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "y=" + y +
                    ", x=" + x +
                    ", visited=" + visited +
                    '}';
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();

            List<Pair> data = new ArrayList<>();

            int starty = sc.nextInt();
            int startx = sc.nextInt();
            Pair start = new Pair(starty, startx);
            start.visited = true;
            data.add(start);

            for (int i = 0; i < N; i++) {
                Pair pair = new Pair(0,0);
                pair.y = sc.nextInt();
                pair.x = sc.nextInt();

                data.add(pair);
            }

            int endy = sc.nextInt();
            int endx = sc.nextInt();

            data.add(new Pair(endy, endx));

            Queue<Pair> q = new ArrayDeque<>();
            q.add(start);

            boolean happyFlag = false;
            while (!q.isEmpty()) {
                Pair cur = q.poll();

                //System.out.println("cur" + cur.y + " " + cur.x);

                if (cur.y == endy && cur.x == endx) {
                    System.out.println("happy");
                    happyFlag = true;
                    break;
                }

                for (Pair p : data) {
                    if(p.visited) continue;
                    int dist = Math.abs(cur.y - p.y) + Math.abs(cur.x - p.x);

                    if (Math.abs(dist) <= 1000) {
                        p.visited = true;
                        q.add(p);
                    }
                }
            }
            if(!happyFlag)
                System.out.println("sad");
        }
    }

}