import java.util.*;
class Solution {
    int max = 0;
    public int solution(int coin, int[] cards) {
        int answer = 0;

        int[] myCards = new int[cards.length+2];
        int[] trash = new int[cards.length+2];
        for(int i = 0 ; i < cards.length/3 ; i++)
            myCards[cards[i]] = 1;

        max = 1;
        System.out.println(cards.length + " " + coin + " " + cards.length/3);
        backtracking(cards.length, cards, myCards, coin, cards.length/3, trash);

        System.out.println(max);
        return max;
    }

    public void backtracking(int N, int[] cards, int[] myCards, int coin, int cur, int[] trash) {
        if(max == (N/3)+1)
            return ;

        int[] newCards = new int[myCards.length];
        int[] newTrash = new int[trash.length];

        // 제출하고 다음 라운드로 첫라운드 제외
        if(cur != N/3) {
            boolean submit = false;
            for(int i = 1 ; i < myCards.length ; i++) {
                if(myCards[i] == 1 && myCards[N+1-i] == 1) {
                    myCards[i] = 0;
                    myCards[N+1-i] = 0;
                    submit = true;
                    break;
                }
            }
            if(!submit)
                return ;
        }

        max = Math.max(max, (cur-N/3)/2 + 1);

        if(N <= cur)
            return ;

        // 2장 전부 갖지 않음
        newCards = Arrays.copyOf(myCards, myCards.length);
        newTrash = Arrays.copyOf(trash, trash.length);
        System.out.println(cards[cur] + " " + cards[cur+1]);
        newTrash[cards[cur]] = 1;
        newTrash[cards[cur+1]] = 1;
        backtracking(N, cards, newCards, coin, cur+2, newTrash);


        // 2장 모두 가짐
        if(coin >= 2) {
            // 2장 중에 반대 카드를 버린 적이 없을 경우 2장 모두 가진다.
            if(trash[N-cards[cur]+1] != 1 && trash[N-cards[cur+1]+1] != 1) {
                newCards = Arrays.copyOf(myCards, myCards.length);
                newCards[cards[cur]] = 1;
                newCards[cards[cur+1]] = 1;
                newTrash = Arrays.copyOf(trash, trash.length);
                backtracking(N, cards, newCards, coin-2, cur+2, newTrash);
            }
        }

        if(coin >= 1) {
            // 첫번째 1장만 가짐
            if(trash[N-cards[cur]+1] != 1) {
                newCards = Arrays.copyOf(myCards, myCards.length);
                newCards[cards[cur]] = 1;
                newTrash = Arrays.copyOf(trash, trash.length);
                newTrash[cards[cur+1]] = 1;
                backtracking(N, cards, newCards, coin-1, cur+2, newTrash);
            }


            // 두번째 1장만 가짐
            if(trash[N-cards[cur+1]+1] != 1) {
                newCards = Arrays.copyOf(myCards, myCards.length);
                newCards[cards[cur+1]] = 1;
                newTrash = Arrays.copyOf(trash, trash.length);
                newTrash[cards[cur]] = 1;
                backtracking(N, cards, newCards, coin-1, cur+2, newTrash);
            }
        }
    }
}