#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,target;
    int arr[100001];

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&target);
    sort(arr,arr+N);

    int l = 0, r = N-1,t,ans = 0;

    while(l < r)
    {
        t = arr[l]+arr[r];

        if(t == target)
        {
            l++;
            r--;
            ans++;
        }
        else if(t < target)
        {
            l++;
        }
        else if(t > target)
        {
            r--;
        }
    }
    printf("%d\n",ans);

}