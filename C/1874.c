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
    Stack stack;
    int n;
    int i;
    scanf("%d",&n);
    int sequence[n];
    char *symbol=(char*)malloc(sizeof(char)*(2*n+1));

    StackInit(&stack);
    for(i=0;i<n;i++)
    {
        scanf("%d",&sequence[i]);
    }
    int sidx=0; //sequence idx
    int aidx=0; //1~n까지 스택에 push된지 여부 
    int kidx=0; //symbol idx
    int top=0; //스택 top


    while(1)
    {
        if(sequence[sidx]>top)
        {
            SPush(&stack,++aidx);
            symbol[kidx++]='+';
            top=SPeek(&stack);
        }
        else if(sequence[sidx++]==top)
        {
            SPop(&stack);
            symbol[kidx++]='-';
            top=SPeek(&stack);
        }
        else if(sequence[i]<top)
        {
            printf("NO\n");
            return 0;
        }
        if(kidx==2*n)
            break;
    }
    int len=strlen(symbol);
    //printf("%dlen\n",len);
    for(i=0;i<len;i++)
        printf("%c\n",symbol[i]);
    
    return 0;
}