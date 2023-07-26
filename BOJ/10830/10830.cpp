#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,B;

void mul_mat(ll A[5][5], ll B[5][5]){
    ll C[5][5];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            int temp = 0;
            for(int k = 0 ; k < N ; k++){
                temp += A[i][k]*B[k][j];
            }
            C[i][j] = temp%1000;
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            A[i][j] = C[i][j];
        }
    }
}

int main(){
    scanf("%lld %lld",&N,&B);

    ll mat[5][5];
    ll ans[5][5];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%lld",&mat[i][j]);
            ans[i][j] = 0;
        }
        ans[i][i] = 1;
    }

    while(B){
        if(B % 2 == 1){
            mul_mat(ans, mat);
        }
        mul_mat(mat,mat);
        B /= 2;
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }

}