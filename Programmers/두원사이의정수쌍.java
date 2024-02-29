class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;

        // X 좌표는 r1 ~ r2
        // 그에 해당하는 Y좌표를 구하자

        for(long x = 1 ; x <= r2 ; x++) {
            double s,e;

            e = Math.sqrt(Math.pow(r2,2) - Math.pow(x,2));
            s = Math.sqrt(Math.pow(r1,2) - Math.pow(x,2));
            answer += ( (long)e - (long)Math.ceil(s) + 1);

        }

        return answer*4;
    }

}