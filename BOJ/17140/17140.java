import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int[][] arr = new int[101][101];
    static int r, c, k, num_row = 3, num_col = 3;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        k = sc.nextInt();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int sec = 0;
        while (sec <= 100) {
            if(arr[r-1][c-1] == k)
                break;
            if (num_row >= num_col) {
                r_operation();
            } else {
                c_operation();
            }
            /*System.out.println("sec = " + sec);
            for(int i = 0 ; i < num_row ; i++) {
                for(int j = 0 ; j < num_col ; j++) {
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();
            }*/
            sec++;
        }
        if(sec == 101)
            System.out.println(-1);
        else
            System.out.println(sec);
    }

    private static void r_operation() {
        int max_col = num_col;
        int[][] newArr = new int[101][101];
        for (int row = 0; row < num_row ; row++) {
            int[] cnt = new int[101];

            int max_value = 0;
            for(int col = 0 ; col < num_col ; col++) {
                if(arr[row][col] == 0) continue;
                cnt[arr[row][col]]++;

                max_value = Math.max(max_value, arr[row][col]);
            }

            /*System.out.println("cnt");
            for(int col = 0 ; col <= max_value ; col++) {
                System.out.print(cnt[col] + " ");
            }
            System.out.println();*/

            PriorityQueue<Temp> pq = new PriorityQueue<>(new Comparator<Temp>() {
                @Override
                public int compare(Temp o1, Temp o2) {
                    if(o1.cnt == o2.cnt)
                        return o1.idx - o2.idx;
                    return o1.cnt - o2.cnt;
                }
            });
            for(int col = 0 ; col <= max_value ; col++) {
                if(cnt[col] != 0)
                    pq.add(new Temp(col, cnt[col]));
            }

            int[] newRow = new int[num_col*2];
            int idx = 0;
            while (!pq.isEmpty()) {
                Temp t = pq.poll();
                newRow[idx++] = t.idx;
                newRow[idx++] = t.cnt;
            }

            max_col = Math.max(max_col, idx);

            for(int col = 0 ; col < idx ; col++) {
                newArr[row][col] = newRow[col];
            }

            /*System.out.println("newRow");
            for(int col = 0 ; col < idx ; col++)
                System.out.print(newRow[col] + " ");
            System.out.println();*/
        }
        num_col = max_col;
        for(int i = 0 ; i < num_row ; i++)
            for(int j = 0 ; j < num_col ; j++)
                arr[i][j] = newArr[i][j];
    }

    private static void c_operation() {
        int max_row = num_row;
        int[][] newArr = new int[101][101];
        for (int col = 0; col < num_col ; col++) {
            int[] cnt = new int[101];

            int max_value = 0;
            for(int row = 0 ; row < num_row ; row++) {
                if(arr[row][col] == 0) continue;
                cnt[arr[row][col]]++;

                max_value = Math.max(max_value, arr[row][col]);
            }

            /*System.out.println("cnt");
            for(int row = 0 ; row <= max_value ; row++) {
                System.out.print(cnt[row] + " ");
            }
            System.out.println();*/

            PriorityQueue<Temp> pq = new PriorityQueue<>(new Comparator<Temp>() {
                @Override
                public int compare(Temp o1, Temp o2) {
                    if(o1.cnt == o2.cnt)
                        return o1.idx - o2.idx;
                    return o1.cnt - o2.cnt;
                }
            });
            for(int row = 0 ; row <= max_value ; row++) {
                if(cnt[row] != 0)
                    pq.add(new Temp(row, cnt[row]));
            }

            int[] newCol = new int[num_row*2];
            int idx = 0;
            while (!pq.isEmpty()) {
                Temp t = pq.poll();
                newCol[idx++] = t.idx;
                newCol[idx++] = t.cnt;
            }

            max_row = Math.max(max_row, idx);

            for(int row = 0 ; row < idx ; row++) {
                newArr[row][col] = newCol[row];
            }

            /*System.out.println("newCol");
            for(int row = 0 ; row < idx ; row++)
                System.out.print(newCol[row] + " ");
            System.out.println();*/
        }
        num_row = max_row;
        for(int i = 0 ; i < num_row ; i++)
            for(int j = 0 ; j < num_col ; j++)
                arr[i][j] = newArr[i][j];
    }

    private static class Temp {
        int idx;
        int cnt;

        public Temp(int idx, int cnt) {
            this.idx = idx;
            this.cnt = cnt;
        }
    }
}