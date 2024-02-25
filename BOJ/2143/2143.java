import java.awt.*;
import java.util.*;
import java.util.List;

public class Main {

    static int T, N, M;
    static int[] arr1, arr2;
    static Map<Integer, Integer> Nmap = new HashMap<>();


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        N = sc.nextInt();
        arr1 = new int[N];
        for (int i = 0; i < N; i++) {
            arr1[i] = sc.nextInt();
        }
        M = sc.nextInt();
        arr2 = new int[M];
        for (int i = 0; i < M; i++) {
            arr2[i] = sc.nextInt();
        }

        int[] temp = new int[N];
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr1[i];
            temp[i] = sum;
        }
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                int sum2 = temp[j] - temp[i] + arr1[i];
                Nmap.put(sum2, Nmap.getOrDefault(sum2, 0) + 1);
            }
        }

        int[] temp2 = new int[M];
        sum = 0;
        for (int i = 0; i < M; i++) {
            sum += arr2[i];
            temp2[i] = sum;
        }
        long ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = i; j < M; j++) {
                int sum2 = temp2[j] - temp2[i] + arr2[i];
                ans += Nmap.getOrDefault(T - sum2, 0);
            }
        }
        System.out.println(ans);


    }

}
