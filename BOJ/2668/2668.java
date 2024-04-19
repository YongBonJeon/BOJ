import java.util.*;

public class Main {
    static int N;
    static int[] uArray, dArray, index;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        uArray = new int[N+1];
        dArray = new int[N+1];
        index = new int[N+1];

        Arrays.fill(uArray, 1);

        for(int i = 1 ; i <= N ; i++) {
            index[i] = sc.nextInt();
            dArray[index[i]]++;
        }

        Queue<Integer> q = new ArrayDeque<>();
        for(int i = 1 ; i <= N ; i++) {
            if(dArray[i] == 0)
                q.add(i);
        }

        while(!q.isEmpty()) {
            Integer cur = q.poll();

            uArray[cur]--;
            dArray[index[cur]]--;

            if(dArray[index[cur]] == 0)
                q.add(index[cur]);
        }

        List<Integer> answer = new ArrayList<>();
        for(int i = 1 ; i <= N ; i++) {
            if(uArray[i] > 0 && dArray[i] > 0)
                answer.add(i);
        }
        System.out.println(answer.size());
        for(Integer n : answer)
            System.out.println(n);
    }

}