#include <stdio.h>
#include <string.h>

#define MAX 1000001
int find[MAX];

void preprocess(char *pattern, int pattern_size){
    int i = 0;
    int j = -1;

    find[0] = -1;

    while(i < pattern_size){
        while(j > -1 && pattern[i] != pattern[j]){
            j = find[j];
        }
        i++;
        j++;
        find[i] = j;
    }
}

int KMP(char *text, int text_size, int start, char *pattern, int pattern_size){
    int i = start;
    int j = 0;
    int position = -1;

    preprocess(pattern, pattern_size);

    while(i < text_size){
        while(j >= 0 && text[i] != pattern[j]){
            j = find[j];
        }
        i++;
        j++;

        if(j == pattern_size){
            position = i - j;
            break;
        }
    }
    return position;
}

int main(){
    char text[MAX];
    char pattern[MAX] = "IOI";

    int n;
    scanf("%d",&n);
    for(int i = 1 ; i < n ; i++){
        strcat(pattern, "OI");
    }
    int pattern_size = strlen(pattern);
    int m;
    scanf("%d",&m);
    scanf("%s",text);

    int position;
    int start = 0;
    int cnt = 0;
    while(1){
        position = KMP(text, strlen(text), start, pattern, pattern_size);
        if(position >= 0){
            cnt++;
            start = position + 1;
        }
        else{
            break;
        }
    }
    printf("%d\n",cnt);

    /*int position = KMP(text, strlen(text), 0, pattern, pattern_size);

    if(position >= 0){
        printf("%d\n",position + 1);
    }*/

}