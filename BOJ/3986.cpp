#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,cnt=0;
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++)
    {
        string input;
        stack<int> s;

        cin >> input;
        
        for(int j = 0 ; j < input.length() ; j++)
        {
            if(s.empty())
            {
                s.push(input[j]);
                continue;
            }
            if(s.top() == input[j])
            {
                s.pop();
            }
            else
                s.push(input[j]);
        }

        if(s.empty())
            cnt++;
    }
    printf("%d\n",cnt);
}