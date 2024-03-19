#include <stdio.h>
#include <stdlib.h>

void sort1(char *ans, int start, int end){
    int temp;
    int i,j;
    for(i=0;i<end-start;i++){
        for(j=start;j<start+end-start-i;j++){
            if(ans[j]<ans[j+1]){
                temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}
void sort2(char *ans, int start, int end){
    int temp;
    int i,j;
    for(i=0;i<end-start;i++){
        for(j=start;j<start+end-start-i;j++){
            if(ans[j]>ans[j+1]){
                temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    char inequ;
    char *ans1,*ans2;
    int i;
    int num1=0,num2=0;
    int end1,end2;

    scanf("%d",&n);

    ans1 = (char*)malloc(sizeof(char)*(n+1)); // 최소 0123456789
    ans2 = (char*)malloc(sizeof(char)*(n+1)); // 최대 9876543210

    for(i = 0 ; i <= n ; i++){
        ans1[i]=i+'0';
    }
    for(i = 0 ; i <=n ; i++){
        ans2[i]=9-i+'0';
    }

    for(i = 0 ; i < n ; i++){
        scanf(" %c", &inequ);
        if(inequ == '>'){
            num1++;

            end2=i;
            sort2(ans2,end2-num2,end2);
            num2 = 0;
            
        }
        if(inequ == '<'){
            end1=i;
            sort1(ans1,end1-num1,end1);
            num1 = 0;

            num2++;
        }
    }
    if(num2>0){
        sort2(ans2,n-num2,n);
    }
     if(num1>0){
        sort1(ans1,n-num1,n);
    }

    printf("%s\n",ans2);
    printf("%s\n",ans1);
}