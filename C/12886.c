#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int X,Y,Z;
int sum;
int visited[1501][1501] = {0,};

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

void sort(int *X, int *Y, int *Z){
    if(*X > *Y){
        int temp = *X;
        *X = *Y;
        *Y = temp;
    }
    if(*X > *Z){
        int temp = *X;
        *X = *Z;
        *Z = temp;
    }
    if(*Y > *Z){
        int temp = *Y;
        *Y = *Z;
        *Z = temp;
    }
}


void bfs(Data V){
    Enqueue(&q,V);
    visited[V.y][V.x] = 1;
    //printf("%d ",V);

    while(!QIsEmpty(&q)){
        //printf("sibal");
        V = Dequeue(&q);

        //printf("%d %d %d\n",V.y,V.x,sum-V.y-V.x);
        if(V.y == V.x && V.y == (sum-V.y-V.x)){
            printf("1\n");
            return ;
        }

        Data next;
        int tempX;
        int tempY;
        int tempZ;

        if(V.x != sum-V.x-V.y){
        tempX = V.x + V.x;
        tempY = V.y;
        tempZ = (sum-V.y-V.x) - V.x;

        sort(&tempX, &tempY, &tempZ);
        //printf("%d %d %d\n",tempX,tempY,tempZ);
        next.x = tempX;
        next.y = tempY;

        if(visited[next.x][next.y] == 0){
            Enqueue(&q,next);
            visited[next.x][next.y]++;
        }
        }

        if(V.x != V.y){
        tempX = V.x + V.x;
        tempY = V.y - V.x;
        tempZ = (sum-V.y-V.x);

        sort(&tempX, &tempY, &tempZ);
        next.x = tempX;
        next.y = tempY;

        if(visited[next.x][next.y] == 0){
            Enqueue(&q,next);
            visited[next.x][next.y]++;
        }
        }

        if(V.y != sum-V.x-V.y){
        tempX = V.x;
        tempY = V.y + V.y;
        tempZ = (sum-V.y-V.x) - V.y;

        sort(&tempX, &tempY, &tempZ);
        next.x = tempX;
        next.y = tempY;

        if(visited[next.x][next.y] == 0){
            Enqueue(&q,next);
            visited[next.x][next.y]++;
        }
        }
    }
    printf("0\n");
}

int main(){
    scanf("%d %d %d",&X, &Y, &Z);

    sort(&X, &Y, &Z);

    sum = X + Y + Z;

    Data start;
    start.x = X;
    start.y = Y;

    if(sum%3 == 0){
        bfs(start);
    }
    else
        printf("0\n");
}