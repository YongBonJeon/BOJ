#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string s;
    int alpha[26], f, ans = 0;

    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
        f = 1;
        memset(alpha, 0 ,sizeof(alpha));
        cin >> s;

        for(int i = 0 ; i < s.length() ; i++)
        {
            char cur = s[i];
            
            if(alpha[cur-'a'])
                f = 0;
            while(i+1 < s.length() && cur == s[i+1])
                i++;
            alpha[cur-'a'] = 1;
        }
        if(f)
            ans++;
    }
    printf("%d\n",ans);
}