#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 3001
#define TRUE 1
#define FALSE 0

typedef struct adjListNode* adjListPointer;
typedef struct adjListNode{
    int dest;
    adjListPointer next;
}adjListNode;

typedef struct adjList{
    int Nnode;
    int *visitInfo;
    adjListPointer* adj_head;
}adjList;

typedef struct stackList* stackPointer;
typedef struct stackList{
    int top;
    int *arr;
}stackList;

stackPointer init_stack(int size){
	stackPointer new_stack = (stackPointer)malloc(sizeof(stackList));
	new_stack->top = -1;
	new_stack->arr = (int*)malloc(sizeof(int)*MAX);

	return new_stack;
}
/* 스택 비어있는지 확인 */
int is_blank(stackPointer stack){
	if(stack->top == -1)
		return 1;
	return 0;
}
/* 스택 삽입 */
void push(stackPointer stack, int element){
	stack->arr[++stack->top] = element;
}
/* 스택 추출 */
int pop(stackPointer stack){
	if(is_blank(stack))
		return -1;
	return stack->arr[stack->top--]; 
}

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

adjList* init_adjList(int num_node){
    adjList* new_adjList = (adjList*)malloc(sizeof(adjList));
    new_adjList->adj_head = (adjListPointer*)malloc(sizeof(adjListPointer)*num_node);
    for(int i = 0 ; i < num_node ; i++){
        new_adjList->adj_head[i] = (adjListPointer)malloc(sizeof(adjListNode));
        new_adjList->adj_head[i]->dest = 0;
        new_adjList->adj_head[i]->next = NULL;
    }

    new_adjList->Nnode = num_node;
    new_adjList->visitInfo = (int*)malloc(sizeof(int)*num_node);
    memset(new_adjList->visitInfo, 0, sizeof(int)*num_node);

    return new_adjList;
}

adjListPointer init_node(int dt){
    adjListPointer new_node = (adjListPointer)malloc(sizeof(adjListNode));
    new_node->dest = dt;
    new_node->next = NULL;

    return new_node;
}

void add_edges(adjList* al, int st, int dt){
    adjListPointer start_new_node = init_node(dt-1);
    start_new_node->next = al->adj_head[st-1]->next;
    al->adj_head[st-1]->next = start_new_node;

    adjListPointer end_new_node = init_node(st-1);
    end_new_node->next = al->adj_head[dt-1]->next;
    al->adj_head[dt-1]->next = end_new_node;
}

int dfs(adjList* al, int st){
    adjListPointer cur_node = al->adj_head[st];
    /* 거리 */
    int depth = 0;

    /* 방문 기록 저장할 스택 초기화 */
    stackPointer stack = init_stack(al->Nnode);

    /* 방문 정점 */
    int visitV = st;

    /* 다음 방문할 정점 */
    int nextV;

    /* 방문 */
    al->visitInfo[visitV] = 1;

    while(al->adj_head[visitV]->next != NULL){
        
        /* 더 방문할 곳이 있었는가? */
        int visitflag = 0;

        /* 현재 정점과 연결된 다음 정점 */
        nextV = al->adj_head[visitV]->next->dest;

        /* 다음 정점을 방문하지 않았다면 */
        if(al->visitInfo[nextV] == 0){
            push(stack, visitV);
            depth++;
            visitV = nextV;
            al->visitInfo[visitV] = 1;
            visitflag = 1;
        }
        /* 다음 정점을 방문 했다면 */
        else{
            adjListPointer cur = al->adj_head[visitV]->next;
            while(cur != NULL){
                /* 다다음 정점 방문 */
                nextV = cur->dest;
                /* 순회가 되는 지 판단 여부 */
                if(nextV == st && depth >= 2){
                    return 1;
                }
                if(al->visitInfo[nextV] == 0){
                    push(stack, visitV);
                    depth++;
                    visitV = nextV;
                    al->visitInfo[visitV] = 1;
                    visitflag = 1;
                    break;
                }
                else{
                    cur = cur->next;
                }
            }
        }
        /* 현재 정점에서 더 이상 방문할 곳이 없다면 */
        if(visitflag == 0){
            //printf("top %d ",stack->top);
            if((stack->top) < 0){
                return 0;
            }
            else{
                if((visitV = pop(stack)) < 0){
                    break;
                }
                depth--;
            }
        }
    }
    return 0;
}

int visited[MAX] = {0, };
int cycle[MAX] = {0,};

int bfs(adjList *al, Data V){
    QueueInit(&q);
    Enqueue(&q, V);
    visited[V] = 1;

    while(!QIsEmpty(&q)){
        Data cur = Dequeue(&q);
        //printf("sipal %d  ",cur);

        if(cycle[cur] == TRUE){
            //printf("cycle cc %d %d\n",cur, visited[cur]);
            return visited[cur];
        }

        adjListPointer p_cur = al->adj_head[cur]->next;

        while(p_cur != NULL){
            Data next = p_cur->dest;

            if(visited[next] == 0){
                //printf("next %d",next);
                Enqueue(&q, next);
                visited[next] = visited[cur] + 1;
            }
            p_cur = p_cur->next;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d ",&n);

    adjList* adj_List = init_adjList(n);

    int st,dt;
    for(int i = 0 ; i < n ; i++){
        scanf("%d %d",&st, &dt); 
        add_edges(adj_List, st, dt);
    }
    /*for(int i = 0 ; i < adj_List->Nnode ; i++){
        adjListPointer cur = adj_List->adj_head[i];
        printf("st %d ",i+1);
        for(cur = cur->next ; cur != NULL ; cur = cur->next){
            printf("%d ",cur->dest + 1);
        }
        printf("\n");
        free(cur);
    }*/
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            adj_List->visitInfo[j] = 0;
        }

        if(dfs(adj_List, i) == 1){
            cycle[i] = TRUE;
        }
        else{
            
            cycle[i] = FALSE;
        }
        //printf("%d ",cycle[i]);
    }
    //printf("\n");
    for(int i = 0 ; i < n ; i++){
      
        if(cycle[i] == FALSE){
            cycle[i] = bfs(adj_List, i);
            //printf("ii %d\n",i);
        }
        for(int j = 0 ; j < n ; j++){
            visited[j] = 0;
        }
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d ",cycle[i]-1);
    }
    printf("\n");

}