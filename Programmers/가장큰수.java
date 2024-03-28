import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = "";

        List<String> oneNumbers = new ArrayList<>();

        boolean allZero = true;
        for(int n : numbers) {
            if(n != 0) allZero = false;
            oneNumbers.add(String.valueOf(n));
        }

        Collections.sort(oneNumbers, new Comparator<>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2+o1).compareTo(o1+o2);
            }
        });
        for(String i : oneNumbers)
            answer += i;

        if(allZero) return "0";
        return answer;
    }
}