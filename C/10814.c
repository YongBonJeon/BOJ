#include <stdio.h>
#include <string.h>

typedef struct{
    int age;
    char name[100];
}bo;

int main(){
    int n=0;
    int i=0,j=0;
    char tempn[100];
    int tempa;
    bo boj[100000];

    scanf("%d",&n);

    for(i = 0 ; i < n ; i++){
        scanf("%d %s",&boj[i].age,boj[i].name);
    }
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n-1-i ; j++){
            if(boj[j].age > boj[j+1].age){
                tempa = boj[j].age;
                boj[j].age = boj[j+1].age;
                boj[j+1].age = tempa;
                strcpy(tempn,boj[j].name);
                strcpy(boj[j].name,boj[j+1].name);
                strcpy(boj[j+1].name,tempn);
            }

        }
    }
    for(i = 0 ; i < n ; i++){
        printf("%d %s",boj[i].age, boj[i].name);
    }
    return 0;
}