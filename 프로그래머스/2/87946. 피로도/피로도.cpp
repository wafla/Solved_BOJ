#include <string>
#include <vector>
using namespace std;
bool visited[9]={0};
vector<vector<int>> v;
int ans = 0;
void dfs(int k, int idx, int cnt)
{
    if(k<0)
        return;
    ans = max(ans, cnt);
    for(int i=0;i<v.size();i++)
    {
        int a = v[i][0];
        int b = v[i][1];
        if(k >= a && !visited[i])
        {
            visited[i]=true;
            dfs(k-b,i,cnt+1);
            visited[i]=false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;
    dfs(k,-1,0);
    return ans;
}