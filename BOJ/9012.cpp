#include <bits/stdc++.h>
using namespace std;

bool solve(string input)
{
    stack<char> s;
    
    for(char x : input)
    {
        if(x == '(')
            s.push(x);
        if(x == ')')
        {
            if(s.empty())
                return false;
            if(s.top() == '(')
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    int num_TC;
    string input;

    cin >> num_TC;

    for(int i = 0 ; i < num_TC ; i++)
    {
        cin >> input;

        if(solve(input))
            printf("YES\n");
        else
            printf("NO\n");
    }
}