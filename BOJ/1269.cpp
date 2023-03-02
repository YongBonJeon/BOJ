#include <bits/stdc++.h>
using namespace std;

/*int main(){
    int a,b;
    int A[200001];
    int B[200001];

    scanf("%d %d",&a, &b);
    for(int i = 0 ; i < a ; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0 ; i < b ; i++){
        scanf("%d",&B[i]);
    }
    sort(B,B+b);

    int common = 0;
    for(int i = 0 ; i < a ; i++){
        if(binary_search(B,B+b,A[i]))
            common++;
    }
    printf("%d\n",a+b-2*common);
}*/

int main(){
    int a,b,t;
    map<int,int> m;

    scanf("%d %d",&a, &b);
    for(int i = 0 ; i < a ; i++){
        scanf("%d", &t);
        m[t]++;
    }
    for(int i = 0 ; i < b ; i++){
        scanf("%d",&t);
        m[t]++;
    }
    
    int ans = 0;
    for(auto it : m){
        if(it.second == 1)
            ans++;
    }
    printf("%d\n",ans);
}