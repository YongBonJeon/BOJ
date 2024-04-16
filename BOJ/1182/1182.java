import java.util.*;
public class Main {
    static int N, S, count = 0;
    static int[] arr;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        S = sc.nextInt();

        arr = new int[N];

        for(int i = 0 ; i < N ; i++)
            arr[i] = sc.nextInt();

        dfs(0, 0, 0);

        System.out.println(count);
    }

    private static void dfs(int index, int sum, int num) {
        if(index == N) {
            if (sum == S && num > 0) {
                //System.out.println(index + " " + num);
                count++;
            }
            return;
        }


        dfs(index + 1, sum + arr[index], num + 1);
        dfs(index + 1, sum, num);
    }
}