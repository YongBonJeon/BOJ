import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());

        Deque<Pair> stack = new ArrayDeque<>();

        StringTokenizer st = new StringTokenizer(bf.readLine());
        for(int i = 0 ; i < N ; i++) {
            int cur = Integer.parseInt(st.nextToken());

            while(!stack.isEmpty() && stack.peek().height < cur) {
                stack.poll();
            }

            if(stack.isEmpty())
                System.out.print(0 + " ");
            else
                System.out.print((stack.peek().idx + 1) + " ");

            stack.push(new Pair(i, cur));
        }
    }

    static class Pair {
        int idx, height;

        Pair(int idx, int height) {
            this.idx = idx;
            this.height = height;
        }
    }
}