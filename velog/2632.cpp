#include <bits/stdc++.h>
using namespace std;

int order;
int m,n;

int A[1001];
int B[1001];

int sum_A[1000001] = {0,};
int sum_B[1000001] = {0,};

int main()
{
    scanf("%d",&order);
    scanf("%d %d",&m,&n);
    int sum = 0;
    for(int i = 0 ; i < m ; i++){
        scanf("%d",&A[i]);
        sum += A[i];
    }
    sum_A[sum]++;
    sum = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&B[i]);
        sum += B[i];
    }
    sum_B[sum]++;

    for(int i = 0 ; i < m ; i++){
        int sum = 0;
        for(int j = 0 ; j < m-1 ; j++){
            sum += A[(i+j)%m];
            sum_A[sum]++;
        }
    }
    sum_A[0]++;

    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < n-1 ; j++){
            sum += B[(i+j)%n];
            sum_B[sum]++;
        }
    }
    sum_B[0]++;

    /*for(int i = 0 ; i <= order ; i++){
        printf("%d %d \n",i,sum_A[i]);
    }
    printf("\n");

    for(int i = 0 ; i <= order ; i++){
        printf("%d %d \n",i,sum_B[i]);
    }
    printf("\n");*/
    int ans = 0;
    for(int i = 0 ; i <= order ; i++){
        ans += sum_A[i]*sum_B[order-i];
    }
    printf("%d\n",ans);


}