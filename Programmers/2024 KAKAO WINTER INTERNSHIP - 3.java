import java.util.*;

class Solution {
    List<Integer> answer;
    int min = 987654321;
    public int[] solution(int[][] dice) {


        int N = dice.length;

        // 주사위를 N / 2 번 고르는 경우의 수
        List<Integer> list = new ArrayList<>();
        answer = new ArrayList<>();

        List<Integer> test1 = new ArrayList<>();
        List<Integer> test2 = new ArrayList<>();
        test1.add(1); test1.add(2);
        test2.add(3); test2.add(4);
        //solve(test1, test2, dice);
        pick(N, 1, list, dice);

        int[] ans = new int[N/2];

        for(int i = 0 ; i < answer.size() ; i++){
            ans[i] = answer.get(i);
        }

        return ans;
    }

    public void pick(int N, int cur, List<Integer> list, int[][] dice) {
        if(list.size() == N/2) {
            List<Integer> B = new ArrayList<>();
            for(int i = 1 ; i <= N ; i++)
                if(!list.contains(i))
                    B.add(i);

            int temp;
            if((temp = solve(list,B,dice)) < min){
                min = temp;
                answer = new ArrayList<>(list);
            }
        }

        for(int i = cur ; i <= N ; i++) {
            list.add(i);
            pick(N, i+1, list, dice);
            list.remove(Integer.valueOf(i));
        }
    }

    public Integer solve(List<Integer> A, List<Integer> B, int[][] dice) {

        Queue<Integer> queue = new LinkedList<>();
        Queue<Integer> queue_new = new LinkedList<>();

        queue.add(0);
        for(int i = 0 ; i < A.size() ; i++) {
            int size = queue.size();
            for(int s = 0 ; s < size ; s++) {
                int cur = queue.poll();

                for(int j = 0 ; j < 6 ; j++) {
                    queue.add(cur + dice[A.get(i)-1][j]);
                }
            }
        }
        int[] temp = new int[501];
        while(!queue.isEmpty()) {
            temp[queue.poll()] += 1;
        }

        int[] statusA = new int[501];

        int sum = 0;
        for(int i = 0 ; i < 501 ; i++) {
            sum += temp[i];
            statusA[i] = sum;
        }

        int ans = 0;

        queue = new LinkedList<>();

        queue.add(0);
        for(int i = 0 ; i < B.size() ; i++) {
            int size = queue.size();
            for(int s = 0 ; s < size ; s++) {
                int cur = queue.poll();

                for(int j = 0 ; j < 6 ; j++) {
                    queue.add(cur + dice[B.get(i)-1][j]);
                }
            }
        }
        temp = new int[501];
        while(!queue.isEmpty()) {
            temp[queue.poll()] += 1;
        }
        for(int i = 0 ; i < 501 ; i++) {
            ans += statusA[i]*temp[i];
        }
        return ans;
    }
}

/*
import java.util.*;

class Solution {
    List<Integer> answer;
    int min = 987654321;
    public int[] solution(int[][] dice) {


        int N = dice.length;

        // 주사위를 N / 2 번 고르는 경우의 수
        List<Integer> list = new ArrayList<>();
        answer = new ArrayList<>();
        pick(N, 1, list, dice);

        int[] ans = new int[N/2];

        for(int i = 0 ; i < answer.size() ; i++){
            ans[i] = answer.get(i);
        }

        return ans;
    }

    public void pick(int N, int cur, List<Integer> list, int[][] dice) {
        if(list.size() == N/2) {
            List<Integer> B = new ArrayList<>();
            for(int i = 1 ; i <= N ; i++)
                if(!list.contains(i))
                    B.add(i);

            int temp;
            if((temp = solve(list,B,dice)) < min){
                min = temp;
                answer = new ArrayList<>(list);
            }
        }

        for(int i = cur ; i <= N ; i++) {
            list.add(i);
            pick(N, i+1, list, dice);
            list.remove(Integer.valueOf(i));
        }
    }

    public Integer solve(List<Integer> A, List<Integer> B, int[][] dice) {
        */
/*System.out.println("A");
        for(Integer a : A)
            System.out.print(a + " ");
        System.out.println();

        for(Integer b : B)
            System.out.print(b + " ");
        System.out.println();
        *//*



        Map<Integer, Integer> num = new HashMap<>();
        Map<Integer, Integer> num1 = new HashMap<>();

        for(int i = 0 ; i < 6 ; i++){
            Integer v = num.getOrDefault(dice[A.get(0)-1][i], 0);
            num.put(dice[A.get(0)-1][i], v+1);
        }

        for(int a = 1 ; a < A.size() ; a++) {
            for (Map.Entry<Integer, Integer> entry : num.entrySet()) {
                for(int i = 0 ; i < 6 ; i++) {
                    Integer v = num1.getOrDefault(entry.getKey()+dice[A.get(a)-1][i], 0);
                    num1.put(entry.getKey()+dice[A.get(a)-1][i], v+entry.getValue());
                }
            }
            num = num1;
        }

        */
/*System.out.println("A 상태");
        for (Map.Entry<Integer, Integer> entry : num.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }*//*


        int[] statusA = new int[501];

        int sum = 0;
        for(int i = 0 ; i < 501 ; i++) {
            sum += num.getOrDefault(i,0);
            statusA[i] = sum;
        }
        */
/*System.out.println("A 자료구조 ");
        for(int i = 0 ; i <= 10 ; i++)
            System.out.println(i + " " + statusA[i] + " ");
        System.out.println();
         *//*

        num = new HashMap<>();
        num1 = new HashMap<>();
        int ans = 0;

        for(int i = 0 ; i < 6 ; i++){
            Integer v = num.getOrDefault(dice[B.get(0)-1][i], 0);
            num.put(dice[B.get(0)-1][i], v+1);
        }

        for(int b = 1 ; b < B.size() ; b++) {
            for (Map.Entry<Integer, Integer> entry : num.entrySet()) {
                for(int i = 0 ; i < 6 ; i++) {
                    Integer v = num1.getOrDefault(entry.getKey()+dice[B.get(b)-1][i], 0);
                    num1.put(entry.getKey()+dice[B.get(b)-1][i], v+entry.getValue());
                }
            }
            num = num1;
        }

        */
/*System.out.println("B 상태");
        for(Integer b : B)
            System.out.print(b + " ");
        System.out.println();*//*

        for(Map.Entry<Integer, Integer> entry : num.entrySet()) {
            //System.out.println(entry.getKey() + " " + entry.getValue() + " " + statusA[entry.getKey()-1]);
            ans += statusA[entry.getKey()-1]*entry.getValue();
        }
        //System.out.println("ans " + ans);

        return ans;
    }
}*/
