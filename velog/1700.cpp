#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K,num = 0,ans = 0;
    int arr[101], cnt[101] = {0,};
    bool check[101] = {0,};

    scanf("%d %d",&N, &K);
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d",&arr[i]);
        
        cnt[arr[i]]++;
    }

    for(int i = 0 ; i < K ; i++)
    {
        if(num < N && !check[arr[i]])
        {
            check[arr[i]] = true;
            cnt[arr[i]]--;
            num++;
        }
        else if(check[arr[i]])
        {
            cnt[arr[i]]--;
        }
        else if(num == N && !check[arr[i]])
        {
            int out = -1, tn = 0;
            for(int j = 0 ; j < K ; j++)
            {
                if(check[arr[j]] && cnt[arr[j]] == 0)
                {
                    out = arr[j];
                    break;
                }
            }
            if(out == -1){
                bool sibal[101] = {0,};
                for(int j = i+1 ; j < K ; j++)
                {
                    if(check[arr[j]] && !sibal[arr[j]] && tn < N)
                    {
                        tn++;
                        out = arr[j];
                        sibal[arr[j]] = true;
                    }
                }
            }
            check[out] = false;
            check[arr[i]] = true;
            cnt[arr[i]]--;
            ans++;
        }
    }
    printf("%d\n",ans);
}