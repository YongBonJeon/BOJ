#include <bits/stdc++.h>
using namespace std;

// Optimal paging algorithm
int main()
{
    int N,K,num = 0,ans = 0;
    int arr[101], cnt[101] = {0,};
    bool check[101] = {0,};

    scanf("%d %d",&N, &K);
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d",&arr[i]);
        
        // 각 전자기기별 사용 횟수
        cnt[arr[i]]++;
    }

    for(int i = 0 ; i < K ; i++)
    {
        // 플러그 여분이 남아있으면서 새로운 전자기기
        if(num < N && !check[arr[i]])
        {
            check[arr[i]] = true;   // 플러그 ON
            cnt[arr[i]]--;
            num++;
        }
        // 현재 사용중인 전자기기
        else if(check[arr[i]])
        {
            cnt[arr[i]]--;
        }
        // 플러그 여분이 남아있지 않으면서 새로운 전자기기
        else if(num == N && !check[arr[i]])
        {
            int out = -1, tn = 0;
            for(int j = 0 ; j < K ; j++)
            {
                // Optimal paging algorithm에 맞게 뽑을 플러그
                // 꽂혀 있는 플러그 중 앞으로 사용되지 않을 플러그 우선으로 뽑는다
                if(check[arr[j]] && cnt[arr[j]] == 0)
                {
                    out = arr[j];
                    break;
                }
            }
            // 꽂혀 있는 플래그 중 모두 사용 되는 경우
            if(out == -1){
                bool temp[101] = {0,};
                // 아직 사용안된 플러그 순회
                for(int j = i+1 ; j < K ; j++)
                {
                    // 꽂혀 있는 플래그 중 가장 늦게 사용되는 플래그를  뽑는다
                    if(check[arr[j]] && !temp[arr[j]] && tn < N)
                    {
                        tn++;
                        out = arr[j];
                        temp[arr[j]] = true;
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