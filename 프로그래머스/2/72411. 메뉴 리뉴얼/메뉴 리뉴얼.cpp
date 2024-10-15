#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<string, int> cnt;
map<string, int> ans;
set<string> S;
vector<bool> visited(10);
void dfs(int idx, string tmp, string order)
{
    S.insert(tmp);
    if(cnt[tmp]==0)
    {
        cnt[tmp]=1;
        ans[tmp]++;
    }
    for(int i=idx+1;i<order.size();i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            tmp+=order[i];
            dfs(i, tmp, order);
            tmp.pop_back();
            visited[i]=false;
        }
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++)
    {
        cnt.clear();
        sort(orders[i].begin(),orders[i].end());
        for(int j=0;j<orders[i].size();j++)
        {
            visited[0]=true;
            string tmp = "";
            tmp+=orders[i][j];
            dfs(j, tmp, orders[i]);
            visited[0]=false;
        }
    }
    vector<string> tmp;
    for(int i=0;i<course.size();i++)
    {
        int maxx = 0;
        tmp.clear();
        for(auto j : S)
        {
            if(j.size()==course[i] && ans[j] > 1)
            {
                if(ans[j] > maxx)
                {
                    maxx = ans[j];
                    tmp.clear();
                    tmp.push_back(j);
                }
                else if(ans[j] == maxx)
                    tmp.push_back(j);
            }
        }
        for(int j=0;j<tmp.size();j++)
            answer.push_back(tmp[j]);
    }
    sort(answer.begin(), answer.end());
    return answer;
}