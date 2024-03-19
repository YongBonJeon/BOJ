#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int m,n;
int **map; //토마토 상태 
int day=1; //날짜


typedef struct _pair
{
    int x;
    int y;
}coordinate;

typedef coordinate Bdata;

typedef struct _node
{
    Bdata data;
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
void Enqueue(Queue *pqueue, int x,int y)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data.x=x;
    newNode->data.y=y;
    newNode->next=NULL;
    //printf("x%d y%d\n",x,y);
    if(QIsEmpty(pqueue))
        pqueue->front=newNode;
    else
        pqueue->rear->next=newNode;
    pqueue->rear=newNode;
    pqueue->numOfData++;
}

Bdata Dequeue(Queue *pqueue)
{
    if(QIsEmpty(pqueue))
    {
        printf("Queue is empty\n");
    }
    Node *rNode=pqueue->front;
    Bdata rdata=rNode->data;

    pqueue->front=pqueue->front->next;
    pqueue->numOfData--;

    free(rNode);

    return rdata;
}
int QSize(Queue *pqueue)
{
    return pqueue->numOfData;
}
/*Bdata QFPeek(Queue *pqueue)
{
    if(QIsEmpty(pqueue))
    {
        printf("Queue is empty\n");
        return ;
    }
    return pqueue->front->data;
}
Bdata QRPeek(Queue *pqueue)
{
    if(QIsEmpty(pqueue))
    {
        printf("Queue is empty\n");
        return ;
    }
    return pqueue->rear->data;
}*/

void bfs(Queue *pqueue);

int main()
{
    int i,j;
    Queue queue; //다음 토마토를 익힐 익은 토마토
    
    scanf("%d %d ",&m,&n);
    map=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        map[i]=(int*)malloc(sizeof(int)*m); //토마토 좌표
    QueueInit(&queue);

     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==1)
                Enqueue(&queue,j,i); //다른 토마토를 익게 할 토마토 좌표 enqueue
        }
    }
    bfs(&queue);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(map[i][j]==0)
            {
                printf("-1\n"); 
                return 0;
            }
        }
    }
    printf("%d\n",day-1);
    return 0;
    
}
void bfs(Queue *pqueue)
{
    while(!QIsEmpty(pqueue)) //더이상 익게할 곳이 없을 때까지
    {
        Bdata data=Dequeue(pqueue);
        int x=data.x;
        int y=data.y;
        
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n)
            {
                if(map[ny][nx]==0)
                {
                    //안익은 토마토 익혀주기
                    map[ny][nx]=map[y][x]+1;
                    Enqueue(pqueue,nx,ny);
                    //이해 안됨
                    if(day<map[ny][nx])
                        day=map[ny][nx];
                }
            }
        }
    }
}