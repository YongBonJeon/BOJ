import java.util.*;

public class Main {
    static int T, K;
    static String W;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();

        while(T-- > 0) {
            W = sc.next();
            K = sc.nextInt();

            if(K == 1) {
                System.out.println("1 1");
                continue;
            }

            int[] index = new int[26];

            int min = Integer.MAX_VALUE, max = 0;
            for (int i = 0; i < W.length(); i++)
                index[W.charAt(i) - 'a']++;

            for (int i = 0; i < W.length(); i++) {
                if (index[W.charAt(i) - 'a'] < K) continue;

                int count = 1;
                for (int j = i + 1; j < W.length(); j++) {
                    if (W.charAt(j) == W.charAt(i)) count++;

                    if (count == K) {
                        min = Math.min(min, j - i + 1);
                        max = Math.max(max, j - i + 1);
                        break;
                    }
                }
            }
            if (max == 0 || min == Integer.MAX_VALUE)
                System.out.println(-1);
            else
                System.out.println(min + " " + max);
        }

    }
}