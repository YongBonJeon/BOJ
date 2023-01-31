#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A,B;

    cin >> A >> B;

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    if(A.compare(B) < 0)
        cout << B << '\n';
    else if(A.compare(B) > 0)
        cout << A << '\n';
}