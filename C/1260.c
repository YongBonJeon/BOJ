#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
#define TRUE 1
#define FALSE 0

int N,M,V; //정점개수, 간선개수, 시작정점
int map[MAX][MAX]; //인접 행렬 그래프
int visited[MAX]; //정점 방문 여부

typedef int Data;

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
    int rdata=rqueue->data;

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
    for(int i = 1 ; i <= N ; i++){
        visited[i] = 0;
    }
}

void dfs(int V){
    visited[V] = 1;
    printf("%d ",V);

    for(int i = 1 ; i <= N; i++){
        if(map[V][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }

}

void bfs(int V){
    Enqueue(&q,V);
    visited[V] = 1;
    printf("%d ",V);

    while(!QIsEmpty(&q)){
        V = Dequeue(&q);

        for(int i = 1 ; i <= N ; i ++){
            if(map[V][i] == 1 && visited[i] == 0){
                Enqueue(&q,i);
                visited[i] = 1;
                printf("%d ",i);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0 ; i < M ; i ++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    QueueInit(&q);

    reset();
    dfs(V);
    printf("\n");

    reset();
    bfs(V);
    printf("\n");
}