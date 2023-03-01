#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    priority_queue<double, vector<double>, greater<double>> pq;
    double input;
    
    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> input;

        pq.push(input);
    }

    cout << fixed;
    cout.precision(3);
    for(int i = 0 ; i < 7 ; i++)
    {
        cout << pq.top() << '\n';
        pq.pop();
    }
}