#include <bits/stdc++.h>
using namespace std;

int N;
int seq[1000001];

int main(){

    vector<int> list;

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&seq[i]);
    }

    for(int i = 0 ; i < N ; i++){
        if(list.empty())
            list.push_back(seq[i]);
        else if(list[list.size()-1] < seq[i]){
            list.push_back(seq[i]);
        }
        else{
            auto pos = lower_bound(list.begin(),list.end(),seq[i]);
            *pos = seq[i];
        }
        /*for(auto x : list)
            printf("%d ",x);
        printf("\n");*/
    }
    printf("%d\n",list.size());
}