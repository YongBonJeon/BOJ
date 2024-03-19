#include <stdio.h>
#include <stdlib.h>

#define MAX_CITY 50
#define TRUE 1
#define FALSE 0

int map[MAX_CITY][MAX_CITY] = {0, };
int visited[MAX_CITY][MAX_CITY] = {0, };
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
int N, M;

typedef struct{
    int y;
    int x;
    int pick;
}coordinate;

typedef coordinate Data;

Data cur_chicken[13];
Data house[2*MAX_CITY]={0,};
int num_house = 0;
int num_chicken = 0;

typedef struct _node{
    Data data;
    struct _node *next;
}Node;

typedef struct _listQueue{
    Node *front;
    Node *rear;
}ListQueue;

typedef ListQueue Queue;
Queue q;

void QueueInit(Queue *pqueue){
    pqueue->front=NULL;
    pqueue->rear=NULL;
}
int QIsEmpty(Queue *pqueue){
    if(!pqueue->front)
        return TRUE;
    return FALSE;
}
void Enqueue(Queue *pqueue, Data data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    if(QIsEmpty(pqueue)){
        pqueue->front=newNode;
        pqueue->rear=newNode;
    }
    else{
        pqueue->rear->next=newNode;
        pqueue->rear=newNode;
    }
}
Data Dequeue(Queue *pqueue){
    if(QIsEmpty(pqueue)){
        printf("Queue is empty\n");
        exit(-1);
    }
    Node *rqueue=pqueue->front;
    Data rdata=rqueue->data;

    pqueue->front=pqueue->front->next;

    free(rqueue);

    return rdata;
}
Data QPeek(Queue *pqueue){
    if(QIsEmpty(pqueue)){
        printf("Queue is empty\n");
        exit(-1);
    }
    return pqueue->front->data;
}


int get_min_distance(Data cur[]){
    int total = 0;
    for(int i = 0 ; i < num_house; i++){
        int dist = 0;
        int house_y = house[i].y;
        int house_x = house[i].x;
        int min = 999999;
        for(int j = 0 ; j < num_chicken ; j++){
            int temp = 0;
            if(cur[j].pick == TRUE){
                temp += abs(house_y - cur[j].y);
                temp += abs(house_x - cur[j].x);
                if(min > temp){
                    min = temp;
                }
            }
        }
        //printf("%d %d %d\n",house_y,house_x,min);
        total += min;
    }
    return total;
}
int total_min = 999999;
void backtracking(Data cur[], int start, int pick){
    if(pick == M){
        int sibal = get_min_distance(cur);
        //printf("\n");
        if(total_min > sibal){
            total_min = sibal;
        }
    }
    for(int i = start ; i < num_chicken ; i++){
        cur[i].pick = TRUE;
        backtracking(cur, i+1,pick+1);
        cur[i].pick = FALSE;
    }
}

int main(){
    scanf("%d %d",&N, &M);

    int temp_map[MAX_CITY][MAX_CITY] = {0,};

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1){
                house[num_house].y = i;
                house[num_house++].x = j;
            }
            if(map[i][j] == 2){
                cur_chicken[num_chicken].y = i;
                cur_chicken[num_chicken++].x = j;
            }
        }
    }
    /* 랜덤으로 M개 만큼 골라 */
    backtracking(cur_chicken, 0, 0);
    printf("%d\n",total_min);
}

/* 0~ M개 치킨집 없애면서 */