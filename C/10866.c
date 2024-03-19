#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    struct _node *next;
    struct _node *before;
    Data data;
}Node;

typedef struct _deque
{
    Node *head;
    Node *tail;
    int numOfData;
}Deque;

void DequeInit(Deque *pdeque)
{
    pdeque->head=NULL;
    pdeque->tail=NULL;
    pdeque->numOfData=0;
}

int DequeIsEmpty(Deque *pdeque)
{
    if(pdeque->head==NULL&&pdeque->tail==NULL)
        return 1;
    return 0;
}

void pushFront(Deque *pdeque, Data data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->before=NULL;

    if(DequeIsEmpty(pdeque))
        pdeque->tail=newNode;
    else
        pdeque->head->before=newNode;

    newNode->next=pdeque->head;
    pdeque->head=newNode;
    pdeque->numOfData++;
   // printf("c\n");
}

void pushBack(Deque *pdeque, Data data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    if(DequeIsEmpty(pdeque))
        pdeque->head=newNode;
    else
        pdeque->tail->next=newNode;
    
    newNode->before=pdeque->tail;
    pdeque->tail=newNode;
    pdeque->numOfData++;
    //printf("d\n");
}

Data popFront(Deque *pdeque)
{
    if(DequeIsEmpty(pdeque))
        return -1;
    
    Node *rNode=pdeque->head;
    Data rData=pdeque->head->data;

    pdeque->head=pdeque->head->next;
    free(rNode);

    if(pdeque->head==NULL)
        pdeque->tail=NULL;
    else
        pdeque->head->before=NULL;
    pdeque->numOfData--;

    return rData;
}

Data popBack(Deque *pdeque)
{
    if(DequeIsEmpty(pdeque))
        return -1;

    Node *rNode=pdeque->tail;
    Data rData=pdeque->tail->data;

    pdeque->tail=pdeque->tail->before;
    free(rNode);

    if(pdeque->tail==NULL)
        pdeque->head=NULL;
    else
        pdeque->tail->next=NULL;
    pdeque->numOfData--;

    return rData;
}

int DequeSize(Deque *pdeque)
{
    return pdeque->numOfData;
}

Data peekFront(Deque *pdeque)
{
    if(DequeIsEmpty(pdeque))
        return -1;
    return pdeque->head->data;
}

Data peekBack(Deque *pdeque)
{
    if(DequeIsEmpty(pdeque))
        return -1;
    return pdeque->tail->data;
}

int main()
{
    int num_Inst;
    int i;
    char *token;
    Deque deque;

    DequeInit(&deque);
    scanf("%d",&num_Inst);

    for(i=0;i<num_Inst;i++)
    {
        char Inst[100]={0, };
        token=NULL;
        scanf(" %[^\n]",Inst);
        //printf("%s\n",Inst);

        token=strtok(Inst,"_");
       // printf("%s\n",token);

        if(strcmp(token,"size")==0)
        {
            printf("%d\n",DequeSize(&deque));
        }
        else if(strcmp(token,"empty")==0)
        {
            printf("%d\n",DequeIsEmpty(&deque));
        }
        else if(strcmp(token,"front")==0)
        {
            //printf("ft\n");
            printf("%d\n",peekFront(&deque));
        }
        else if(strcmp(token,"back")==0)
        {
            //printf("bk\n");
            printf("%d\n",peekBack(&deque));
        }
        else if(strcmp(token,"push")==0)
        {
            token=strtok(NULL," ");
            //printf("3\n");
            if(strcmp(token,"front")==0)
            {
                //printf("4\n");
                token=strtok(NULL, " ");
                //printf("%s\n",token);
                int data=atoi(token);
                //printf("%d ",data);
                pushFront(&deque,data);
            }
            else if(strcmp(token,"back")==0)
            {
                token=strtok(NULL, " ");
                int data=atoi(token);
                //printf("%d ",data);
                pushBack(&deque,data);
            }
        }
        else if(strcmp(token,"pop")==0)
        {
            token=strtok(NULL," ");
            if(strcmp(token,"front")==0)
            {
                printf("%d\n",popFront(&deque));
            }
            else if(strcmp(token,"back")==0)
            {
                printf("%d\n",popBack(&deque));
            }
        }
    }
    return 0;
}
