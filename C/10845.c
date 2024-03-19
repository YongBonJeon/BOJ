#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
}Node;

typedef struct _queue
{
    Node *front;
    Node *rear;
    int numOfData;
}Queue;

void QueueInit(Queue *pqueue)
{
    pqueue->front=NULL;
    pqueue->rear=NULL;
    pqueue->numOfData=0;
}
int QIsEmpty(Queue *pqueue)
{
    if(pqueue->front==NULL)
        return 1;
    return 0;
}
void Enqueue(Queue *pqueue, int data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(QIsEmpty(pqueue))
        pqueue->front=newNode;
    else
        pqueue->rear->next=newNode;
    pqueue->rear=newNode;
    pqueue->numOfData++;
}

int Dequeue(Queue *pqueue)
{
    if(QIsEmpty(pqueue))
        return -1;
    Node *rNode=pqueue->front;
    int rdata=rNode->data;

    pqueue->front=pqueue->front->next;
    pqueue->numOfData--;

    free(rNode);

    return rdata;
}
int QSize(Queue *pqueue)
{
    return pqueue->numOfData;
}
int QFPeek(Queue *pqueue)
{
    if(QIsEmpty(pqueue))
        return -1;
    return pqueue->front->data;
}
int QRPeek(Queue *pqueue)
{
    if(QIsEmpty(pqueue))
        return -1;
    return pqueue->rear->data;
}

int main()
{
    int n,idx=0,data;
    char arr[100];
    char *tok;

    Queue queue;
    QueueInit(&queue);
    scanf("%d ",&n);
    if(n<1||n>10000)
        return 0;
    while(idx!=n)
    {
        scanf(" %[^\n]",arr);
        if(strcmp(arr,"front")==0){
            printf("%d\n",QFPeek(&queue));
        }
        else if(strcmp(arr,"back")==0){
            printf("%d\n",QRPeek(&queue));
        }
        else if(strcmp(arr,"size")==0){
            printf("%d\n",QSize(&queue));
        }
        else if(strcmp(arr,"empty")==0){
            printf("%d\n",QIsEmpty(&queue));
        }
        else if(strcmp(arr,"pop")==0){
            printf("%d\n",Dequeue(&queue));
        }
        else
        {
            tok=strtok(arr," ");
            tok=strtok(NULL," ");
            data=atoi(tok);
            Enqueue(&queue,data);
        }
        idx++;
    }
    return 0;
}