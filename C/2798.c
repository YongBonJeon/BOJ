#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n;//카드의 개수
    int max; //3장의 합의 맥시멈
    //int a1,a2,a3; //3장의 카드
    int arr[100];
    int sum; //3장 카드의 합
    int i,j,k,temp;

    scanf("%d %d",&n,&max);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
    sum=3*arr[0];
    for(i=0;i<n;i++)
    {
        /*if(arr[i]>max/3)
            break;*/
        for(j=i+1;j<n;j++)
        {
            /*if(arr[i]>max/2)
                break;*/
            for(k=j+1;k<n;k++)
            {
                temp=arr[i]+arr[j]+arr[k];
                if(temp<=max&&sum<temp)
                    sum=temp;
                /*else
                    break;*/

            }
        }
    }
    printf("%d\n",sum);
    return 0;
}