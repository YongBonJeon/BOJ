#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char map[9][9][100]={0,};
char temp[9][9] = {0,};
int dir[9][2] = {{0,0}, {-1,0}, {0,1}, {-1,1}, {1,0}, {1,1}, {0,-1}, {1,-1}, {-1,-1}};
/* 제자리, 상, 우, 우상, 하, 우하, 좌, 좌하, 좌상 */
int visited[8][8][8] = {0,};

typedef struct{
    int y;
    int x;
    int sec;
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

void makeMap(){
    for(int sec = 0 ; sec < 100 ; sec++){
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                map[i][j][sec] = '.';
            }
        }
    }


    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            map[i][j][0] = temp[i][j];
        }
    }

    for(int sec = 0 ; sec < 10 ; sec++){
        for(int i = 6 ; i >= 0 ; i--){
            for(int j = 0 ; j < 8 ; j++){
                if(map[i][j][sec] == '#'){
                    map[i][j][sec+1] = '.';
                    map[i+1][j][sec+1] = '#';
                }
            }
        }
    }
}


void bfs(){
    Data cur = {7,0,0};
    Enqueue(&q,cur);
    visited[cur.y][cur.x][0] = 1;

    while(!QIsEmpty(&q)){
        cur = Dequeue(&q);

        for(int i = 0 ; i < 9 ; i ++){
            /* 이동 */
            Data next = {cur.y+dir[i][0], cur.x+dir[i][1],cur.sec};

            /* 좌표 유효성 검사 */
            if(next.y < 0 || next.x < 0 || next.y > 7 || next.x > 7){
                continue;
            }

            if(next.y == 7 && next.x == 7){
                printf("1\n");
                return ;
            }
            
            /* 벽이면 이동 x */
            if(map[next.y][next.x][next.sec] == '#'){
                continue;
            }

            /* 벽 이동 */
            next.sec++;
            if(map[next.y][next.x][next.sec] == '#'){ /* 벽에 깔렸다면 */
                continue;
            }
            else{ /* 벽에 깔리지 않고 방문한 적이 없다면 */
                if(visited[next.y][next.x][next.sec] == 0){
                    Enqueue(&q,next);
                    visited[next.y][next.x][next.sec] = visited[cur.y][cur.x][cur.sec] + 1;
                }
            }
        }
    }
    printf("0\n");
}

int main(){
    for(int i = 0 ; i < 8 ; i++){
        scanf("%s",temp[i]);
    }
    makeMap();

    /*for(int sec = 0 ; sec < 15 ; sec++){
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                printf("%c",map[i][j][sec]);
            }
            printf("\n");
        }
        printf("\n\n");
    }*/
    
    bfs();
}