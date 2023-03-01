#include <bits/stdc++.h>
using namespace std;

int N,S;
int seq[100001];
int pSum[100001];

// 5 1 3 5  10  7 4  9  2  8
// 5 6 9 14 24 31 35 44 46 54

int main()
{
    scanf("%d %d",&N,&S);
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&seq[i]);
        sum += seq[i];
        pSum[i] = sum;
    }

    int l = -1, r = 0;

    int temp_sum, min_length = INT_MAX;
    while(l < N && r < N){
        if(l == -1)
            temp_sum = pSum[r];
        else
            temp_sum = pSum[r]-pSum[l];
        
        if(temp_sum < S){
            r++;
        }
        else if(temp_sum >= S){
            min_length = min(min_length, r-l);
            //printf("t s %d len %d %d\n",temp_sum, r,l);
            l++;
        }
    }
    if(min_length == INT_MAX)
        printf("0\n");
    else
        printf("%d\n",min_length);

    
}