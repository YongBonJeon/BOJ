#include<bits/stdc++.h>
using namespace std;

map<int, int> ans;
vector<int> input;

int solve(int n)
{
    int num_5 = 0;

    for(int i = n ; i >= 2 ; i--)
    {
        int temp = i;
        /*while(temp % 2 == 0)
        {
            num_2++;
            temp = temp/2;
        }*/

        while(temp % 5 == 0)
        {
            num_5++;
            temp = temp/5;
        }
    }
    return num_5;
}

int main()
{
    int num_TC;

    scanf("%d",&num_TC);

    for(int i = 0 ; i < num_TC ; i++)
    {
        int N;

        scanf("%d",&N);

        //input.push_back(N);
        printf("%d\n",solve(N));
    }
}