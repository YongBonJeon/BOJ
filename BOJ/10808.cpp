#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    vector<int> ans(26);

    cin >> input;

    for(char c : input)
    {
        ans[c-'a']++;
    }

    for(int i = 0 ; i < 26 ; i++)
        printf("%d ",ans[i]);
    printf("\n");
}