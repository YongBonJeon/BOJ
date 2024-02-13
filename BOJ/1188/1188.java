import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N, M;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        int length = N*M;
        int sausage = M;
        int slice_unit = N;

        int ans = 0;

        for(int i = slice_unit ; i < length ; i+=slice_unit){
            if(i % sausage != 0){
                ans++;
            }
        }
        System.out.println(ans);

    }

}
