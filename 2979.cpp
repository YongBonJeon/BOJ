/*
1~2 5
2~3 3
3~5 1
5~6 3
6~8 5

5+6+3*2+6+5*2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c, ans=0;
    vector<int> pay(101);

    cin >> a >> b >> c;

    for(int i = 0 ; i < 3 ; i++)
    {
        int l,r;
        cin >> l >> r;
        for(int i = l ; i < r ; i++)
            pay[i]++;
    }

    for(int i = 1 ; i < 101 ; i++)
    {
        if(pay[i] == 1)
            ans += a;
        else if(pay[i] == 2)
            ans += 2*b;
        else if(pay[i] == 3)
            ans += 3*c;
    }
    
    cout << ans << "\n";

    return 0;
}