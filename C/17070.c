#include <stdio.h>
#include <stdlib.h>

int map[17][17] = {0, };
int visited[17][17] = {0,};
int pipe_direction[3][2];
int n;

#define TRUE 1
#define FALSE 0

typedef struct coordinate{
    int y;
    int x;
    int direction;
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

int total = 0;

void bfs(Data start){
    visited[start.y][start.x] = 1;
    Enqueue(&q, start);

    while(!QIsEmpty(&q)){
        Data cur = Dequeue(&q);

        //printf("%d %d %d\n",cur.y, cur.x, cur.direction);
        if(cur.y == n && cur.x == n){
            total++;
            continue;
        }

        /* 방향이 가로다! */
        Data next;

        if(cur.direction == 1){
            //1
            next.y = cur.y;
            next.x = cur.x+1;
            next.direction = cur.direction;
            if(next.y <= n && next.x <= n){
                if(map[next.y][next.x] == 0){
                    Enqueue(&q, next);
                }
            }
            //2
            next.y = cur.y+1;
            next.x = cur.x+1;
            next.direction = cur.direction+1;
            if(next.y <= n && next.x <= n){
                if(map[cur.y][cur.x+1] == 0 && map[cur.y+1][cur.x] == 0 && map[next.y][next.x] == 0){
                    Enqueue(&q, next);
                }
            }
        }
        else if(cur.direction == 2){
                //3
                next.y = cur.y;
                next.x = cur.x+1;
                next.direction = cur.direction-1;
                if(next.y <= n && next.x <= n){
                    if(map[next.y][next.x] == 0){
                        Enqueue(&q, next);
                    }
                }
                //4
                next.y = cur.y+1;
                next.x = cur.x;
                next.direction = cur.direction+1;
                if(next.y <= n && next.x <= n){
                    if(map[next.y][next.x] == 0){
                        Enqueue(&q, next);
                    }
                }
                //5
                next.y = cur.y+1;
                next.x = cur.x+1;
                next.direction = cur.direction;
                if(next.y <= n && next.x <= n){
                    if(map[cur.y+1][cur.x] == 0 && map[cur.y][cur.x+1] == 0 && map[next.y][next.x] == 0){
                        Enqueue(&q, next);
                    }
                }
            }
            else if(cur.direction == 3){
                next.y = cur.y+1;
                next.x = cur.x;
                next.direction = cur.direction;
                if(next.y <= n && next.x <= n){
                    if(map[next.y][next.x] == 0){
                        Enqueue(&q, next);
                    }
                }

                next.y = cur.y+1;
                next.x = cur.x+1;
                next.direction = cur.direction -1;
                if(next.y <= n && next.x <= n){
                    if(map[cur.y+1][cur.x] == 0 && map[cur.y][cur.x+1] == 0 && map[next.y][next.x] == 0){    
                        Enqueue(&q, next);
                    }
                }
            }
    }
}

int main(){
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    Data start;
    start.y = 1;
    start.x = 2;
    start.direction = 1;

    QueueInit(&q);
    if(map[n][n] == 0){
        bfs(start);
    }
    printf("%d\n",total);
}