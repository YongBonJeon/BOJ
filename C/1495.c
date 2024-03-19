#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 51

int gapVolumn[MAX];
int numOfMusic, startVolumn, MaxVolumn, MyMax=0;
int cnt=0;

void Music(int Volumn, int n){
    
    if(n-1 == numOfMusic){
        //printf("%d\n",Volumn);
        if(MyMax < Volumn){
            MyMax = Volumn;
        }
        cnt++;
        return ;
    }
    if(Volumn+gapVolumn[n] <= MaxVolumn){
        Music(Volumn+gapVolumn[n],n+1);
    }
    
    if(Volumn-gapVolumn[n] >= 0){
        Music(Volumn-gapVolumn[n],n+1);
    }
}

int main(){
    
    int curVolumn = startVolumn;
    scanf("%d %d %d",&numOfMusic, &startVolumn, &MaxVolumn);

    for(int i = 1 ; i <= numOfMusic ; i++){
        scanf("%d",&gapVolumn[i]);
    }

    Music(startVolumn,1);

    if(cnt == 0){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",MyMax);

}