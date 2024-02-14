import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N, M;
    static int[] price;

    static class unit {
        int rest_money;
        List<Integer> buy_list;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        price = new int[N];
        for (int i = 0; i < N; i++) {
            price[i] = sc.nextInt();
        }
        M = sc.nextInt();

        int rest = M;
        String ans = "";
        // 0이 아닌 수 중 가장 싼 값을 첫번째
        int minValue = 100000;
        int minIdx = 1;
        for (int i = 1; i < N; i++) {
            if (price[i] < minValue) {
                minValue = price[i];
                minIdx = i;
            }
        }
        if(rest >= minValue) {
            ans += minIdx;
            rest -= price[minIdx];
        }
        // 0포함 가장 싼 값으로 나머지 다 채움
        if(minValue > price[0]) {
            minIdx = 0;
            minValue = price[0];
        }

        while(rest >= minValue) {
            ans += minIdx;
            rest -= minValue;
        }

        // 처음 숫자부터 가능하다면 제일 큰 값으로 변경
        for (int i = 0; i < ans.length(); i++) {
            if (rest < 0) break;
            for (int j = N - 1; j >= 0; j--) {
                if (price[j] - price[ans.charAt(i) - '0'] <= rest) {
                    rest -= (price[j] - price[ans.charAt(i) - '0']);
                    ans = ans.substring(0, i) + j + ans.substring(i + 1);

                    break;
                }
            }
        }

        boolean allZero = true;
        for (int i = 0; i < ans.length(); i++) {
            if (ans.charAt(i) != '0') {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            System.out.println(0);
            return;
        }
        System.out.println(ans);

    }



}
