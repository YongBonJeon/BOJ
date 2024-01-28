import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        List<Integer> plusArr = new ArrayList<>();
        List<Integer> minusArr = new ArrayList<>();

        for(int i = 0; i < N; i++){
            int num = sc.nextInt();
            if(num > 0)
                plusArr.add(num);
            else
                minusArr.add(num);
        }

        Collections.sort(plusArr, Collections.reverseOrder());
        Collections.sort(minusArr);

        int ans = 0;

        if(N == 1){
            if(plusArr.size() == 1)
                System.out.println(plusArr.get(0));
            else
                System.out.println(minusArr.get(0));
            return;
        }

        for(int i = 0; i < plusArr.size(); i++){
            if(i == plusArr.size()-1){
                ans += plusArr.get(i);
                break;
            }
            if(plusArr.get(i) > 1 && plusArr.get(i+1) > 1){
                ans += plusArr.get(i) * plusArr.get(i+1);
            }
            else if(plusArr.get(i) == 1 || plusArr.get(i+1) == 1){
                ans += plusArr.get(i);
                ans += plusArr.get(i+1);
            }
            i++;
        }
        for(int i = 0; i < minusArr.size(); i++){
            if(i == minusArr.size()-1){
                ans += minusArr.get(i);
                break;
            }
            if(minusArr.get(i) < 0 && minusArr.get(i+1) < 0){
                ans += minusArr.get(i) * minusArr.get(i+1);
            }
            else if(minusArr.get(i) == 0 || minusArr.get(i+1) == 0){
            }
            i++;
        }


        System.out.println(ans);
    }



}