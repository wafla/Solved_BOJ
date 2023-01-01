#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
vector<vector<int>> vt;
vector<vector<int>> rvt;
vector<vector<int>> ans;
stack<int> S;
bool visit[5001] = { 0 };
int r = 0;
void dfs(int idx)
{
	visit[idx] = 1;
	for (int i = 0; i < vt[idx].size(); i++)
		if (!visit[vt[idx][i]])
			dfs(vt[idx][i]);
	S.push(idx);
}
void dfs_r(int idx, int x)
{
	visit[idx] = 1;
	ans[x].push_back(idx);
	for (int i = 0; i < rvt[idx].size(); i++)
		if (!visit[rvt[idx][i]])
			dfs_r(rvt[idx][i], x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int d, l;
	cin >> d >> l;
	vt.resize(d + 1);
	rvt.resize(d + 1);
	for (int i = 0; i < l; i++)
	{
		int x, y;
		cin >> x >> y;
		vt[x].push_back(y);
		rvt[y].push_back(x);
	}
	for (int i = 1; i <= d; i++)
		if (!visit[i])
			dfs(i);
	memset(visit, 0, sizeof(visit));
	while (S.size())
	{
		int idx = S.top();
		S.pop(); 
		if (visit[idx])
			continue;
		ans.resize(++r);
		dfs_r(idx, r - 1);
	}
	int maxx = 0;
	for (int i = 0; i < r; i++)
		if (maxx < ans[i].size())
			maxx = ans[i].size();
	cout << maxx << '\n';
}