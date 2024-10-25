#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define pi pair<int,int>
#define T pair<pi, int> // 좌표, 노드 번호
using namespace std;
vector<vector<int>> answer(2);
vector<T> v;
void solve(int left, int right)
{
    if(left>right)
        return;
    T top_node = {{-1,-1},-1};
    int idx = 0;
    for(int i=left;i<=right;i++)
    {
        if(top_node.X.Y < v[i].X.Y)
        {
            top_node = {{v[i].X.X,v[i].X.Y},v[i].Y};
            idx = i;
        }
    }
    answer[0].push_back(top_node.Y);
    solve(left, idx-1);
    solve(idx+1,right);
    answer[1].push_back(top_node.Y);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i=0;i<nodeinfo.size();i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        v.push_back({{x,y},i+1});   
    }
    sort(v.begin(),v.end());
    solve(0, v.size()-1);
    return answer;
}