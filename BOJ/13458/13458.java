import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int N, B, C;
        long ans = 0;
        int[] tester;

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        tester = new int[N];
        for(int i = 0 ; i < N ; i++)
            tester[i] = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();


        for(int i = 0 ; i < N ; i++) {
            tester[i] -= B;
            tester[i] = Math.max(tester[i], 0);
        }
        ans += N;

        for(int i = 0 ; i < N ; i++) {
            ans += tester[i] / C;
            if(tester[i] % C != 0) ans +=1 ;
        }
        System.out.println(ans);
    }
}
