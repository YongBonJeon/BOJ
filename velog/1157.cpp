#include <bits/stdc++.h>
using namespace std;

int main()
{
    int alpha[26] = {0,};

    string s;

    cin >> s;

    for(auto x : s)
    {
        if(x >= 'a' && x <= 'z')
        {
            alpha[x-'a']++;
        }
        else if(x >= 'A' && x <= 'Z')
        {
            alpha[x-'A']++;
        }
    }
    int max_ = 0, max_idx = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(max_ < alpha[i])
        {
            max_ = alpha[i];
            max_idx = i;
        }
    }
    int t = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(max_ == alpha[i])
            t++;
    }
    if(t >= 2)
        printf("?\n");
    else
        printf("%c\n",'A'+max_idx);
}