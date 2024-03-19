#include <stdio.h>
#include <stdlib.h>

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

int binary_search(int arr[], int start, int end, int target){
    int mid = (start+end)/2;

    if(start > end){
        return 0;
    }

    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return binary_search(arr, start, mid, target);
    }
    else{
        return binary_search(arr, mid+1, end, target);
    }
}


int main(){
    int n;
    int *arr;
    int *sort_arr;
    int *remove_arr;
    scanf("%d",&n);

    arr = (int*)malloc(sizeof(int)*n);
    sort_arr = (int*)malloc(sizeof(int)*n);
    remove_arr = (int*)malloc(sizeof(int)*n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
        sort_arr[i] = arr[i];
    }
    qsort(sort_arr, n, sizeof(int), compare);
    
    remove_arr[0] = sort_arr[0];
    int x=1;
    for (int i = 1; i < n; i++)
		if (sort_arr[i] != remove_arr[x - 1]) remove_arr[x++] = sort_arr[i];
    
    for(int i = 0 ; i < n ; i++){
        printf("%d ",binary_search(remove_arr, 0, x, arr[i]));
    }
    printf("\n");

    free(remove_arr);
    free(sort_arr);
    free(arr);



    /*for(int i = 0 ; i < n ; i++){
        printf("%d ",sort_arr[i]);
    }
    printf("\n");
    for(int i = 0 ; i < x ; i++){
        printf("%d ",remove_arr[i]);
    }
    printf("\n");*/

    /*int count = 0;
    int j = 0;
    for(int i = 0 ; i < n ; i++){
        while(1){
        if(arr[i] == remove_arr[j]){
            printf("%d ",j);
            break;
        }
        else if(arr[i] > remove_arr[j]){
            j++;
        }
        else if(arr[i] < remove_arr[j]){
            j--;
        }
        }
    }
    printf("\n");*/

}