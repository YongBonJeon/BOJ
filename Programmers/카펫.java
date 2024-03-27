class Solution {
    // N M -> brown = 2*N + 2*(M-2)
    // N M -> yellow = N-2*M-2
    public int[] solution(int brown, int yellow) {
        int[] answer = {};

        for(int n = 3 ; n < brown ; n++) {
            for(int m = 3 ; m <= n ; m++) {
                if(n*2 + (m-2)*2 == brown && (n-2)*(m-2) == yellow)
                    return new int[]{n,m};
            }
        }
        return answer;
    }
}