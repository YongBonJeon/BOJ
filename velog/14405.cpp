#include <bits/stdc++.h>
using namespace std;

string ex[3] = 
    { 
        "pi",
        "ka",
        "chu"
    };
string s;
int N;
bool success = 0;

void make(string x)
{
    //cout << x << '\n';
    if(x.length() >= N)
    {
        if(!x.compare(s)){
            success = 1;
        }
        return ;
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        if(s[x.length()] == ex[i][0])
            make(x+ex[i]);
    }
}

int main()
{
    cin >> s;

    N = s.length();

    string temp;
    make(temp);

    if(success)
        printf("YES\n");
    else
        printf("NO\n");

}