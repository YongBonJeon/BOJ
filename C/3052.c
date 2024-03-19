#include <stdio.h>

int main(){
    int arr[10] = {0,};
    int total = 10;

    for(int i = 0 ; i < 10 ; i++){
        scanf("%d",&arr[i]);
        arr[i] = arr[i]%42;
    }

    for(int i = 0 ; i < 9 ; i++){
        int flag = 0;
        for(int j = i+1 ; j < 10 ; j++){
            if(arr[i] == arr[j]){
                flag++;
            }
        }
        if(flag){
            total--;
        }
    }
    printf("%d\n",total);
}