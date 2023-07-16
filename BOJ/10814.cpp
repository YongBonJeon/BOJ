#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    int N;

    string s;

    vector<pair<int, string>> person;

    int age;

    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        cin >> age >> s;
        person.push_back({age, s});
       
    }

    stable_sort(person.begin(),person.end(),compare);

    for(auto x : person){
        cout << x.first << " " << x.second << '\n';
    }
    

}