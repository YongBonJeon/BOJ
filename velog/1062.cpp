#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<string> input;
int alpha[26];
int max_ = 0;

void study(int st, int num)
{
    if(num == K-5)
    {
        int ans = 0, success = 1;
        for(auto x : input)
        {
            success = 1;
            for(int i = 0 ; i < x.length() ; i++)
            {
                if(!alpha[x[i]-'a']){
                    success = 0;
                }
            }
            if(success){
                ans++;
            }
        }
        max_ = max(max_, ans);
    }

    for(int i = st ; i < 26 ; i++)
    {
        if(alpha[i])
            continue;
        
        alpha[i] = 1;
        study(i+1, num+1);
        alpha[i] = 0;
    }
}

int main()
{
    cin >> N >> K;

    string temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        int len = temp.length();
        temp = temp.substr(4,len-8);
        input.push_back(temp);
    }
    alpha['a'-'a'] = 1;
    alpha['n'-'a'] = 1;
    alpha['t'-'a'] = 1;
    alpha['i'-'a'] = 1;
    alpha['c'-'a'] = 1;

    study(0,0);
    printf("%d\n",max_);
}