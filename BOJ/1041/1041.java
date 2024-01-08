import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Long N = sc.nextLong();
        Long min = Long.MAX_VALUE;
        Long max = 0L;
        List<Long> list = new ArrayList<>();

        for (int i = 0; i < 6; i++) {
            Long temp = sc.nextLong();
            list.add(temp);
            min = Math.min(min, temp);
            max = Math.max(max, temp);
        }

        Long min_twosum = Long.MAX_VALUE;
        Long min_threesum = Long.MAX_VALUE;

        for (int i = 0; i < 6; i++) {
            for (int j = i+1; j < 6; j++) {
                if(i == 0 && j == 5) continue;
                if(i == 1 && j == 4) continue;
                if(i == 2 && j == 3) continue;

                min_twosum = Math.min(list.get(i) + list.get(j), min_twosum);
            }
        }

        min_threesum = Math.min(list.get(0) + list.get(1) + list.get(2), min_threesum);
        min_threesum = Math.min(list.get(0) + list.get(1) + list.get(3), min_threesum);
        min_threesum = Math.min(list.get(0) + list.get(2) + list.get(4), min_threesum);
        min_threesum = Math.min(list.get(0) + list.get(3) + list.get(4), min_threesum);
        min_threesum = Math.min(list.get(1) + list.get(2) + list.get(5), min_threesum);
        min_threesum = Math.min(list.get(1) + list.get(3) + list.get(5), min_threesum);
        min_threesum = Math.min(list.get(2) + list.get(4) + list.get(5), min_threesum);
        min_threesum = Math.min(list.get(3) + list.get(4) + list.get(5), min_threesum);

        Long ans = 0L;

        if (N == 1) {
            System.out.println(list.stream().mapToLong(Long::longValue).sum() - max);
            return ;
        }

        // 보이는 면 가장자리를 제외한 공간
        ans += (N - 2) * (N - 2) * min * 5L;
        // 보이는 면 가장자리를 제외한 제일 하단 공간
        ans += (N - 2) * 4L * min;
        // 보이는 8가지 모서리
        ans += (N - 2) * 8L * min_twosum;
        // 하단 4개의 꼭짓점
        ans += 4L * min_twosum;
        // 상단 4개의 꼭짓점
        ans += 4L * min_threesum;

        sc.close();
        /*System.out.println((N - 2) * (N - 2)*5
                + (N - 2) * 4 + (N - 2) * 8*2 + 4*2 + 4*3);
        System.out.println(N*N*5);
        System.out.println("min_twosum = " + min_twosum);
        System.out.println("min_threesum = " + min_threesum);*/
        System.out.println(ans);
    }
}