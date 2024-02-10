import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N, M, maxCrane = 0, maxBox = 0;
    static List<Integer> crane = new ArrayList<>();
    static List<Integer> box =  new ArrayList<>();



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int temp;
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            temp = sc.nextInt();
            crane.add(temp);
        }
        M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            temp = sc.nextInt();
            box.add(temp);
        }
        Collections.sort(crane, reverseOrder());
        Collections.sort(box, reverseOrder());
        if(crane.get(0) < box.get(0)){
            System.out.println(-1);
            return;
        }



        int ans = 0;
        while(!box.isEmpty()){
            int craneIdx = 0, boxIdx = 0;

            while(craneIdx < N){
                if(boxIdx == box.size()){
                    break;
                }
                if(crane.get(craneIdx) >= box.get(boxIdx)){
                    box.remove(boxIdx);
                    craneIdx++;
                }else{
                    boxIdx++;
                }
            }
            ans++;
        }
        System.out.println(ans);




    }


}