import java.util.*;

public class Main {
    static int N;
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        arr = new int[N];
        for(int i=0; i<N; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);

        int result = 0;

        for(int i=0; i<N; i++) {
            if(twoPointer(i)) {
                result++;
            }
        }
        System.out.println(result);

    }

    private static boolean twoPointer(int i) {
        int left = 0;
        int right = N-1;
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(left == i) {
                left++;
                continue;
            } else if(right == i) {
                right--;
                continue;
            }
            if(sum == arr[i]) {
                return true;
            } else if(sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }


}