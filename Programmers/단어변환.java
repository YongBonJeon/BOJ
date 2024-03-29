import java.util.*;
class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;

        Map<String, Integer> map = new HashMap<>();
        Queue<String> q = new ArrayDeque<>();
        map.put(begin, 0);
        q.add(begin);

        while(!q.isEmpty()) {
            String cur = q.poll();

            if(cur.equals(target))
                return map.get(cur);

            for(String word : words) {
                int diff = 0;
                for(int i = 0 ; i < word.length() ; i++) {
                    if(word.charAt(i) != cur.charAt(i))
                        diff++;
                }

                if(diff == 1 && map.getOrDefault(word, null) == null) {
                    map.put(word, map.get(cur) + 1);
                    q.add(word);
                }
            }
        }


        return answer;
    }
}