import java.util.*;
public class Main {
    static int N, S;
    static int[] arr;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        S = sc.nextInt();

        arr = new int[N];
        List<Integer> left = new ArrayList<>(), right = new ArrayList<>();

        for(int i = 0 ; i < N ; i++)
            arr[i] = sc.nextInt();

        dfs(0, 0,N/2, left);
        dfs(N/2, 0, N, right);


        Collections.sort(left);
        Collections.sort(right);

        int l = 0, r = right.size() - 1;

        Long count = 0L;
        while(l < left.size() && r >= 0) {
            int a = left.get(l), b = right.get(r);
            int temp = a+b;
            if(temp == S) {
                Long cnt1 = 0L, cnt2 = 0L;
                while (l < left.size() && left.get(l) == a){
                    l++;
                    cnt1++;
                }
                while (r >= 0 && right.get(r) == b){
                    r--;
                    cnt2++;
                }
                count += cnt1*cnt2;
            }
            else if(temp > S) {
                r--;
            } else if(temp < S) {
                l++;
            }
        }
        if(S == 0)
            System.out.println(count-1);
        else System.out.println(count);
    }

    private static void dfs(int index, int sum, int limit, List<Integer> list) {
        if(index == limit) {
            list.add(sum);
            return;
        }

        dfs(index + 1, sum + arr[index], limit, list);
        dfs(index + 1, sum, limit, list);
    }
}