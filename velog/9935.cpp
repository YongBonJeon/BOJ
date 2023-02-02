#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
    string s, pat, ret;

    cin >> s >> pat;

    for(auto x : s)
    {
        ret += x;

        if(ret.size() >= pat.size() && ret.substr(ret.size()-pat.size(), pat.size()) == pat)
        {
            ret.erase(ret.end() - pat.size(), ret.end());
        }
    }
    if(!ret.empty())
        cout << ret << '\n';
    else
        cout << "FRULA" << '\n'; 
}   