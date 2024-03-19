#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[9];

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

void dfs(int temp[], int depth, int lower){
    if(depth == M){
        for(int i = 0 ; i < depth ; i++){
            printf("%d ",temp[i]);
        }
        printf("\n");
        return ;
    }

    for(int i = 0 ; i < N ; i++){
        if(arr[i] >= lower){
            temp[depth] = arr[i];
            dfs(temp, depth+1, arr[i]);
        }
    }
}

int main(){
    scanf("%d %d",&N, &M);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);

    int temp[9];

    dfs(temp, 0, arr[0]);
}