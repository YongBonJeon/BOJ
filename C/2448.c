#include <stdio.h>

char space[3072][6143] = {0, };

void setStar(int height, int x, int y){
    if(height == 3){
        space[y][x] = '*';
        space[y+1][x-1] = '*';
        space[y+1][x+1] = '*';
        space[y+2][x-2] = '*';
        space[y+2][x-1] = '*';
        space[y+2][x] = '*';
        space[y+2][x+1] = '*';
        space[y+2][x+2] = '*';
    }
    else{
        setStar(height / 2, x, y);
        setStar(height / 2, x - (height / 2), y + (height / 2));
        setStar(height / 2, x + (height / 2), y + (height / 2));
    }
    
  
}

int main(){
    int n;
    scanf("%d",&n);

    setStar(n, n-1, 0);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n*2-1 ; j++){
            if(space[i][j] == '\0'){
                printf(" ");
            }
            else{
                printf("%c",space[i][j]);
            }
        }
        printf("\n");
    }
}