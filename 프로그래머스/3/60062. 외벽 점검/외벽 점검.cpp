#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#define T pair<int, vector<int>>
#define X first
#define Y second
using namespace std;
set<int> S;
int ans = 987654321;
T check(int idx, int w, int y, int dir, int n, vector<int> weak, vector<int> dist)
{
    vector<int> v;
    int x = 0;
    while(x <= w)
    {
        if(y>n-1)
            y=0;
        if(y<0)
            y=n-1;
        if(S.count(y))
        {
            v.push_back(y);
            S.erase(y);
            idx+=dir;
        }
        y+=dir;
        x++;
    }
    return {idx, v};
}
void checking(vector<int> v)
{
    for(int i=0;i<v.size();i++)
        S.insert(v[i]);
}
void dfs(int idx, int cnt, int n, vector<int> weak, vector<int> dist)
{
    if(S.empty())
    {
        ans = min(ans, cnt);
        return;
    }
    if(cnt==dist.size())
        return;
    T t = check(idx, dist[cnt], weak[idx], 1, n, weak, dist);
    int nidx = t.X;
    dfs(nidx,cnt+1,n,weak,dist);
    checking(t.Y);
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int s = weak.size();
    for(int i=0;i<s;i++)
        S.insert(weak[i]);
    for(int i=0;i<s;i++)
        weak.push_back(weak[i]);
    for(int i=0;i<s;i++)
        weak.push_back(weak[i]);
    sort(dist.begin(),dist.end());
    do{
        for(int i=s;i<2*s;i++)
            dfs(i,0,n,weak,dist);
    } while (next_permutation(dist.begin(),dist.end()));
    if(ans==987654321)
        return -1;
    else
        return ans;
}