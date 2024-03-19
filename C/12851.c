#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int map[100001];
int visited[100001];
//int dir[3] = {};
int n,m;

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

int min = 1000000;
void bfs(Data v){
    visited[v] = 1;
    Enqueue(&q, v);

    while(!QIsEmpty(&q)){
        int cur = Dequeue(&q);
        //printf("%d %d\n",cur,visited[cur]);

        int next;

        next = cur*2;
        if(next >= 0 && next <= 100000 && next <= m*3){
            if(next == m){
                if(visited[cur] <= min){
                    //printf("mate %d\n",cur);
                    min = visited[cur];
                    visited[m]++;
                    //continue;
                }
            }
            else if(visited[next] == 0 || visited[next] >= visited[cur] + 1){
                visited[next] = visited[cur] + 1;
                Enqueue(&q, next);
            }
        }

        next = cur+1;
        if(next >= 0 && next <= 100000 && next <= m){
            if(next == m){
                if(visited[cur] <= min){
                    //printf("mate %d\n",cur);
                    min = visited[cur];
                    visited[m]++;
                    //continue;
                }
            }
           else if(visited[next] == 0 || visited[next] >= visited[cur] + 1){
                visited[next] = visited[cur] + 1;
                Enqueue(&q,next);
            }
        }

        next = cur-1;
        if(next >= 0 && next <= 100000){
            if(next == m){
                if(visited[cur]<= min){
                    //printf("mate %d\n",cur);
                    min = visited[cur];
                    visited[m]++;
                    //continue;
                }
            }
            else if(visited[next] == 0 || visited[next] >= visited[cur] + 1){
                visited[next] = visited[cur] + 1;
                Enqueue(&q, next);
            }
        }
    }
}

int main(){
    scanf("%d %d",&n, &m);

    if(n == m){
        min = 0;
        visited[n] =1;
    }
    else{
        bfs(n);
    }
    

    printf("%d\n%d\n",min,visited[m]);
}