#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
}Node;

typedef struct _stack
{
    Node *head;
    int numOfData;
}Stack;

void StackInit(Stack *pstack)
{
    pstack->head=NULL;
    pstack->numOfData=0;
}
void SPush(Stack *pstack, int data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    
    newNode->next=pstack->head;
    pstack->head=newNode;
    pstack->numOfData++;
}
int SIsEmpty(Stack *pstack)
{
    if(pstack->head==NULL)
        return 1;
    return 0;
}
int SPop(Stack *pstack)
{
    if(SIsEmpty(pstack))
        return -1;
    Node *rNode=pstack->head;
    int rdata=rNode->data;

    pstack->head=pstack->head->next;
    pstack->numOfData--;

    free(rNode);

    return rdata;
}
int SSize(Stack *pstack)
{
    return pstack->numOfData;
}
int SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack))
        return -1;
    return pstack->head->data;
}

int main()
{
    int n,idx=0,data;
    char arr[100];
    char *tok;

    Stack stack;
    StackInit(&stack);
    scanf("%d ",&n);
    if(n<1||n>10000)
        return 0;
    while(idx!=n)
    {
        scanf(" %[^\n]",arr);
        if(strcmp(arr,"top")==0){
            printf("%d\n",SPeek(&stack));
        }
        else if(strcmp(arr,"size")==0){
            printf("%d\n",SSize(&stack));
        }
        else if(strcmp(arr,"empty")==0){
            printf("%d\n",SIsEmpty(&stack));
        }
        else if(strcmp(arr,"pop")==0){
            printf("%d\n",SPop(&stack));
        }
        else
        {
            tok=strtok(arr," ");
            tok=strtok(NULL," ");
            data=atoi(tok);
            SPush(&stack,data);
        }
        idx++;
    }
    return 0;
}