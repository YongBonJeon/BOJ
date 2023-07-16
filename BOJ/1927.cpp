#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> heap;

    int N;

    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        int q;
        scanf("%d",&q);

        if(q != 0){
            heap.push(q);
        } else{
            if(heap.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n",heap.top()); 
                heap.pop();
            }
        }
    }
}