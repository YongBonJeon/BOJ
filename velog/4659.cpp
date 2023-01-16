#include <bits/stdc++.h>
using namespace std;

int check0(char a)
{
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return 1;
    return 0;
}

int check1(string input)
{
    for(char a : input)
        if(check0(a))
            return 1;
    return 0;
}

int check2(string input)
{
    for(int i = 0 ; i < (int)(input.size())-2 ; i++)
    {
        if(check0(input[i]) == 0 && check0(input[i+1]) == 0 && check0(input[i+2]) == 0)
            return 0;
        if(check0(input[i]) == 1 && check0(input[i+1]) == 1 && check0(input[i+2]) == 1)
            return 0;
    }
    return 1;
}

int check3(string input)
{
    for(int i = 0 ; i < (int)(input.size())-1 ; i++)
    {
        if(input[i] == input[i+1]){
            if(input[i] == 'e' || input[i] == 'o')
                continue;
            return 0;
        }
    }
    return 1;
}

int main()
{
    string input;

    while(1)
    {
        cin >> input;

        if(input.compare("end") == 0)
            break;

        if(check1(input) == 0){
            printf("<%s> is not acceptable.\n",input.c_str());
            continue;
        }
        if(check2(input) == 0){
            printf("<%s> is not acceptable.\n",input.c_str());
            continue;
        }
        if(check3(input) == 0){
            printf("<%s> is not acceptable.\n",input.c_str());
            continue;
        }
        printf("<%s> is acceptable.\n",input.c_str());
    }
}