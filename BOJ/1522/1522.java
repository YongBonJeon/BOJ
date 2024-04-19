import java.util.*;

public class Main {
    static String str;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        str = sc.next();

        int num_a = 0;
        for(int i = 0 ; i < str.length() ; i++) {
            if(str.charAt(i) == 'a') num_a++;
        }

        str = str + str;
        int max_a = 0;

        for(int i = 0 ; i <= str.length() - num_a ; i++) {
            int num = 0;
            for(int j = i ; j < i + num_a ; j++) {
                if(str.charAt(j) == 'a') num++;
            }
            max_a = Math.max(max_a, num);
        }

        System.out.println(num_a - max_a);

    }

}