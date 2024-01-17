#include<bits/stdc++.h>
using namespace std;

int N;

int is_alphabet(char x)
{
    if(x >= 'a' && x <= 'z')
        return 1;
    return 0;
}

void split_digit(string input, vector<string> &digit)
{
    string temp;
    int flag = 0;
    int st = 0;

    for(int i = 0 ; i < (int)input.size() ; i++)
    {
        if(is_alphabet(input[i]))
        {
            if(flag){
                temp = input.substr(st, i-st);
                digit.push_back(temp);
                flag = 0;
            }
        }
        else
        {
            if(!flag){
                st = i;
                flag = 1;
            }
        }
    }
    if(flag){
        temp = input.substr(st);
        digit.push_back(temp);
    }
}

bool compare(string a, string b)
{
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    string input;

    vector<string> digit;

    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> input;

        split_digit(input, digit);
    }

    /* 앞 0 삭제  (ex. 00080)*/
    for(string &a : digit)
    {
        int st = 1;
        if(a[0] == '0')
        {
            while(a[st] == '0')
            {
                st++;
            }
            if(st == a.end()-a.begin())
                st -= 1;
            a = a.substr(st);
        }
    }

    sort(digit.begin(), digit.end(), compare);
    for(string a : digit)
        printf("%s\n",a.c_str());
}