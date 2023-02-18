#include <bits/stdc++.h>
using namespace std;

// https://www.mathopenref.com/coordpolygonarea2.html

int main()
{
    int N;
    vector<pair<double,double>> coordinate;

    double x,y;
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lf %lf",&x,&y);
        coordinate.push_back({y,x});
    }    

    double sum = 0;
    for(int i = 0 ; i < N ; i++){
        double temp;

        temp = (coordinate[i%N].second + coordinate[(i+1)%N].second)*(coordinate[i%N].first-coordinate[(i+1)%N].first);

        //sum += abs(temp);
        sum += temp;
    }
    printf("%.1lf\n",abs(sum/2.0));
}