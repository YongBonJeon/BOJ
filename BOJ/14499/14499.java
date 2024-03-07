import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class Dice {
        int[] num;
        int[] idx;

        public Dice(int[] num, int[] idx) {
            this.num = num;
            this.idx = idx;
        }
    }
    public static void main(String[] args) {
        int N, M, x, y, K;
        int[][] map;
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        K = sc.nextInt();

        map = new int[N][M];
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        Dice dice = new Dice(new int[]{0, 0, 0, 0, 0, 0}, new int[]{0, 1, 2, 3, 4, 5});
        int od;
        int nx = x, ny = y;

        for(int i = 0 ; i < K ; i++) {
            od = sc.nextInt();
            int[] nextIdx = new int[6];

            // 동쪽 굴리기
            if(od == 1) {
                ny++;
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    ny--;
                    continue;
                }
                nextIdx[0] = dice.idx[3];
                nextIdx[1] = dice.idx[1];
                nextIdx[2] = dice.idx[0];
                nextIdx[3] = dice.idx[5];
                nextIdx[4] = dice.idx[4];
                nextIdx[5] = dice.idx[2];
            }
            // 서쪽 굴리기
            else if(od == 2) {
                ny--;
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    ny++;
                    continue;
                }
                nextIdx[0] = dice.idx[2];
                nextIdx[1] = dice.idx[1];
                nextIdx[2] = dice.idx[5];
                nextIdx[3] = dice.idx[0];
                nextIdx[4] = dice.idx[4];
                nextIdx[5] = dice.idx[3];
            }
            // 북쪽 굴리기
            else if(od == 3) {
                nx--;
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    nx++;
                    continue;
                }
                nextIdx[0] = dice.idx[4];
                nextIdx[1] = dice.idx[0];
                nextIdx[2] = dice.idx[2];
                nextIdx[3] = dice.idx[3];
                nextIdx[4] = dice.idx[5];
                nextIdx[5] = dice.idx[1];
            }
            // 남쪽 굴리기
            else if(od == 4) {
                nx++;
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    nx--;
                    continue;
                }
                nextIdx[0] = dice.idx[1];
                nextIdx[1] = dice.idx[5];
                nextIdx[2] = dice.idx[2];
                nextIdx[3] = dice.idx[3];
                nextIdx[4] = dice.idx[0];
                nextIdx[5] = dice.idx[4];
            }
            dice.idx = Arrays.copyOf(nextIdx, 6);

            if(map[nx][ny] == 0) {
                map[nx][ny] = dice.num[dice.idx[5]];
            } else {
                dice.num[dice.idx[5]] = map[nx][ny];
                map[nx][ny] = 0;
            }
            System.out.println(dice.num[dice.idx[0]]);
        }

    }
}
