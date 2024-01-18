import java.util.*;
class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;

        int[][] graph = new int[friends.length][friends.length];
        int[] gift_table = new int[friends.length];

        Map<String, Integer> StringToInt = new HashMap<>();
        for(int i = 0 ; i < friends.length ; i++){
            StringToInt.put(friends[i], i);
        }

        for(String gift : gifts) {
            String[] s = gift.split(" ");
            String from = s[0];
            String to = s[1];

            graph[StringToInt.get(from)][StringToInt.get(to)] += 1;
            gift_table[StringToInt.get(from)] += 1;
            gift_table[StringToInt.get(to)] -= 1;
        }

        int[] next_gift = new int[friends.length];
        for(int i = 0 ; i < friends.length ; i++) {
            for(int j = i+1 ; j < friends.length ; j++ ){
                if(graph[i][j] > 0 || graph[j][i] > 0) {
                    if(graph[i][j] > graph[j][i]) {
                        next_gift[i] += 1;
                    } else if(graph[i][j] < graph[j][i]) {
                        next_gift[j] += 1;
                    } else if(graph[i][j] == graph[j][i]) {
                        if(gift_table[i] > gift_table[j]) {
                            next_gift[i] += 1;
                        } else if(gift_table[i] < gift_table[j]) {
                            next_gift[j] += 1;
                        }
                    }
                } else if(graph[i][j] == 0 && graph[j][i] == 0) {
                    if(gift_table[i] > gift_table[j]) {
                        next_gift[i] += 1;
                    } else if(gift_table[i] < gift_table[j]) {
                        next_gift[j] += 1;
                    }
                }
            }
        }
        return Arrays.stream(next_gift).max().getAsInt();
    }
}