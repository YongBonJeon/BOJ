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
/*while(1)
    {
        printf("%d\n",atoi(input.c_str()));

    }

    if(atoi(input.c_str())){
        printf("?");
        digit.push_back(atoi(input.c_str()));
        return ;
    }*/

    for(int i = 0 ; i < (int)input.size() ; i++)
    {
        //printf("%d %d %d\n",flag, st, i);
        if(is_alphabet(input[i]))
        {
            if(flag){
                //printf("c %d %d\n",st,i);
                //cout << input.substr(st,i-st) << '\n';
                temp =input.substr(st, i-st);
                digit.push_back(temp);
                //st = i;
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
        //printf("c %d %d\n",st,i);
        //cout << input.substr(st) << '\n';
        temp = input.substr(st);
        digit.push_back(temp);
    }
}

bool compare(string a, string b)
{
    int lenA = a.length();
    int lenB = b.length();

    if(lenA < lenB)
        return true;
    else if(lenA > lenB)
        return false;
    else{
        if(a.compare(b) < 0)
            return true;
        else
            return false;
    }
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