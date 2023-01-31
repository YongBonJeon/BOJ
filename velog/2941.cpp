#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cin >> s;

    int cnt = 0;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == 'c')
        {
            if(i+1 < s.length() && s[i+1] == '=')
            {
                cnt++;
                i++;
            }
            else if(i+1 < s.length() && s[i+1] == '-')
            {
                cnt++;
                i++;
            }
            else
                cnt++;
        }
        else if(s[i] == 'd')
        {
            if(i+2 < s.length() && s[i+1] == 'z' && s[i+2] == '=')
            {
                cnt++;
                i += 2;
            }
            else if(i+1 < s.length() && s[i+1] == '-')
            {
                cnt++;
                i++;
            }
            else
                cnt++;
        }
        else if(s[i] == 'l')
        {
            if(i+1 < s.length() && s[i+1] == 'j')
            {
                cnt++;
                i++;
            }
            else
                cnt++;
        }
        else if(s[i] == 'n')
        {
            if(i+1 < s.length() && s[i+1] == 'j')
            {
                cnt++;
                i++;
            }
            else
                cnt++;
        }
        else if(s[i] == 's' || s[i] == 'z')
        {
            if(i+1 < s.length() && s[i+1] == '=')
            {
                cnt++;
                i++;
            }
            else
                cnt++;
        }
        else
            cnt++;
    }
    printf("%d\n",cnt);
}