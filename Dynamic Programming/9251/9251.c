#include <stdio.h>
#include <string.h>

#define MAX 1001
#define select_max(a,b) (((a) > (b)) ? (a) : (b))

int main(){
    char arr1[MAX];
    char arr2[MAX];
    int LCS[MAX][MAX] = {0, };


    scanf("%s",arr1);
    scanf("%s",arr2);

   for(int i = 0 ; i <= strlen(arr1) ; i++){
    for(int j = 0 ; j <= strlen(arr2) ; j++){
        if(i == 0 || j == 0){
            LCS[i][j] = 0;
            }
        else if(arr1[i-1] == arr2[j-1]){
            LCS[i][j] = LCS[i-1][j-1] + 1;
            }
        else{
            LCS[i][j] = select_max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    /*for(int i = 0 ; i <= strlen(arr1) ; i++){
        for(int j = 0 ; j <= strlen(arr2) ; j++){
            printf("%d ",LCS[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",LCS[strlen(arr1)][strlen(arr2)]);
}