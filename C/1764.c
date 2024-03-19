#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *s1, const void *s2){
    return strcmp((char*)s1,(char*)s2);
}

int binary_search(char arr[][21], char target[],int start, int end){
    int mid = (start+end)/2;
    //printf("mid %d\n",mid);

    if(start > end){
        return -1;
    }

    if(strcmp(arr[mid], target) == 0){
        return mid;
    }

    if(strcmp(arr[mid], target) < 0){
        start = mid+1;
        return binary_search(arr, target, start, end);
    }
    else{
        end = mid-1;
        return binary_search(arr, target, start, end);
    }

}

int main(){
    int n,m;
    char arr_n[50000][21];
    char arr_m[50000][21];

    scanf("%d %d",&n, &m);

    for(int i = 0 ; i < n ; i++){
        scanf("%s",arr_n[i]);
    }

    for(int j = 0 ; j < m ; j++){
        scanf("%s",arr_m[j]);
    }
    qsort(arr_n, n, sizeof(arr_n[0]), compare);
    qsort(arr_m, m, sizeof(arr_m[0]), compare);

    char new_arr[50000][21];
    int new_idx = 0;

    for(int i = 0 ; i < n ; i++){
        int num = binary_search(arr_m, arr_n[i], 0, m);
        if(num >= 0){
            strcpy(new_arr[new_idx++], arr_n[i]);
            //printf("%s\n",arr_n[i]);
        }
    }
    printf("%d\n",new_idx);
    for(int i = 0 ; i < new_idx ; i++){
        printf("%s\n",new_arr[i]);
    }



}