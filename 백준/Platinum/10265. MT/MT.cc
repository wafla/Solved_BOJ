#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
vector<int> adj;
vector<vector<int>> r_adj;
vector<vector<int>> cycle;
vector<int> visited;
vector<bool> is_cycle;
vector<pi> max_cycle;
stack<int> st;
int order = 1;
int dp[1001][1001] = { 0 };
int cnt = 0;
int FindSCC(int idx)
{
	int min_order = visited[idx] = order++;
	st.push(idx);

	int next_idx = adj[idx];
	if (visited[next_idx] == -1)
		min_order = min(min_order, FindSCC(next_idx));
	else if (!is_cycle[next_idx])
		min_order = min(min_order, visited[next_idx]);

	if (min_order == visited[idx])
	{
		vector<int> tmp;
		while (!st.empty())
		{
			int num = st.top();
			st.pop();
			is_cycle[num] = 1;
			tmp.push_back(num);
			if (num == idx)
				break;
		}
		if (tmp.size() == 1 && adj[idx] != idx)
			is_cycle[idx] = 0;
		else
			cycle.push_back(tmp);
	}
	return min_order;
}
int makeSCC(int idx)
{
	if (visited[idx] != -1)
		return 0;
	visited[idx] = 1;
	if (!is_cycle[idx])
	{
		is_cycle[idx] = 1;
		cnt++;
	}
	for(int i=0;i<r_adj[idx].size();i++)
		makeSCC(r_adj[idx][i]);
	return 0;
}
int solve(int idx, int w)
{
	if (idx >= cycle.size())
		return 0;

	int& ret = dp[idx][w];
	if (ret != -1)
		return ret;

	ret = max(ret, solve(idx + 1, w));
	for (int i = max_cycle[idx].X; i <= max_cycle[idx].Y; i++)
	{
		if (w - i < 0)
			break;
		ret = max(ret, solve(idx + 1, w - i) + i);
	}
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	adj.resize(n + 1);
	r_adj.resize(n + 1);
	is_cycle.resize(n + 1, false);
	visited.resize(n + 1, -1);

	for (int i = 1; i <= n; i++)
	{
		cin >> adj[i];
		r_adj[adj[i]].push_back(i);
	}


	for (int idx = 1; idx <= n; idx++)
		if (visited[idx] == -1)
			FindSCC(idx);

	for (int i = 0; i <= n; i++)
		visited[i] = -1;

	max_cycle.resize(cycle.size());
	for (int i = 0; i < cycle.size(); i++)
	{
		max_cycle[i].X = cycle[i].size();
		cnt = cycle[i].size();
		for (int j = 0; j < cycle[i].size(); j++)
			if (visited[cycle[i][j]] == -1)
				makeSCC(cycle[i][j]);
		max_cycle[i].Y = cnt;
	}
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, k) << '\n';
}
// 참고 : https://kukekyakya.tistory.com/462