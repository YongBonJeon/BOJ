#include <bits/stdc++.h>
using namespace std;

int target, num_error, e;
bool error[11];

int check(int num){
    if(num == 0 && error[0] == false)
        return 1;
    else if(num == 0 && error[0] == true){
        return -1;  
    }
    
    int len = 0;
    while(num > 0){
        len++;
        if(error[num%10]){
            return -1;
            printf("%d\n",num);
        }
        num /= 10;
    }

    return len;
}

int main(){
    scanf("%d",&target);
    scanf("%d",&num_error);
    for(int i = 0 ; i < num_error ; i++){
        scanf("%d",&e);
        error[e] = true;
    }

    int ans = 9999999;

    for(int i = target ; i >= 0 ; i--){
        if(check(i) != -1){
            //printf("1 %d %d\n",i, check(i));
            ans = min(ans, target-i+check(i));
            //printf("%d %d\n\n",target-i, check(i));
            break;
        }
    }

    for(int i = target ; i < 999999 ; i++){
        if(check(i) != -1){
            //printf("2 %d\n",i);
            ans = min(ans, i-target+check(i));
            break;
        }
    }

    for(int i = 100 ; i >= 0 ; i--){
        if(i == target){
            //printf("3 %d\n",i);
            ans = min(ans, 100-i);
            //printf("%d %d\n\n",target-i, check(i));
            break;
        }
    }

    for(int i = 100 ; i < 999999 ; i++){
        if(i == target){
            //printf("4 %d\n",i);
            ans = min(ans, i-100);
            break;
        }
    }

    if(target == 100)
        ans = 0;

    printf("%d\n",ans);
}