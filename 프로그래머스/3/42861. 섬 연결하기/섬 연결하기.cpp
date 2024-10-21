#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define pi pair<int,int>
#define X first
#define Y second
#define T pair<int,pi>
int parent[101]={0};
int cnt = 1;
int find(int x)
{
    if(x == parent[x])
        return x;
    return parent[x]=find(parent[x]);
}
void merge(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if(px < py)
        parent[py] = px;
    else
        parent[px]=py;
    cnt++;
}
using namespace std;
int solution(int n, vector<vector<int>> costs) {
    priority_queue<T, vector<T>, greater<T>> PQ;
    for(int i=0;i<costs.size();i++)
    {
        int x = costs[i][0];
        int y = costs[i][1];
        int w = costs[i][2];
        PQ.push({w,{x,y}});
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        parent[i]=i;
    while(PQ.size() && cnt < n)
    {
        auto cur = PQ.top();
        PQ.pop();
        if(find(cur.Y.X) == find(cur.Y.Y))
            continue;
        merge(cur.Y.X, cur.Y.Y);
        ans+=cur.X;
    }
    return ans;
}