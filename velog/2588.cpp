#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B;

    scanf("%d %d",&A,&B);

    int i,j,k;
    k = B%10;
    j = B%100-k;
    i = B/100;

    printf("%d\n%d\n%d\n%d\n",A*k,A*j/10,A*i,A*B);

}