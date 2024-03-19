#include <stdio.h>

#define MAX 500

int n,m;
int map[MAX][MAX];
int tet[4];


int main(){
    scanf("%d %d",&n,&m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf(" %d",&map[i][j]);
        }
    }

    int max=0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m-3 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i][j+2]+map[i][j+3];
            if(temp > max){
                max = temp;
                //printf("1%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-3 ; i++){
        for(int j = 0 ; j < m ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+2][j]+map[i+3][j];
            if(temp > max){
                max = temp;
                //printf("1%d\n",max);
            }
        }
    }



    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i+1][j]+map[i+1][j+1];
            if(temp > max){
                max = temp;
                //printf("2%d\n",max);
            }
        }
    }

    

    for(int i = 0 ; i < n-2 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+2][j]+map[i+2][j+1];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i][j+1]+map[i][j+2];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-2 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+2][j+1];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i][j+2]+map[i-1][j+2];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 2 ; i < n ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i-1][j+1]+map[i-2][j+1];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-2 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+2][j]+map[i][j+1];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+2];
            if(temp > max){
                max = temp;
                //printf("3%d\n",max);
            }
        }
    }





    for(int i = 0 ; i < n-2 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+2][j+1];
            if(temp > max){
                max = temp;
                //printf("4%d\n",max);
            }
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i-1][j+1]+map[i-1][j+2];
            if(temp > max){
                max = temp;
                //printf("4%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-2 ; i++){
        for(int j = 1 ; j < m ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+1][j-1]+map[i+2][j-1];
            if(temp > max){
                max = temp;
                //printf("4%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+1][j+2];
            if(temp > max){
                max = temp;
                //printf("4%d\n",max);
            }
        }
    }






    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1];
            if(temp > max){
                max = temp;
                //printf("5%d\n",max);
            }
        }
    }
    for(int i = 1 ; i < n-1 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i-1][j+1]+map[i+1][j+1];
            if(temp > max){
                max = temp;
                //printf("5%d\n",max);
            }
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m-2 ; j++){
            int temp = map[i][j]+map[i][j+1]+map[i][j+2]+map[i-1][j+1];
            if(temp > max){
                max = temp;
                //printf("5%d\n",max);
            }
        }
    }
    for(int i = 0 ; i < n-2 ; i++){
        for(int j = 0 ; j < m-1 ; j++){
            int temp = map[i][j]+map[i+1][j]+map[i+2][j]+map[i+1][j+1];
            if(temp > max){
                max = temp;
                //printf("5%d\n",max);
            }
        }
    }

    printf("%d\n",max);
}