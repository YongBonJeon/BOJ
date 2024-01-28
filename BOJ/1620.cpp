#include <bits/stdc++.h>
using namespace std;

/*
    string -> Int = map
    Int -> string = array
*/

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    map<string,int> m1;
    map<int,string> m2;
    string m3[100004];

    cin >> N >> M;

    for(int i = 0 ; i < N ; i++)
    {
        string tmp;
        cin >> tmp;
        m1[tmp] = i+1;
        m2[i+1] = tmp;
        m3[i+1] = tmp;
    }

    for(int i = 0 ; i < M ; i++)
    {
        string tmp;
        cin >> tmp;

        if(atoi(tmp.c_str()) == 0)
            cout << m1[tmp] << "\n";
        else
            cout << m3[atoi(tmp.c_str())] << "\n";
            //cout << m2[atoi(tmp.c_str())] << "\n"; 

    }
    
}