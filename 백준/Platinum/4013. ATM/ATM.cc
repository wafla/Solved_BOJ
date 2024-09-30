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
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> rv;
vector<vector<int>> scc;
vector<int> cash;
vector<int> arr;
vector<bool> visited;
vector<bool> visited2;
map<int, int> rest;
stack<int> st;
vector<set<int>> S;
vector<bool> is_rest;
vector<int> which_scc;
int n, m, start, p, sidx;
void dfs(int x)
{
	visited[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		int nx = v[x][i];
		if (visited[nx])
			continue;
		dfs(nx);
	}
	st.push(x);
}
void rdfs(int x, int size)
{
	visited2[x] = 1;
	scc[size].push_back(x);
	S[size].insert(x);
	which_scc[x] = size;
	if (x == start)
		sidx = size;
	if (rest[x])
		is_rest[size] = 1;
	for (int i = 0; i < rv[x].size(); i++)
	{
		int nx = rv[x][i];
		if (!visited[nx] || visited2[nx])
			continue;
		rdfs(nx, size);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	rv.resize(n + 1);
	cash.resize(n + 1);
	visited.resize(n + 1, 0);
	visited2.resize(n + 1, 0);
	which_scc.resize(n + 1, -1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		rv[y].push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x; 
		cin >> x;
		cash[i + 1] = x;
	}
	cin >> start >> p;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		rest[x] = 1;
	}
	
	dfs(start);

	while (st.size())
	{
		auto cur = st.top();
		st.pop();
		if (!visited2[cur])
		{
			scc.resize(scc.size() + 1);
			S.resize(scc.size());
			is_rest.resize(scc.size());
			rdfs(cur, scc.size() - 1);
		}
	}

	arr.resize(scc.size());
	vector<vector<int>> nv(n + 1);
	vector<int> cnt(n + 1);
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
		{
			arr[i] += cash[scc[i][j]];
			for (int k = 0; k < v[scc[i][j]].size(); k++)
			{
				int nx = v[scc[i][j]][k];
				if (!S[i].count(nx))
				{
					nv[i].push_back(which_scc[nx]);
					cnt[which_scc[nx]]++;
				}
			}
		}
	}

	int ans = 0;
	vector<int> dp(n + 1, 0);
	dp[sidx] = arr[sidx];
	if (is_rest[sidx])
		ans = dp[sidx];
	queue<int> Q;
	Q.push(sidx);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int idx = cur;
		for (int i = 0; i < nv[idx].size(); i++)
		{
			int nidx = nv[idx][i];
			cnt[nidx]--;
			dp[nidx] = max(dp[nidx], dp[idx] + arr[nidx]);
			if (is_rest[nidx])
				ans = max(dp[nidx], ans);
			if (!cnt[nidx])
				Q.push(nidx);
		}
	}
	cout << ans << '\n';
}