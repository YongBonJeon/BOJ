#include <bits/stdc++.h>
using namespace std;

vector<int> input;

void combination(int start, vector<int> v)
{
    if(v.size() == 7)
    {
        if(accumulate(v.begin(),v.end(),0) == 100)
        {
            for(int i = 0 ; i < 7 ; i++)
                printf("%d\n",v[i]);
            exit(0);
        }
    }

    for(int i = start+1 ; i < 9 ; i++)
    {
        v.push_back(input[i]);
        combination(i, v);
        v.pop_back();
    }
}

int main()
{
    vector<int> v;
    for(int i = 0 ; i < 9 ; i++){
        int tmp;
        scanf("%d",&tmp);
        input.push_back(tmp);
    }
    
    sort(input.begin(), input.end());

    combination(-1,v);
}