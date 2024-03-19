#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; 
    int n,k; //갖고 있는 랜선 수 , 갖고 싶은 랜선 수
    long long max_len=0; //랜선 최대 길이
    long long *pre_len; //갖고 있는 랜선의 길이
    int post_len=0; //잘라서 만들어지고 있는 랜선 수
    scanf("%d %d",&n,&k);

    pre_len=(long long*)malloc(sizeof(long long)*n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&pre_len[i]);
        if(max_len<pre_len[i])
            max_len=pre_len[i];
    }

    long long first=1;
    long long mid;
    long long want=0;
    long long result=0;

    while(first<=max_len){
        want=0;
        mid=(first+max_len)/2;
    
        for(i=0;i<n;i++)
            want+=(pre_len[i]/mid);

        if(want<k)
            max_len=mid-1;
        else
        {
            first=mid+1;
            if(result<mid)
                result=mid;
        }
    }
    printf("%d\n",result);

    return 0;
}