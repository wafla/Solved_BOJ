#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> A, B;
    for(int i=0;i<participant.size();i++)
        A[participant[i]]++;
    for(int i=0;i<completion.size();i++)
        B[completion[i]]++;
    for(int i=0;i<participant.size();i++)
    {
        if(A[participant[i]] == B[participant[i]])
            continue;
        else
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}