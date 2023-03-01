#include <bits/stdc++.h>
using namespace std;

int N,M;
int jewel[300001];

bool sperad(int val){
    int student = 0;
    for(int i = 0 ; i < M ; i++){
        student += jewel[i] / val;
        if(jewel[i]%val)
            student++;
    }
    return N >= student;
}

int main()
{
    int left = 1, right = 1;
    scanf("%d %d",&N, &M);
    for(int i = 0 ; i < M ; i++){
        scanf("%d",&jewel[i]);

        right = max(right,jewel[i]);
    }

    // 질투심이 이 사이에 존재하겠지
    int mid,ret = INT_MAX;
    while(left <= right){
        mid = (left+right)/2;

        if(sperad(mid)){
            ret = min(ret,mid);
            right = mid-1;
        }
        else
            left = mid+1;
    }
    printf("%d\n",ret);
}