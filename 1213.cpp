#include<bits/stdc++.h>
using namespace std;

/* 순열 이용해봅시다 - 실패 */
/*
int main()
{
    string input;
    int success = 0;
    cin >> input;
    sort(input.begin(),input.end());

    do
    {
        string tmp = input;
        reverse(tmp.begin(),tmp.end());
        if(input.compare(tmp) == 0){
            cout << input << '\n';
            success++;
            break;
        }
    } while (next_permutation(input.begin(),input.end()));
    
    if(!success)
        cout << "I'm Sorry Hansoo\n"; 
}
*/

int main()
{
    string input;
    cin >> input;
    vector<int> mono(26,0);

    for(int i = 0 ; i < input.length() ; i++)
    {
        mono[input[i]-'A']++;
    }
    int check = 0;

    for(int i = 0 ; i < 26 ; i++)
    {
        if(mono[i]%2 == 1)
            check++;
    }
    if(check > 1){
        printf("I'm Sorry Hansoo\n");
        return 0;
    }

    vector<int> ans(input.length());
    int idx = 0;
    int last;
    for(int i = 0 ; i < 26 ; i++)
    {
        //printf("%d\n",mono[i]);
        if(mono[i]%2 == 1)
            last = i;
        for(int j = 0 ; j < mono[i]/2 ; j++)
        {
            ans[idx++] = i;
            ans[ans.size()-idx] = i;
            //cout << idx << " "<< ans.size()-idx << "\n";
        }
    }
    if(check == 1)
        ans[idx] = last;

    for(int i = 0 ; i < input.length() ; i++)
        printf("%c",'A'+ans[i]);
    printf("\n");


}