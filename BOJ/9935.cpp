#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
    string s, pat, ret;

    cin >> s >> pat;

    for(auto x : s)
    {
        // 1글자씩 붙인다
        ret += x;

        // 폭발 문자열이 발생할 때마다 삭제
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