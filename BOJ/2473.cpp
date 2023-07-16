#include <bits/stdc++.h>
using namespace std;

int N;
long long solution[5001];
int ans[3];
long long val = 3000000001L;

int main(){
    int N;
    
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&solution[i]);
    }
    sort(solution, solution+N);

    for(int i = 0 ; i < N-2 ; i++){
        int l = i+1;
        int r = N-1;

        while(l<r){
            if(abs(solution[i]+solution[l]+solution[r]) < abs(val)){
                //printf("%lld %lld %lld %lld\n",solution[i],solution[l],solution[r], val);
                ans[0] = i;
                ans[1] = l;
                ans[2] = r;
                val = abs(solution[i]+solution[l]+solution[r]);
            }
            if(solution[i]+solution[l]+solution[r] < 0)
                l++;
            else
                r--;
        }
    }
    for(int i = 0 ; i < 3 ; i++)
        printf("%lld ",solution[ans[i]]);
    printf("\n");
}