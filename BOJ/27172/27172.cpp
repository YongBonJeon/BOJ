#include <bits/stdc++.h>
using namespace std;

// 다른 플레이어의 카드로 나눴을 때 나머지가 0 승리
// 나누어 떨어지면 패배
// 둘다 아니면 무승부 

// 일단 소수면 무조건 비기거나 이긴다
// 소수는 배수 상대로만 이길 수 있다.
// 소수가 아닌 경우 

int N,x,maxv = 0;
vector<int> card; // index - > value
int reverse_card[1000001]; // value -> index
int score[1000001];

int main(){
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&x);
        card.push_back(x);
        reverse_card[x] = 1;
        maxv = max(maxv, x);
    }

    for(int i = 0 ; i < N ; i++){
        int cur = card[i];
        for(int j = cur*2 ; j <= maxv ; j += cur){
            if(reverse_card[j] == 1){
                score[j] -= 1;
                score[cur] += 1;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        printf("%d ",score[card[i]]);
    }
    printf("\n");
}