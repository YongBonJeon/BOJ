import java.util.Scanner;

public class Main {
    static int N;
    static int[][] map;
    static int min_ans = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N+1][N+1];

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        select();
        //System.out.println();
        //calculate(3, 5, 2, 1);
        System.out.println(min_ans);
    }

    private static void select() {
        int x, y, d1, d2;

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                for(int k = 1 ; k <= N ; k++) {
                    for(int l = 1 ; l <= N ; l++) {
                        if(i + k + l <= N && j - k >= 1 && j + l <= N) {
                            calculate(i, j, k, l);
                        }
                    }
                }
            }
        }
    }

    private static void calculate(int x, int y, int d1, int d2) {
        int[][] checked = new int[N+1][N+1];
        int area_1 = 0, area_2 = 0, area_3 = 0, area_4 = 0, area_5 = 0;
        int local_max = 0, local_min = Integer.MAX_VALUE;

        for(int d = 0 ; d <= d1 ; d++)
            checked[x+d][y-d] = 5;
        for(int d = 0 ; d <= d2 ; d++)
            checked[x+d][y+d] = 5;
        for(int d = 0 ; d <= d2 ; d++)
            checked[x+d1+d][y-d1+d] = 5;
        for(int d = 0 ; d <= d1 ; d++)
            checked[x+d2+d][y+d2-d] = 5;

        for(int i = x+1 ; i < x + d1 + d2 ; i++) {
            boolean five = false;
            for(int j = 1 ; j <= N ; j++) {
                if(!five && checked[i][j] == 5) {
                    five = true;
                } else if(five && checked[i][j] == 5) {
                    five = false;
                }
                if(five)
                    checked[i][j] = 5;
            }
        }

        for(int i = 1 ; i < x + d1 ; i++) {
            for(int j = 1 ; j <= y ; j++) {
                if(checked[i][j] != 5) {
                    area_1 += map[i][j];
                    checked[i][j] = 1;
                }
            }
        }
        local_min = Math.min(area_1, local_min);
        local_max = Math.max(area_1, local_max);

        for(int i = 1 ; i <= x + d2 ; i++) {
            for(int j = y+1 ; j <= N ; j++) {
                if(checked[i][j] != 5) {
                    area_2 += map[i][j];
                    checked[i][j] = 2;
                }
            }
        }
        local_min = Math.min(area_2, local_min);
        local_max = Math.max(area_2, local_max);

        for(int i = x + d1 ; i <= N ; i++) {
            for(int j = 1 ; j < y-d1+d2 ; j++) {
                if(checked[i][j] != 5) {
                    area_3 += map[i][j];
                    checked[i][j] = 3;
                }
            }
        }
        local_min = Math.min(area_3, local_min);
        local_max = Math.max(area_3, local_max);

        for(int i = x + d2 + 1 ; i <= N ; i++) {
            for(int j = y-d1+d2 ; j <= N ; j++) {
                if(checked[i][j] != 5) {
                    area_4 += map[i][j];
                    checked[i][j] = 4;
                }
            }
        }
        local_min = Math.min(area_4, local_min);
        local_max = Math.max(area_4, local_max);

        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++) {
                if(checked[i][j] == 5)
                    area_5 += map[i][j];
            }
        }
        local_min = Math.min(area_5, local_min);
        local_max = Math.max(area_5, local_max);

        /*System.out.println("area_1 = " + area_1);
        System.out.println("area_2 = " + area_2);
        System.out.println("area_3 = " + area_3);
        System.out.println("area_4 = " + area_4);
        System.out.println("area_5 = " + area_5);*/
        min_ans = Math.min(local_max - local_min, min_ans);

        //print(checked);
    }

    private static void print(int[][] arr) {
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++)
                System.out.print(arr[i][j] + " ");
            System.out.println();
        }
    }
}