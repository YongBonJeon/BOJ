#include <stdio.h>

#define MAX 10000

int arr[10000];
int n,m;
int flag = 0;
int main(){

    scanf("%d %d",&n, &m);

    for(int i = 0 ; i < n ; i++){
        scanf(" %d",&arr[i]);
    }

    for(int i = 0 ; i < n ; i++){
        int temp_sum = 0;
        for(int j = i ; j < n ; j++){
            temp_sum += arr[j];
            if(temp_sum == m){
                flag++;
            }
            else if(temp_sum > m){
                break;
            }
        }
    }
    printf("%d\n",flag);
}