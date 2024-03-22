import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int N = gems.length;

        Map<String, Integer> index = new HashMap<>();

        int num = 0;
        for(int i = 0 ; i < N ; i++) {
            if(!index.containsKey(gems[i])) {
                index.put(gems[i], num++);
            }
        }

        int[] count = new int[num];

        int min_dist = Integer.MAX_VALUE;
        int min_l = 0, min_r = 0;

        int check = 0, l = 0 , r = 0;
        while(true) {
            //System.out.println(l + " " + r + " check " + check);
            if(check == num) {
                if(min_dist > (r-1)-l) {
                    min_dist = (r-1)-l;
                    min_l = l;
                    min_r = r-1;
                } else if(min_dist == (r-1)-l) {
                    if(min_l > l) {
                        min_l = l;
                        min_r = r-1;
                    }
                }
                //System.out.println("min " + min_l + " " + min_r);

                if(count[index.get(gems[l])] > 0) {
                    count[index.get(gems[l])] -= 1;
                    if(count[index.get(gems[l])] == 0)
                        check -= 1;
                }
                l++;
            } else if(r == N) break;
            else if(check < num) {
                if(count[index.get(gems[r])] == 0)
                    check += 1;
                count[index.get(gems[r])] += 1;
                r++;
            }
        }
        return new int[]{min_l+1, min_r+1};
    }
}