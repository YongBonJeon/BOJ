import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[][] status = new int[4][8];
    public static void main(String[] args) {
        int K;
        Scanner sc = new Scanner(System.in);

        String temp;
        for(int i = 0 ; i < 4 ; i++) {
            temp = sc.next();
            for(int j = 0 ; j < 8 ; j++) {
                status[i][j] = temp.charAt(j) - '0';
            }
        }
        K = sc.nextInt();

        int num, dir, ans = 0;
        for(int i = 0 ; i < K ; i++) {
            num = sc.nextInt();
            dir = sc.nextInt();
            gogo(num-1, dir);

            /*for(int p = 0 ; p < 4 ; p++) {
                for(int q = 0 ; q < 8 ; q++) {
                    System.out.print(status[p][q]);
                }
                System.out.println();
            }*/
        }
        if(status[0][0] == 1) ans += 1;
        if(status[1][0] == 1) ans += 2;
        if(status[2][0] == 1) ans += 4;
        if(status[3][0] == 1) ans += 8;
        System.out.println(ans);

    }

    private static void gogo(int num, int dir) {
        rightRotate(num, -dir);
        leftRotate(num, -dir);
        rotate(num, dir);
    }

    private static void leftRotate(int num, int dir) {
        if(num - 1 >= 0 && status[num][6] != status[num-1][2]) {
            leftRotate(num-1, -dir);
            rotate(num-1, dir);
        }
    }

    private static void rightRotate(int num, int dir) {
        if(num+1 < 4 && status[num][2] != status[num+1][6]) {
            rightRotate(num+1, -dir);
            rotate(num+1, dir);
        }
    }

    private static void rotate(int num, int dir) {
        if (dir == 1) {
            int[] old = Arrays.copyOf(status[num], 8);
            for (int i = 0; i < 8; i++) {
                status[num][((i + 1) % 8)] = old[i];
            }
        }
        // 반시계 방향
        else if (dir == -1) {
            int[] old = Arrays.copyOf(status[num], 8);
            for (int i = 0; i < 8; i++) {
                status[num][((i + 7) % 8)] = old[i];
            }
        }
    }
}