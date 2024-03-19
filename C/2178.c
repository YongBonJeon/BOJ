#include <stdio.h>
#include <stdlib.h>

#define MAX 101
#define TRUE 1
#define FALSE 0

int column, row;
int map[MAX][MAX];
int visited[MAX][MAX] ={0,};
int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
int min = MAX*MAX;

typedef struct{
    int y;
    int x;
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

void bfs(int y, int x){
    Data cur = {y,x};
    Enqueue(&q, cur);

    while(!QIsEmpty(&q)){
        cur = Dequeue(&q);
        for(int i = 0 ; i < 4 ; i++){
            Data next = {cur.y+dir[i][0], cur.x+dir[i][1]};

            if(next.y == column-1 && next.x == row-1){
                printf("%d\n",visited[cur.y][cur.x] + 1);
                return ;
            }

            /* 유효성 검사 */
            if(next.y < 0 || next.x < 0 || next.y > column-1 || next.x > row-1){
                continue;
            }

            /* 갈 수 있는 길이고 이미 방문을 하지 않았다면 */
            if(map[next.y][next.x] == 1 && visited[next.y][next.x] == 0){
                Enqueue(&q, next);
                //printf("bb %d %d\n",next.y,next.x);
                visited[next.y][next.x] = visited[cur.y][cur.x] + 1;
            }

        }
    }
    //return 1;
}

int main(){
    scanf("%d %d",&column, &row);

    for(int i = 0 ; i < column ; i++){
        for(int j = 0 ; j < row ; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    visited[0][0] = 1;
    bfs(0, 0);

}