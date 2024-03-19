#include <stdio.h>
#include <string.h>

// 98765432 10
// 

char word[10][10];
int used[32] = {0, }; // 0~9 사용행렬


void make(int num){
    for(int i = 0 ; i < num ; i++){
        for(int j = strlen(word[i])-1, x = 1 ; j >= 0 ; j--,x*=10){
            char temp = word[i][j];
            used[temp - 'A'] += x;
        }
    }
}

int find(){
    int max = 0;
    int temp = 0;
    for(int i = 0 ; i < 32 ; i++){
        if(max < used[i]){
            max = used[i];
            temp = i;
        }
    }
    used[temp] = 0;
    return max;
}

int sum(int num){
    int temp = 0;

    for(int i = 9 ; i >= 0 ; i--){
        int r = find();
        //printf("%d ",r);
        temp += r*i;
        //printf("temp%d\n",temp);
         //for(int i = 0 ; i < 32 ; i++){
        //printf("%d\n ",used[i]);
    //}
    }
    return temp;
}



int main(){
    int num;

    scanf("%d",&num);

    for(int i = 0 ; i < num ; i++){
        scanf("%s",word[i]);
    }

    make(num);

   

    printf("%d\n",sum(num));



}