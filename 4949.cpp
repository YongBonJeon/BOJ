#include <bits/stdc++.h>
using namespace std;

bool solve(string input)
{
    stack<char> s;

    for(char x : input)
    {
        if(x == '(')
            s.push(x);
        else if(x == ')')
        {
            if(s.empty())
                return false;
            if(s.top() == '(')
                s.pop();
            else
                return false;
        }

        if(x == '[')
            s.push(x);
        else if(x == ']')
        {
            if(s.empty())
                return false;
            if(s.top() == '[')
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
    string input;

    while(1)
    {
        getline(cin, input);
        if(!input.compare("."))
            break;

        //cout << input;

        if(solve(input))
            printf("yes\n");
        else
            printf("no\n");
    }
}