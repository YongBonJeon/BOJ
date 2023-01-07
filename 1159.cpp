#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    vector<string> input;
    vector<int> num(26);

    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        string tmp;
        cin >> tmp;
        input.push_back(tmp);
        num[tmp[0]-'a']++;
    }
    
    int success = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(num[i] >= 5)
        {
            printf("%c",'a'+i);
            success++;
        }
    }
    if(!success)
        printf("PREDAJA\n");
    else
        printf("\n");
}