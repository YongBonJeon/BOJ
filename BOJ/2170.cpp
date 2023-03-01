#include <bits/stdc++.h>
using namespace std;

pair<int,int> line[1000001];

int main(){
    int N,s,d;

    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d %d",&line[i].first,&line[i].second);
    }
    sort(line,line+N);

    int sum = 0, last = INT_MIN;
    for(int i = 0 ; i < N ; i++){
        //printf("%d %d\n",line[i].first,line[i].second);
        if(last > line[i].second)
            continue;
        if(line[i].first >= last){
            sum += line[i].second - line[i].first;
        }
        else{
            sum += line[i].second - last;
        }
        last = max(last,line[i].second);
        //printf("last %d\n",last);
    }
    printf("%d\n",sum);
}