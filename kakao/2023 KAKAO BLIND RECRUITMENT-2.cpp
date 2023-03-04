#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int round, temp;
    for(int house = n- 1 ; house >= 0 ; house--){
        if(deliveries[house] == 0 && pickups[house] == 0) continue;
        
        round = (max(deliveries[house], pickups[house])-1)/cap +1;
        
        temp = round*cap;
        for(int i = house ; i >= 0 && temp != 0 ; i--){
            if(deliveries[i] == 0) continue;
            
            if(deliveries[i] <= temp){
                temp -= deliveries[i];
                deliveries[i] = 0;
            }
            else{
                deliveries[i] -= temp;
                temp = 0;
            }
        }
        
        temp = round*cap;
        for(int i = house ; i >= 0 && temp != 0 ; i--){
            if(pickups[i] == 0) continue;
            
            if(pickups[i] <= temp){
                temp -= pickups[i];
                pickups[i] = 0;
            }
            else{
                pickups[i] -= temp;
                temp = 0;
            }
        }
        
        /*printf("%d %d\n",house,round);
        
        for(auto i : deliveries)
            printf("%d ",i);
        printf("\n");
        for(auto i : pickups)
            printf("%d ",i);
        printf("\n");*/
        
        answer += 2*round*(house+1);
    }
    
    return answer;
}