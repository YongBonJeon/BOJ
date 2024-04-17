import java.util.*;
public class Main {
    static int H, W;
    static boolean[][] map;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        H = sc.nextInt();
        W = sc.nextInt();

        map = new boolean[H+1][W+1];

        int temp;
        for(int i = 0 ; i < W ; i++) {
            temp = sc.nextInt();
            for(int h = 1 ; h <= temp ; h++)
                map[h][i] = true;
        }

        /*for(int h = 0 ; h <= H ; h++) {
            for(int w = 0 ; w < W ; w++) {
                System.out.print(map[h][w] + " ");
            }
            System.out.println();
        }*/

        int answer = 0;
        for(int h = 1 ; h <= H ; h++) {
            int w = 1;
            //System.out.println("h " + h);
            while(w < W) {
                //System.out.println("w " + w);
                int st;
                if(map[h][w-1] && !map[h][w]) st = w;
                else {
                    w++;
                    continue;
                }

                while(w < W && !map[h][w]) w++;
                if(w < W) {
                    //System.out.println("++ h " + h + " " + st + " ~ " + w);
                    answer += w - st;
                }
                w++;
            }
        }


        System.out.println(answer);



    }
}