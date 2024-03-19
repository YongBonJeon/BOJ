#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define TRUE 1
#define FALSE 0

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


typedef struct _Adj_list_node{
    int destination;
    int weight;
    struct _Adj_list_node *next;
}Adj_list_node;

typedef Adj_list_node* Adj_list_pointer;

typedef struct Adj_list{
    Adj_list_pointer *head;
    int *visited;
    int num_head;
}Adj_list;

Adj_list* init_adj_list(int n){
    Adj_list* al = (Adj_list*)malloc(sizeof(Adj_list));

    al->head = (Adj_list_pointer*)malloc(sizeof(Adj_list_pointer)*(n+1));
    al->num_head = n;
    al->visited = (int*)malloc(sizeof(int)*(n+1));

    for(int i = 0 ; i <= n ; i++){
        al->head[i] = (Adj_list_pointer)malloc(sizeof(Adj_list_node));
        al->head[i]->destination = 0;
        al->head[i]->weight = 0;
        al->head[i]->next = NULL;
    }

    return al;
}

Adj_list_pointer init_adj_list_node(int dest, int wg){
    Adj_list_pointer new_node;
    new_node = (Adj_list_pointer)malloc(sizeof(Adj_list_node));
    new_node->destination = dest;
    new_node->weight = wg;
    new_node->next = NULL;

    return new_node;
}

void add_edges(Adj_list *al, int start, int dest, int weight){
    Adj_list_pointer new_start_node = init_adj_list_node(dest, weight);
    new_start_node->next = al->head[start]->next;
    al->head[start]->next = new_start_node;
}

int total_max = 0;
int most_vertex;

int bfs(Adj_list *al, Data vertex){
    int distance_max = 0;
    //int most_vertex;

    al->visited[vertex] = TRUE;
    Enqueue(&q, vertex);
    //Adj_list_pointer cur = al->head[vertex]->next;
    

    while(!QIsEmpty(&q)){
        Data v = Dequeue(&q);
        //printf("x\n");

        Adj_list_pointer cur = al->head[v]->next;
        while(cur != NULL){
            if(al->visited[cur->destination] == 0){
                Enqueue(&q, cur->destination);
                //distance += cur->weight;
                al->visited[cur->destination] = al->visited[v] + cur->weight;
                if(distance_max < al->visited[cur->destination]){
                    most_vertex = cur->destination;
                    distance_max = al->visited[cur->destination];
                }
            }
            cur = cur->next;
        }
    }
    return distance_max;
}

void reset(Adj_list *al, int n){
    for(int i = 0 ; i <= n ; i++){
        al->visited[i] = 0;
    }
}

int main(){
    int n;
    Adj_list *al;

    scanf("%d",&n);
    al = init_adj_list(n);

    for(int i = 1 ; i <= n ; i++){
        int v;
        scanf("%d",&v);
        
        while(1){
            int destination, weight;
            scanf("%d",&destination);
            if(destination == -1){
                break;
            }
            scanf("%d",&weight);

            add_edges(al, v, destination, weight);
        }
        //printf("e?\n");
    }

    QueueInit(&q);
    reset(al, n);
    bfs(al,1);
    QueueInit(&q);
    reset(al, n);
    printf("%d\n", bfs(al, most_vertex)-1);
}