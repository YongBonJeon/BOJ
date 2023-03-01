#include <bits/stdc++.h>
using namespace std;

/* 1, 3, 6, 10*/
/* 1/n -> n*n-1/2 + 1 번째 */
/* n/1 -> n*n+1/2 번째*/
/*  1   2   4   7   11
    3   5   8   12
    6   9   13
    10  14
    15 
    
    */
/* X = */

int main()
{
    int X,t = 1, pos = 0;;
    int a,b;
    scanf("%d",&X);

    while(t*(t-1)/2 + 1 <= X)
    {
        t++;
    }
    
    a = 1;
    b = --t;


    while((t*(t-1)/2 + 1) + pos != X)
    {
        //printf("%d %d\n",a,b);
        a++;
        b--;
        pos++;
    }
    if(!(t % 2))
        printf("%d/%d\n",a,b);
    else
        printf("%d/%d\n",b,a);

}