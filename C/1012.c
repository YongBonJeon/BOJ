#include <stdio.h>

#include <stdlib.h>

#define MAX 51
#define TRUE 1
#define FALSE 0

int row, column, worm;
char map[MAX][MAX] = {0,};
int visited[MAX][MAX] = {1,};
int y[MAX*MAX];
int x[MAX*MAX];
int dir[4][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};

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

int bfs(int y, int x){

    /* 지렁이 방문 */
    if(visited[y][x] == 0){
        visited[y][x] = 1;
    }
    else{
        return 0;
    }
    
    Data cur = {y,x};
    //printf("bb %d %d\n",y,x);
    Enqueue(&q, cur);

    while(!QIsEmpty(&q)){
        cur = Dequeue(&q);
        //printf("cc %d %d\n",cur.y,cur.x);
        for(int i = 0 ; i < 4 ; i++){
            Data next = {cur.y+dir[i][0], cur.x+dir[i][1]};

            /* 유효성 검사 */
            if(next.y < 0 || next.x < 0 || next.y > column-1 || next.x > row-1){
                continue;
            }

            /* 지렁이가 이미 방문을 안했고 배추가 심어져 있는 경우에 방문 */
            if(map[next.y][next.x] == 1 && visited[next.y][next.x] == 0){
                Enqueue(&q, next);
                //printf("bb %d %d\n",next.y,next.x);
                visited[next.y][next.x] = 1;
            }

        }
    }
    return 1;
}


int main(){
    int test_num;

    scanf("%d",&test_num);

    while(test_num > 0){
        int ans = 0;
        scanf("%d %d %d",&row, &column, &worm);

        for(int i = 0 ; i < worm ; i++){
            scanf("%d %d",&x[i], &y[i]);
            map[y[i]][x[i]] = 1;
            visited[y[i]][x[i]] = 0;
        }
        //printf("\n\n");
        for(int i = 0 ; i < worm ; i++){
            //printf("%d %d\n",y[i],x[i]);
            ans+=bfs(y[i], x[i]);
        }

        printf("%d\n",ans);
        test_num--;
    }
}