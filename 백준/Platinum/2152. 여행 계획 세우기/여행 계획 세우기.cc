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
int n, m, s, t, sidx, eidx = -1;
vector<vector<int>> v;
vector<vector<int>> rv;
vector<vector<int>> scc;
vector<bool> visited;
vector<bool> visited2;
vector<int> cnt;
vector<int> which_scc;
vector<int> sum;
vector<set<int>> S;
stack<int> st;
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
	if (x == s)
		sidx = size;
	if (x == t)
		eidx = size;
	visited2[x] = 1;
	scc[size].push_back(x);
	which_scc[x] = size;
	S[size].insert(x);
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
	cin >> n >> m >> s >> t;
	v.resize(n + 1);
	rv.resize(n + 1);
	visited.resize(n + 1);
	visited2.resize(n + 1);
	which_scc.resize(n + 1, -1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		rv[y].push_back(x);
	}

	dfs(s);

	while (st.size())
	{
		auto cur = st.top();
		st.pop();
		if (visited2[cur])
			continue;
		scc.resize(scc.size() + 1);
		S.resize(scc.size());
		rdfs(cur, scc.size() - 1);
	}

	vector<vector<int>> nv(n + 1);
	sum.resize(n + 1);
	cnt.resize(n + 1);
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
		{
			sum[i] += 1;
			for (int k = 0; k < v[scc[i][j]].size(); k++)
			{
				int nx = v[scc[i][j]][k];
				if (S[i].count(nx))
					continue;
				nv[i].push_back(which_scc[nx]);
				cnt[which_scc[nx]]++;
			}
		}
	}

	vector<int> dp(scc.size());
	dp[sidx] = sum[sidx];
	queue<int> Q;
	Q.push(sidx);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < nv[cur].size(); i++)
		{
			int nx = nv[cur][i];
			cnt[nx]--;
			dp[nx] = max(dp[nx], dp[cur] + sum[nx]);
			if (!cnt[nx])
				Q.push(nx);
		}
	}
	if (eidx == -1)
		cout << 0 << '\n';
	else
		cout << dp[eidx] << '\n';
}