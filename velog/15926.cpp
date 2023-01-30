#include<bits/stdc++.h>
using namespace std;

int N;
string input;
stack<int> s;
int check[200001];

int main()
{
    cin >> N >> input;

    for(int i = 0 ; i < N ; i++)
    {
        if(input[i] == '(')
        {
            s.push(i);
        }
        else if(input[i] == ')')
        {
            if(s.empty())
            {
                continue;
            }
            check[i] = check[s.top()] = 1;
            s.pop();
        }
    }

    int local = 0, global = 0;
    for(int i = 0 ; i < N ; i++)
    {
        //printf("%d ",check[i]);
        if(check[i])
            local++;
        else
        {
            global = max(global, local);
            local = 0;
        }
    }
    global = max(global, local);

    printf("%d\n",global);
}