#include <bits/stdc++.h>
using namespace std;

int order;
int m,n;

int A[1001];
int B[1001];

int sum_A[1001][1001];
int sum_B[1001][1001];

int main()
{
    scanf("%d",&order);
    scanf("%d %d",&m,&n);
    int t;
    for(int i = 0 ; i < m ; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&B[i]);
    }

    for(int i = 0 ; i < m ; i++){
        int sum = 0;
        for(int j = 0 ; j < m ; j++){
            sum += A[(i+j)%m];
            sum_A[i][j] = sum;
        }
    }
    for(int i = 1 ; i < m ; i++)
        sum_A[i][m-1] = 0;
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < n ; j++){
            sum += B[(i+j)%n];
            sum_B[i][j] = sum;
        }
    }
    for(int i = 1 ; i < n ; i++)
        sum_B[i][n-1] = 0;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ",sum_A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d ",sum_B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int ans = 0;
    int need;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            need = order - sum_A[i][j];
            if(need == 0)
                ans++;
            if(need <= 0)
                break;

            for(int k = 0 ; k < n ; k++){
                if(binary_search(sum_B[k],sum_B[k]+n,need)){
                    ans++;
                }
            }

        }
    }
    printf("%d\n",ans);

}