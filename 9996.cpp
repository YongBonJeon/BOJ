#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string pattern;
    vector<string> input;

    cin >> N >> pattern;
    int p_len = pattern.size();

    for(int i = 0 ; i < N ; i++)
    {
        string copy = pattern;
        string tmp;
        cin >> tmp;
        int t_len = tmp.size();
        int diff = t_len-p_len;

        int pos = copy.find('*');
        for(int i = 0 ; i < diff ; i++)
            copy.insert(pos, "*");

        int l = 0, r = tmp.size()-1;
        int success = 0;
        //cout << copy << tmp <<"\n";
        if(diff == -1)
        {
            tmp.insert(pos, "*");
            if(copy.compare(tmp) == 0)
                success++;
        }
        else if(diff < -1){
            success = 0;
        }
        else{
            while(l<=r)
            {
                //printf("%d %d %c %c %c %c\n",l,r,copy[l], tmp[l], copy[r], tmp[r]);
                if(copy[l] == '*' && copy[r] == '*'){
                    success++;
                    break;
                }
                if(copy[l] == tmp[l])
                    l++;
                else
                {
                    if(copy[l] != '*')
                        break;  
                }

                if(copy[r] == tmp[r])
                    r--;
                else
                {
                    if(copy[r] != '*')
                        break;  
                }
            }   
        }

        if(success)
            printf("DA\n");
        else
            printf("NE\n");
        //cout << copy;
    }
}