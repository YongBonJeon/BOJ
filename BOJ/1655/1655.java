import java.io.*;
import java.util.*;

import static java.util.Collections.reverseOrder;

public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        N = Integer.parseInt(input);

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for(int i = 0; i < N; i++) {
            input = br.readLine();
            int num = Integer.parseInt(input);
            if(minHeap.size() == maxHeap.size()) {
                maxHeap.add(num);
            } else {
                minHeap.add(num);
            }

            if(!minHeap.isEmpty() && !maxHeap.isEmpty()) {
                if(minHeap.peek() < maxHeap.peek()) {
                    int tmp = minHeap.poll();
                    minHeap.add(maxHeap.poll());
                    maxHeap.add(tmp);
                }
            }
            bw.write(maxHeap.peek() + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }




}
