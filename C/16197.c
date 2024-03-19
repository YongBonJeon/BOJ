#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define TRUE 1
#define FALSE 0

int M,N;
int coin[3][2];
char map[MAX][MAX];
int visited[MAX][MAX][MAX][MAX] = {0,};
int dir[4][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};

typedef struct{
    int ay;
    int ax;
    int by;
    int bx;
}coordinate;

typedef coordinate Data;

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

/*void reset(){
    for(int i = 1 ; i <= N ; i++){
        visited[i] = 0;
    }
}*/


int bfs(Data CoinSet){

    int flag_a = 0, flag_b = 0;

    Enqueue(&q,CoinSet);
    visited[CoinSet.ay][CoinSet.ax][CoinSet.by][CoinSet.bx] = 1;

    while(!QIsEmpty(&q)){
        Data curCoin = Dequeue(&q);
        if(visited[curCoin.ay][curCoin.ax][curCoin.by][curCoin.bx] > 10){
            return -1;
        }

        for(int i = 0 ; i < 4 ; i ++){
            flag_a = 0;
            flag_b = 0;

            /* 이동 */
            Data nextCoin = {curCoin.ay+dir[i][0], curCoin.ax+dir[i][1], curCoin.by+dir[i][0], curCoin.bx+dir[i][1]};

            /* 벽이면 이동 x */
            if(map[nextCoin.ay][nextCoin.ax] == '#'){
                nextCoin.ay = curCoin.ay;
                nextCoin.ax = curCoin.ax;
            }
            if(map[nextCoin.by][nextCoin.bx] == '#'){
                nextCoin.by = curCoin.by;
                nextCoin.bx = curCoin.bx;
            }

            /* 바닥에 떨어지면 flag on*/
            if(nextCoin.ay < 0 || nextCoin.ax < 0 || nextCoin.ay > M-1 || nextCoin.ax > N-1){
                flag_a = 1;
            }
            if(nextCoin.by < 0 || nextCoin.bx < 0 || nextCoin.by > M-1 || nextCoin.bx > N-1){
                flag_b = 1;
            }

            /* 바닥에 동시에 떨어지면 */
            if(flag_a && flag_b){
                continue;
            }
            /* 둘 중에 하나만 바닥에 떨어지면 */
            else if(flag_a || flag_b){
                return visited[curCoin.ay][curCoin.ax][curCoin.by][curCoin.bx];

            }
            /* 둘 다 바닥에 떨어지지 않고 방문하지 않은 곳이라면 */
            if(visited[nextCoin.ay][nextCoin.ax][nextCoin.by][nextCoin.bx] == 0){
                Enqueue(&q,nextCoin);
                //printf("%d %d %d %d\n",nextCoin.ay,nextCoin.ax,nextCoin.by,nextCoin.bx);
                visited[nextCoin.ay][nextCoin.ax][nextCoin.by][nextCoin.bx] = visited[curCoin.ay][curCoin.ax][curCoin.by][curCoin.bx] + 1;
            }
        }
    }
    return -1;
}


int main(){
    scanf("%d %d",&M,&N);

    for(int i = 0 ; i < M ; i++){
        scanf("%s",map[i]);
    }

    for(int i = 0, k = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ;j++){
            if(map[i][j] == 'o' ){
                coin[k][0] = i;
                coin[k++][1] = j;
            }
        }
    }

    Data CoinSet = {coin[0][0], coin[0][1], coin[1][0], coin[1][1]};

    printf("%d\n",bfs(CoinSet));


}