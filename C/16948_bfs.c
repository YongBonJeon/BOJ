#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
#define TRUE 1
#define FALSE 0

int N;
int start[2];
int end[2];
int dir[6][2] = {{-1, -2}, {1,-2}, {-2,0}, {2,0}, {-1,2}, {1,2}};
int map[MAX][MAX];
int visited[MAX][MAX] = {0,};
int flag=10000;

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

/*void reset(){
    for(int i = 1 ; i <= N ; i++){
        visited[i] = 0;
    }
}*/


void bfs(Data V){

    Enqueue(&q,V);
    visited[V.y][V.x] = 1;
    //printf("%d ",V);

    while(!QIsEmpty(&q)){
        V = Dequeue(&q);

        //printf("%d %d\n",V.y,V.x);
        if(V.y == end[1] && V.x == end[0]){
            printf("%d\n",visited[V.y][V.x]-1);
            return ;
        }

        for(int i = 0 ; i < 6 ; i ++){
            Data next = {V.y+dir[i][0], V.x+dir[i][1]};

            if(next.y < 0 || next.x < 0 || next.y > N-1 || next.x > N-1){
                continue;
            }

            if(visited[next.y][next.x] == 0){
                Enqueue(&q,next);
                visited[next.y][next.x] = visited[V.y][V.x] + 1;
                //printf("%d ",i);
            }
        }
    }
    printf("-1\n");
}

int main(){
    scanf("%d", &N);

    scanf("%d %d %d %d",&start[0], &start[1], &end[0], &end[1]);
    int y = start[1];
    int x = start[0];

    Data start = {y,x};

    QueueInit(&q);

    bfs(start);

    
}