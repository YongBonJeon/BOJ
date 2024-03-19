#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[9];
int visited[10000] = {0,};

int compare(const void (*a), const void (*b)){
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

void dfs(int temp[], int depth){
    if(depth == M){
        for(int i = 0 ; i < depth ; i++){
            printf("%d ",temp[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 0 ; i < N ; i++){
        int cur_vertex = arr[i];
        //printf("test %d\n",cur_vertex);
        if(!visited[cur_vertex]){
            visited[cur_vertex] = 1;
            //printf("%d ",cur_vertex);
            temp[depth] = cur_vertex;
            dfs(temp, depth + 1);
            visited[cur_vertex] = 0;
        }
    }
}

int main(){
    scanf("%d %d",&N, &M);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    //printf("%d %d %d %d\n",arr[0], arr[1], arr[2], arr[3]);
    int temp[9];
    dfs(temp, 0);
}