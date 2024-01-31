import java.util.*;

class Solution {
    public int solution(int storey) {
        int answer = 0;

        String s = Integer.toString(storey);
        int[] storeyArr = new int[s.length()+1];
        for(int i = 1 ; i <= s.length() ; i++) {
            storeyArr[i] = s.charAt(i-1) - '0';
        }
        storeyArr[0] = 0;

        for(int i = s.length() ; i >= 0 ; i--) {
            if(storeyArr[i] == 10) {
                storeyArr[i] = 0;
                storeyArr[i-1] += 1;
            }
            if(storeyArr[i] > 5) {
                answer += 10 - storeyArr[i];
                if(i != 0)
                    storeyArr[i-1]++;
            } else if(storeyArr[i] < 5) {
                answer += storeyArr[i];
            } else if(storeyArr[i] == 5) {
                if(i != 0) {
                    if(storeyArr[i-1] >= 5) {
                        storeyArr[i-1]++;
                    }
                }
                answer += 5;
            }
        }
        return answer;
    }
}