#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int data[26] = {0,};
    
    string s;
    for(int i = 0 ; i < survey.size() ; i++){
        s = survey[i];
        if(choices[i] > 4){
            data[s[1]-'A'] += choices[i]%4;
        }
        else if(choices[i] < 4){
            data[s[0]-'A'] += 4 - choices[i]%4;
        }
    }
    if(data['R'-'A'] >= data['T'-'A'])
        answer += "R";
    else
        answer += "T";
    if(data['C'-'A'] >= data['F'-'A'])
        answer += "C";
    else
        answer += "F";
    if(data['J'-'A'] >= data['M'-'A'])
        answer += "J";
    else
        answer += "M";
    if(data['A'-'A'] >= data['N'-'A'])
        answer += "A";
    else
        answer += "N";
    return answer;
}