#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;

    getline(cin,input);

    for(char& a : input)
    {
        int idx;
        if(a >= 'a' && a <= 'z')
        {
            idx = a - 'a';
            idx = (idx+13)%26;
            a = 'a'+idx;
        }
        else if(a >= 'A' && a <= 'Z')
        {
            idx = a - 'A';
            idx = (idx+13)%26;
            a = 'A'+idx;
        }
    }
    cout << input << '\n';
}