import java.util.*;

public class Main {
    static int N, K, num_robot = 0;
    static int[] robot;
    static int[] durability;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        durability = new int[N*2];
        robot = new int[N];

        for(int i = 0 ; i < N*2 ; i++) {
            durability[i] = sc.nextInt();
        }

        int sec = 0;
        while(num_zero() < K) {
            //System.out.println("sec = " + (sec+1));
            // 벨트 회전
            rotate_belt();

            // 로봇 이동
            move_robot();

            // 로봇 올리기
            add_robot();
            sec++;
        }
        System.out.println(sec);
    }

    private static int num_zero() {
        int num = 0;
        for(int i = 0 ; i < N*2 ; i++)
            if(durability[i] == 0)
                num++;
        return num;
    }

    private static void add_robot() {
        if(durability[0] > 0 && robot[0] == 0) {
            robot[0] = 1;
            durability[0]--;
        }

        /*System.out.println("after add robot");
        for(int i = 0 ; i < N*2 ; i++)
            System.out.print(durability[i] + " ");
        System.out.println();
        for(int i = 0 ; i < N ; i++)
            System.out.print(robot[i] + " ");
        System.out.println();*/
    }

    private static void move_robot() {
        for(int i = N-1 ; i >= 1 ; i--) {
            if (durability[i] > 0 && robot[i-1] == 1 && robot[i] == 0) {
                robot[i] = robot[i - 1];
                robot[i-1] = 0;
                durability[i]--;
            }
        }
        robot[N-1] = 0;

        /*System.out.println("after move robot");
        for(int i = 0 ; i < N*2 ; i++)
            System.out.print(durability[i] + " ");
        System.out.println();
        for(int i = 0 ; i < N ; i++)
            System.out.print(robot[i] + " ");
        System.out.println();*/

    }

    private static void rotate_belt() {
        int temp = durability[N*2-1];
        for(int i = N*2-1 ; i >= 1 ; i--) {
            durability[i] = durability[i-1];
        }
        durability[0] = temp;

        for(int i = N-1 ; i >= 1 ; i--) {
            robot[i] = robot[i-1];
        }
        robot[0] = 0;
        robot[N-1] = 0;

        /*System.out.println("after rotate");
        for(int i = 0 ; i < N*2 ; i++)
            System.out.print(durability[i] + " ");
        System.out.println();
        for(int i = 0 ; i < N ; i++)
            System.out.print(robot[i] + " ");
        System.out.println();*/
    }
}