#include <bits/stdc++.h>
using namespace std;

int N;
int score[3]={0,};
pair<int, int> win_time[3];

int main()
{
    cin >> N;
    
    int team;
    string time;

    int minute=0;
    int second=0;
    int last_minute = 0;
    int last_second = 0;
    int win1 = 0;
    int win2 = 0;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> team;
        cin >> time;
        
        int pos = time.find(":");
        minute = stoi(time.substr(0,pos));
        second = stoi(time.substr(pos+1));

        //printf("%d %d\n",minute, second);

        score[team]++;

        if(score[1] > score[2])
        {
            if(win1)
            {
                win_time[1].first += (minute-last_minute);
                win_time[1].second += (second-last_second);
            }
            win1 = 1;
        }
        else if(score[1] < score[2]){
            if(win2)
            {
                win_time[2].first += (minute-last_minute);
                win_time[2].second += (second-last_second);
            }
            win2 = 1;
        }
        else{
            if(win1)
            {
                win_time[1].first += (minute-last_minute);
                win_time[1].second += (second-last_second);
            }
            if(win2)
            {
                win_time[2].first += (minute-last_minute);
                win_time[2].second += (second-last_second);
            }
            win1 = 0;
            win2 = 0;
        }
        last_minute = minute;
        last_second = second;

        //printf("%d %d %d %d\n",win_time[1].first,win_time[1].second,win_time[2].first, win_time[2].second);
    }
    if(win1)
    {          
        win_time[1].first += (48-last_minute);          
        win_time[1].second += (0-last_second);  
    }
    if(win2)
    {
        win_time[2].first += (48-last_minute);
        win_time[2].second += (0-last_second);
    }

    if(win_time[1].second < 0)
    {
        while(win_time[1].second < 0)
        {
            win_time[1].second += 60;
            win_time[1].first-=1;
        }  
    }
    if(win_time[2].second < 0)
    {
        while(win_time[2].second < 0)
        {
            win_time[2].second += 60;
            win_time[2].first-=1;
        }  
    }
    if(win_time[1].second >= 60)
    {
        while(win_time[1].second >= 60)
        {
            win_time[1].second -= 60;
            win_time[1].first+=1;
        }  
    }
    if(win_time[2].second >= 60)
    {
        while(win_time[2].second >= 60)
        {
            win_time[2].second -= 60;
            win_time[2].first+=1;
        }  
    }
    printf("%02d:%02d\n%02d:%02d\n",win_time[1].first,win_time[1].second,win_time[2].first, win_time[2].second);
}