#include <bits/stdc++.h>
using namespace std;

string A;
string B;
char C[10050];

void add(int i, int adder)
{
    int temp;
    if(i >= A.length() && i >= B.length()){
        if(adder)
            C[i] = adder + '0';
        return ;
    }
    else if(i >= A.length()){
        temp = B[i] - '0' + adder;
        if(temp >= 10){
            adder = 1;
            temp -= 10;
        }
        else
            adder = 0;
    }
    else if(i >= B.length()){
        temp = A[i] - '0' + adder;
        if(temp >= 10){
            adder = 1;
            temp -= 10;
        }
        else
            adder = 0;
    }
    else{
        temp = A[i]-'0' + B[i]-'0' + adder;

        if(temp >= 10){
            adder = 1;
            temp -= 10;
        }
        else
            adder = 0;
    }
    C[i] = temp + '0';
    add(i+1,adder);

}

int main()
{
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    add(0,0);

    for(int i = 1 ; i <= strlen(C) ; i++)
    {
        printf("%c",C[strlen(C)-i]);
    }
    printf("\n");
}