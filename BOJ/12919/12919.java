import java.util.*;

public class Main {
    static String S,T;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        S = sc.next();
        T = sc.next();

        if(dfs(T,S)) System.out.println(1);
        else System.out.println(0);
    }

    private static boolean dfs(String start, String target) {
        //System.out.println(start + " " + target);
        if(start.length() == target.length()) {
            if(start.equals(target))
                return true;
            return false;
        }

        String temp = start.substring(1);
        String reverse = "";
        for(int i = temp.length() -1 ; i >= 0 ; i --)
            reverse += temp.charAt(i);
        boolean A = false, B = false;
        if(start.charAt(start.length()-1) == 'A')
            A = dfs(start.substring(0,start.length()-1), target);
        if(start.charAt(0) == 'B')
            B = dfs(reverse, target);

        return A || B;
    }
}