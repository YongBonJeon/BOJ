#include <bits/stdc++.h>
using namespace std;

int N;
char ineql[11];
vector<int> ans;
bool first = 0;
char min_[11];
char max_[11];

void go(int idx)
{
    if(ans.size() == N+1)
    {
        char temp[11];
        int i;
        for(i = 0 ; i < ans.size() ; i++){
            temp[i] = ans[i] +'0';
        }
        temp[i] = '\0';
        
        if(!first)
        {
            strcpy(min_, temp);
            first = 1;
        }
        strcpy(max_, temp);
    
        return ;
    }

    if(ans.size() == 0)
    {
        for(int i = 0 ; i <= 9 ; i++)
        {
            ans.push_back(i);
            go(idx+1);
            ans.pop_back();
        }
        return ;
    }

    for(int i = 0 ; i <= 9 ; i++)
    {
        if(find(ans.begin(), ans.end(), i) == ans.end())
        {
            if(ineql[idx] == '<')
            {
                if(ans.back() < i){
                    ans.push_back(i);
                    go(idx+1);
                    ans.pop_back();
                }
            }
            else if(ineql[idx] == '>')
            {
                if(ans.back() > i){
                    ans.push_back(i);
                    go(idx+1);
                    ans.pop_back();
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf(" %c",&ineql[i]);

    go(-1);

    printf("%s\n%s\n",max_,min_);

}