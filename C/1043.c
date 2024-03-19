#include <stdio.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

int num_people;
int num_party;
int num_know_truth;
int arr_know_truth[MAX] = {0, };
int party[MAX][MAX] = {0,};
int num_party_people[MAX] = {0,};

void talk_truth(int start){
    for(int i = start ; i < num_party ; i++){
        int truth_flag = FALSE;
        /* 파티에 진실을 아는 사람이 있다면 */
        for(int j = 0 ; j < num_party_people[i] ; j++){
            if(arr_know_truth[party[i][j]] == TRUE){
                truth_flag = TRUE;
            }
        }
        
        /* 파티에 있는 인원들에게 진실을 말한다 */
        if(truth_flag){
            for(int j = 0 ; j < num_party_people[i] ; j++){
                arr_know_truth[party[i][j]] = TRUE;
            }
        }
    }
}

int talk_lie(){
    int total_lie = 0;
    for(int i = 0 ; i < num_party ; i++){
        int lie_flag = TRUE;
        /* 파티에 진실을 아는 사람이 없다면 */
        for(int j = 0 ; j < num_party_people[i] ; j++){
            if(arr_know_truth[party[i][j]] == TRUE){
                lie_flag = FALSE;
            }
        }
        if(lie_flag){
            total_lie++;
        }
    }
    return total_lie;
}

int main(){
    scanf("%d %d",&num_people, &num_party);
    
    scanf("%d",&num_know_truth);

    for(int i = 0 ; i < num_know_truth ; i++){
        int temp;
        scanf("%d",&temp);
        arr_know_truth[temp] = TRUE;
    }
    /*printf("\nknow\n");
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",arr_know_truth[i]);
    }
    printf("\nknow\n");*/

    for(int i = 0 ; i < num_party ; i++){
        scanf("%d",&num_party_people[i]);

        for(int j = 0 ; j < num_party_people[i] ; j++){
            scanf("%d",&party[i][j]);
        }
    }

    /* 파티 참가 1. 진실 사람 있는 경우 -> 진실 얘기 -> 참여한 다른 사람 모두 진실을 알게 됨
               2. 진실 사람 없는 경우 -> 과장 얘기 -> 참여한 다른 사람 모두 과장을 알게 됨

    */
   for(int i = 0 ; i < num_party ; i++){
       talk_truth(0);
   }

   /* 과장된 얘기를 할 수 있는 파티의 최댓값 */
   printf("%d\n",talk_lie());

}