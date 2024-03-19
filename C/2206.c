#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
#define TRUE 1
#define FALSE 0

int dir[4][2] = {{1,0}, {0,1}, {-1, 0},{0, -1}};
int column,row;
int map[MAX][MAX];
int visited[MAX][MAX][2]; //정점 방문 여부

typedef struct vector{
    int x;
    int y;
    int block;
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

int bfs(){
    coordinate cur={0, 0, 1};
    Enqueue(&q,cur);
    visited[0][0][1] = 1; 
    //printf("%d %d\n",cur.y,cur.x);

    coordinate next;
    while(!QIsEmpty(&q)){
        cur = Dequeue(&q);
        if(cur.y == column-1 && cur.x == row-1){
            return visited[cur.y][cur.x][cur.block];
        }

        for(int i = 0 ; i < 4 ; i++){
            next.y = cur.y + dir[i][0];
            next.x = cur.x + dir[i][1];
            if(next.y >= 0 && next.y <= column-1 && next.x >= 0 && next.x <= row-1){
                //다음 칸이 벽이고 뚫을 수 있을 때
                if(map[next.y][next.x] == 1 && cur.block == 1){
                    next.block = 0;
                    Enqueue(&q,next);
                    visited[next.y][next.x][0] = visited[cur.y][cur.x][1] + 1;
                }
                //다음 칸이 0이고 방문하지 않았을 때
                else if(map[next.y][next.x] == 0 && visited[next.y][next.x][cur.block] == 0){
                    next.block = cur.block;
                    Enqueue(&q, next);
                    visited[next.y][next.x][cur.block] = visited[cur.y][cur.x][cur.block] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d",&column,&row);

    for(int i = 0 ; i < column ; i++){
        for(int j = 0 ; j < row ; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    coordinate start = {0,0};

    printf("%d\n",bfs());


    
}