#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node1{
    Data data;
    struct _node1 *next;
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

typedef struct _node{
    int destination;
    struct _node *next;
}node;

typedef node* nodePointer;

typedef struct _adj_list{
    nodePointer *head;
    int *visitInfo;
    int num_node;
}adj_list;

adj_list* init_adj_list(int num_node){
    adj_list* new_list = (adj_list*)malloc(sizeof(adj_list));

    new_list->head = (nodePointer*)malloc(sizeof(nodePointer)*(num_node+1));
    for(int i = 0 ; i <= num_node ; i++){
        new_list->head[i] = (nodePointer)malloc(sizeof(node));
        new_list->head[i]->destination = 0;
        new_list->head[i]->next = NULL;
    }
    new_list->visitInfo = (int*)malloc(sizeof(int)*(num_node+1));
    new_list->num_node = num_node;

    return new_list;
}

nodePointer init_node(int dest){
    nodePointer new_node = (nodePointer)malloc(sizeof(node));
    
    new_node->destination = dest;
    new_node->next = NULL;

    return new_node;
}
int end_flag = 0;
int parent[100001] = {0,};
void dfs(adj_list* al, int v, int target){
    /* 방문 */
    al->visitInfo[v] = 1;

    nodePointer cur = al->head[v]->next;
    //printf("%d\n",cur->destination);
    while(cur != NULL){
        if(cur->destination == target){
            printf("%d\n",v);
            end_flag = 1;
            return ;
        }
        if(al->visitInfo[cur->destination] == 0){
            //printf("%d\n",cur->destination);
            dfs(al, cur->destination, target);
            if(end_flag){return;}
        }
        cur = cur->next;
    }
}

void bfs(adj_list *al, int v, int target){
    al->visitInfo[v] = 1;
    Enqueue(&q, v);

    while(!QIsEmpty(&q)){
        int v = Dequeue(&q);
        nodePointer cur = al->head[v];

        while(cur->next != NULL){
            nodePointer next = cur->next;
            //printf("%d\n",next->destination);

            if(al->visitInfo[next->destination] == 0){
                parent[next->destination] = v;
                Enqueue(&q, next->destination);
                al->visitInfo[next->destination] = 1;
            }
            cur = cur->next;
        }
    }
}

void add_edge(adj_list *al, int st, int dt){
    nodePointer new_start_node = init_node(dt);
    new_start_node->next = al->head[st]->next;
    al->head[st]->next = new_start_node;

    nodePointer new_end_node = init_node(st);
    new_end_node->next = al->head[dt]->next;
    al->head[dt]->next = new_end_node;
}

int main(){
    int n;

    scanf("%d",&n);

    adj_list* al = init_adj_list(n);
   
    int st, dt;
    for(int i = 0 ; i < n-1 ; i++){
        scanf("%d %d",&st, &dt);
       //printf("%d %d\n",st,dt);

        add_edge(al, st, dt);
    }

    for(int j = 0 ; j <= n ; j++){
            al->visitInfo[j] = 0;
        }
    for(int i = 2 ; i <= 2 ; i++){
        for(int j = 0 ; j <= n ; j++){
            al->visitInfo[j] = 0;
        }
        QueueInit(&q);
        bfs(al, 1, i);
        //dfs(al, 1, i);
        end_flag = 0;
    }
    for(int i = 2 ; i <= n ; i++){
        printf("%d\n",parent[i]);
    }
}