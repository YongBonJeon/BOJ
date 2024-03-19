#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 25

int map[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};
int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
int n;

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


int bfs(Data start){
    int num = 0;
    Enqueue(&q, start);
    visited[start.y][start.x] = 1;

    while(!QIsEmpty(&q)){
        Data cur = Dequeue(&q);

        for(int i = 0 ; i < 4 ; i++){
            Data next = {cur.y + dir[i][0], cur.x + dir[i][1]};

            /* 유효성 검사 */
            if(next.y < 0 || next.x < 0 || next.y > n-1 || next.x > n-1){
                continue;
            }

            if(map[next.y][next.x] == 1 && visited[next.y][next.x] == 0){
                Enqueue(&q, next);
                visited[next.y][next.x] = 1;
                num++;
            }
        }

    }
    return num+1;
}


int compare(const void *a, const void *b){
    if(*(int*)a == *(int*)b){
        return 0;
    }
    else if(*(int*)a < *(int*)b){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    int num[MAX*MAX]={0,};
    int num_idx = 0;
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                Data start = {i,j};
                num[num_idx++] = bfs(start);
            }
        }
    }
    qsort(num, num_idx, sizeof(int), compare);
    printf("%d\n",num_idx);
    for(int i = 0 ; i < num_idx; i++){
        printf("%d\n",num[i]);
    }
}