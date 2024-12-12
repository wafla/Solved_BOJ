#include <string>
#include <vector>

using namespace std;
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp = triangle;
    for(int i=1;i<dp.size();i++)
    {
        for(int j=0;j<dp[i].size();j++)
        {
            if(j==0)
            {
                dp[i][j] += dp[i-1][j];
            }
            else if(j==dp[i].size()-1)
            {
                dp[i][j] += dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + dp[i][j];
            }
        }
    }
    for(int i=0;i<dp[dp.size()-1].size();i++)
        answer = max(answer, dp[dp.size()-1][i]);
    return answer;
}