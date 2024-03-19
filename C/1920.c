#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(long long arr[],int left, int mid, int right)
{
    int i;
    int frontIdx=left;
    int rearIdx=mid+1;

    long long *sortArr=(long long*)malloc(sizeof(right+1));
    int sortIdx=left;

    while(frontIdx<=mid&&rearIdx<=right)
    {
        if(arr[frontIdx]<=arr[rearIdx])
            sortArr[sortIdx]=arr[frontIdx++];
        else
            sortArr[sortIdx]=arr[rearIdx++];
        sortIdx++;
    }
    if(frontIdx>mid)
    {
        for(i=rearIdx;i<=right;i++,sortIdx++)
            sortArr[sortIdx]=arr[i];
    }
    else
    {
        for(i=frontIdx;i<=mid;i++,sortIdx++)
            sortArr[sortIdx]=arr[i];
    }

    for(i=left;i<=right;i++)
        arr[i]=sortArr[i];

    free(sortArr);
}

void MergeSort(long long arr[],int left, int right)
{
    int mid;

    if(left<right)
    {
        mid=(left+right)/2;

        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);

        MergeTwoArea(arr,left,mid,right);
    }
}
void BubbleSort(int arr[], int n){
    int i,j;
    int temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int BinarySearch(long long *arr,int size, long long target)
{
    int first=0,last=size-1;
    int mid;

    while(first<=last){
        mid=(first+last)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            last=mid-1;
        else
            first=mid+1;
    }
    return -1;
}
int compare(const void *a, const void *b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main()
{
    int n,m;
    int i;
    long long *nArr,*mArr;
    int sidx;
    
    scanf("%d",&n);
    nArr=(long long*)malloc(sizeof(long long)*n);
    for(i=0;i<n;i++)
        scanf("%lld",&nArr[i]);
    scanf("%d",&m);
    mArr=(long long*)malloc(sizeof(long long)*m);
    for(i=0;i<m;i++)
        scanf("%lld",&mArr[i]);

    //nArr을 정렬한 후 이분탐색을 할 거에요
    MergeSort(nArr,0,n-1);
    //BubbleSort(nArr,n);
    //qsort(nArr,n,sizeof(long long),compare);
    for(i=0;i<m;i++)
    {
        sidx=BinarySearch(nArr,n,mArr[i]);
        if(sidx!=-1)
            printf("1\n");
        else
            printf("0\n");
    }
    
    
    return 0;
}