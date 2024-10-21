#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0;
    int idx2 = 0;
    int goal_idx = 0;
    string s ="";
    int flag = 0;
    while(goal_idx < goal.size())
    {
        if(goal[goal_idx]==cards1[idx1])
        {
            idx1++;
            goal_idx++;
        }
        else if(goal[goal_idx]==cards2[idx2])
        {
            idx2++;
            goal_idx++;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        return "No";
    else
        return "Yes";
}