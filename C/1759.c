#include <stdio.h>

/* 모음 : a, e, i, o, u */

#define MAX 15

int L, C;
char alphabet[MAX];
int used[MAX];

void sort(){
    for(int i = 0 ; i < C-1 ; i++){
        for(int j = 0 ; j < C-i-1 ; j++){
            if(alphabet[j] > alphabet[j+1]){
                char temp;
                temp = alphabet[j];
                alphabet[j] = alphabet[j+1];
                alphabet[j+1] = temp;
            }
        }
    }
}

int isVowel(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x =='u'){
        return 1;
    }
    return 0;
}

void makePW(char password[], int depth, int vowel, int index){

    if(depth == L){
        if(vowel !=0 && (L-vowel) >=2){
            printf("%s\n",password);
        }
        return ;
    }

    for(int i = index ; i < C ; i++){
        if(isVowel(alphabet[i])){
            //printf("%c\n",alphabet[i]);
            password[depth] = alphabet[i];
            //printf("%d %s\n",depth,password);
            makePW(password, depth+1, vowel+1, i+1);
        }
        else{
            //printf("%d %s\n",depth,password);
            password[depth] = alphabet[i];
            makePW(password, depth+1, vowel, i+1);
        }
    }

}

int main(){
    scanf("%d %d",&L,&C);

    for(int i = 0 ; i < C ; i++){
        scanf(" %c", &alphabet[i]);
    }

    sort();
    char password[MAX] ={0,};
    
    //printf("%s\n",alphabet);

    makePW(password, 0, 0, 0);

}