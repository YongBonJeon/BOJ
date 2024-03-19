#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int map[100][100] = {0,};
int n,m;
int visited[100][100] = {0,};
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

typedef struct coordinate{
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

void reset(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visited[i][j] = 0;
        }
    }
}

int is_inside(int y, int x){
    Data cur = {y,x};
    visited[cur.y][cur.x] = 1;
    Enqueue(&q, cur);

    while(!QIsEmpty(&q)){
        cur = Dequeue(&q);
        //printf("y %d x %d cy%d cx%d\n",y,x,cur.y,cur.x);
        if(cur.y == n-1 || cur.x == m-1 || cur.y == 0 || cur.x == 0){
                if(map[cur.y][cur.x] == 0)
                    return 0;
        }
        for(int i = 0 ; i < 4 ; i++){
            Data next = {cur.y+dir[i][0], cur.x+dir[i][1]};

            if(next.y < 0 || next.y > n-1 || next.x < 0 || next.x > m-1){
                continue;
            }
            
            /* 외부에 도달했으므로 외부임 */
            if(next.y == n-1 || next.x == m-1 || next.y == 0 || next.x == 0){
                if(map[next.y][next.x] == 0)
                    return 0;
            }
            if(map[next.y][next.x] == 0 && visited[next.y][next.x] == 0){
                Enqueue(&q, next);
                visited[next.y][next.x] = 1;
            }
        }
    }
    /* 외부에 도달하지 못했으므로 내부 */
    return 1;
}

int is_melt(int y, int x){
    int melt_flag = 0;
    //int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    /* 내부 확인 */
    QueueInit(&q);
    reset();
    if(is_inside(y,x)){
        return 0;
    }

    /* 외부 공기 확인 */
    for(int i = 0 ; i < 4 ; i++){
        int check_y = y+dir[i][0];
        int check_x = x+dir[i][1];
        if(check_y < 0 || check_x < 0 || check_y > n-1 || check_x > m-1){
            continue;
        }
        if(map[check_y][check_x] == 0){
            int temp;
            QueueInit(&q);
            reset();
            if((temp = is_inside(check_y, check_x)) == 0){
                //printf("y %d x %d cy %d cx %d  %d\n",y,x,check_y,check_x,temp);
                melt_flag++;
            }
        }
    }

    if(melt_flag >= 2){
        return 1;
    }

    return 0;
}

void select_cheese(){

    int temp[100][100] = {0,};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            temp[i][j] = map[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 1){
                //QueueInit(&q);
                if(is_melt(i,j)){
                    temp[i][j] = 0;
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            map[i][j] = temp[i][j];
        }
    }
}

int is_all_melt(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 1){
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    scanf("%d %d",&n, &m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int time = 0;
    while(!is_all_melt()){
        select_cheese();
        /*printf("\n");
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }*/
        time++;
    }

    printf("%d\n",time);
}