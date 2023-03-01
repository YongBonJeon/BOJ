#include <bits/stdc++.h>
using namespace std;

int T,N;

deque<int> deq;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> T;

    for(int i = 0 ; i < T; i++)
    {
        string cmd;
        string arr;
        cin >> cmd >> N >> arr;

        arr = arr.substr(1,arr.length()-1);
        int pos; string token;
        deq.clear();
        while(N != 0 && (pos = arr.find(",")) != string::npos)
        {
            token = arr.substr(0,pos);
            deq.push_back(stoi(token));
            arr.erase(0,pos+1);
        }
        if(N != 0){
            deq.push_back(stoi(arr));
        }

        bool error = 0, reverse = 0;
        for(auto x : cmd)
        {
            if(x == 'R')
            {
                reverse = !reverse;
            }
            else if(x == 'D')
            {
                if(deq.empty()){
                    error = 1;
                    break;
                }
                else if(reverse){
                    deq.pop_back();
                    N--;
                }
                else if(!reverse){
                    deq.pop_front();
                    N--;
                }
            }
        }
        if(error)
            cout << "error" << "\n";
        else if(!error && !deq.empty())
        {
            if(reverse)
            {
                cout << "[";
                for (auto o = deq.rbegin(); o != deq.rend(); o++) {
                    if (o == deq.rend() - 1)
                        cout << *o;
                    else
                    cout << *o << ',';
            }
                cout <<"]" <<"\n";
            }
            else
            {
                cout << "[";
            for (auto o = deq.begin(); o != deq.end(); o++) {
                if (o == deq.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
                cout <<"]" <<"\n";
            }

        }
        else if(!error && deq.empty())
            cout <<"[]" << "\n";
    }
}