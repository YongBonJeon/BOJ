#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 200001
#define TRUE 1
#define FALSE 0

//int N,K;
int map[MAX];
int visited[MAX];

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


int find(int N, int K){
    Data cur = N;
    Enqueue(&q,cur);
    visited[cur] = 0;

    while(!QIsEmpty(&q)){
        cur = Dequeue(&q);
        
        if(cur == K){
            return visited[cur];
        }

        for(int i = 0 ; i < 3 ; i++){
            Data next;
            switch(i){
                case 0:
                    next = cur+1;
                    if(next >= 0 && next < MAX){
                        if(visited[next] > visited[cur]+1){
                            visited[next] = visited[cur]+1;
                        }
                    }
                    if(next > 2*K){break;}
                    if(next >= 0 && next < MAX && visited[next] == 0){
                        Enqueue(&q,next);
                        //printf("0next%d\n",next);
                        visited[next] = visited[cur] + 1;
                    }
                    break;
                case 1:
                    next = cur-1;
                    if(next >= 0 && next < MAX){
                        if(visited[next] > visited[cur]+1){
                            //printf("sibal\n");
                            visited[next] = visited[cur]+1;
                        }
                    }
                    if(next >= 0 && next < MAX && visited[next] == 0){
                        Enqueue(&q,next);
                        //printf("1next%d",next);
                        visited[next] = visited[cur] + 1;
                        //printf("v %d\n",visited[next]);
                    }
                    break;
                case 2:
                    next = cur*2;
                    if(next >= 0 && next < MAX){
                        if(visited[next] > visited[cur]+1){
                            visited[next] = visited[cur]+1;
                        }
                    }
                    if(next > 2*K){break;}
                    if(next >= 0 && next < MAX && visited[next] == 0){
                        Enqueue(&q,next);
                        //printf("2next%d\n",next);
                        visited[next] = visited[cur] + 1;
                    }
                    break;
            }
        }
        /*for(int i = 1 ; i <= N ; i ++){
            if(map[V][i] == 1 && visited[i] == 0){
                Enqueue(&q,i);
                visited[i] = 1;
                printf("%d ",i);
            }
        }*/
    }
    return 0;
}

int main(){
    int N,K;
    scanf("%d %d",&N,&K);

    printf("%d\n",find(N,K));
}