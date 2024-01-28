#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;

    cin >> input;

    int l,r;
    l = 0;
    r = input.length()-1;

    while(l<r)
    {
        if(input[l] != input[r])
        {
            printf("0\n");
            return 0;
        }
        l++;
        r--;
    }
    printf("1\n");

    return 0;
}