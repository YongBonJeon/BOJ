import java.io.*;
import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N;
    static int[] nums;
    static int a,b;
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        nums = new int[N];
        for(int i=0; i<N; i++){
            nums[i] = sc.nextInt();
        }
        if(N == 1){
            System.out.println("A");
            return;
        } else if(N == 2 && nums[0] != nums[1]){
            System.out.println("A");
            return;
        } else if(N == 2){
            System.out.println(nums[0]);
            return;
        }

        if(nums[0] == nums[1]) {
            if(allEqual(0)){
                System.out.println(nums[0]);
            } else {
                System.out.println("B");
            }
            return;
        }
        if(nums[1] == nums[2]){
            if(allEqual(1)){
                System.out.println(nums[1]);
            } else {
                System.out.println("B");
            }
            return;
        }
        if((nums[2] - nums[1]) % (nums[1] - nums[0]) != 0){
            System.out.println("B");
            return;
        }
        a = (nums[2] - nums[1]) / (nums[1] - nums[0]);
        b = nums[1] - a * nums[0];

        if(isB()){
            System.out.println("B");
            return;
        }


        System.out.println((a * nums[N-1] + b));

    }

    private static boolean allEqual(int start) {
        for(int i=start+1; i<N; i++){
            if(nums[i] != nums[i-1]){
                return false;
            }
        }
        return true;
    }

    private static boolean isB() {
        for(int i=0; i<N-1; i++){
            if(nums[i+1] != a * nums[i] + b){
                b = nums[i+1] - a * nums[i];
                return true;
            }
        }
        return false;
    }


}
