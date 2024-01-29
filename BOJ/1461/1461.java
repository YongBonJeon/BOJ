import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < N; i++){
            list.add(sc.nextInt());
        }

        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Math.abs(o2) - Math.abs(o1);
            }
        });

        int ans = 0;

        // 처음 M개는 편도
        int d = list.get(0);
        ans += Math.abs(d);
        list.remove(0);
        int num = 1;
        List<Integer> temp = new ArrayList<>();
        for (Integer i : list) {
            if(num == M) break;
            if (i * d > 0) {
                temp.add(i);
                num++;
            }
        }
        list.removeAll(temp);

        while(!list.isEmpty()) {
            // 나머지는 왕복
            d = list.get(0);
            ans += 2 * Math.abs(d);
            list.remove(0);
            num = 1;
            temp = new ArrayList<>();
            for (Integer i : list) {
                if(list.isEmpty()) break;
                if(num == M) break;
                if (i * d > 0) {
                    temp.add(i);
                    num++;
                }
            }
            list.removeAll(temp);
        }

        System.out.println(ans);

    }



}