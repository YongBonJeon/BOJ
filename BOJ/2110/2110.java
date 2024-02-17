import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N, C;
    static int[] home;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        C = sc.nextInt();

        home = new int[N];
        for (int i = 0; i < N; i++) {
            home[i] = sc.nextInt();
        }

        Arrays.sort(home);

        int left = 1;
        int right = home[N - 1] - home[0];
        int result = 0;

        while (left <= right) {

            // 최소 거리
            int mid = (left + right) / 2;
            int recentInstall = home[0];

            // 공유기 설치 수
            int count = 1;

            for (int i = 1; i < N; i++) {
                int distance = home[i] - recentInstall;

                // 최소 거리보다 크거나 같으면 설치
                if (mid <= distance) {
                    recentInstall = home[i];
                    count++;
                }
            }

            // 공유기 설치 수가 C보다 크거나 같으면 결과값 저장
            if (count >= C) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(result);



    }

}
