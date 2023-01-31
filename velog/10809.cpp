#include <bits/stdc++.h>
using namespace std;

int alpha[26] = {0,};

int main()
{
    string s;

    cin >> s;

    for(int i = 0 ; i < 26 ; i++)
        alpha[i] = -1;

    for(int i = 0 ; i < s.length() ; i++)
    {
        if(alpha[s[i]-'a'] == -1)
            alpha[s[i]-'a'] = i;
    }
    for(int i = 0 ; i < 26 ; i++)
        printf("%d ",alpha[i]);
    printf("\n");
}