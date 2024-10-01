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
int n, m;
vector<vector<int>> v;
vector<vector<int>> rv;
vector<vector<int>> nv;
vector<vector<int>> scc;
vector<bool> check;
vector<bool> visited;
vector<int> which_scc;
vector<int> sum;
vector<int> cnt;
vector<set<int>> S;
stack<int> st;
void dfs(int x)
{
	visited[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		int nx = v[x][i];
		if (!visited[nx])
			dfs(nx);
	}
	st.push(x);
}
void rdfs(int x, int size)
{
	visited[x] = 1;
	which_scc[x] = size;
	S[size].insert(x);
	scc[size].push_back(x);
	for (int i = 0; i < rv[x].size(); i++)
	{
		int nx = rv[x][i];
		if (!visited[nx])
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
	which_scc.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		rv[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs(i);

	fill(visited.begin(), visited.end(), false);
	while (st.size())
	{
		auto cur = st.top();
		st.pop();
		if (visited[cur])
			continue;
		scc.resize(scc.size() + 1);
		S.resize(scc.size());
		rdfs(cur, scc.size() - 1);
	}

	nv.resize(scc.size());
	sum.resize(scc.size());
	cnt.resize(scc.size());
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

	for (int i = 0; i < scc.size(); i++)
	{
		if (S[i].size() == n)
		{
			cout << n << '\n';
			for (int i = 1; i <= n; i++)
				cout << i << " ";
			cout << '\n';
			return 0;
		}
	}

	check.resize(scc.size());
	vector<int> asdf;
	for (int i = 0; i < scc.size(); i++)
		if (!cnt[i])
			asdf.push_back(i);
	if (asdf.size() > 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	int i = asdf[0];
	queue<pair<int, int>> Q;
	int tmp = scc[i].size();
	Q.push({ i,tmp });
	check[i] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int x = cur.X;
		int ans = cur.Y;
		if (!check[x])
			ans += scc[x].size();
		if (ans == n)
		{
			cout << scc[i].size() << '\n';
			sort(scc[i].begin(), scc[i].end());
			for (int j = 0; j < scc[i].size(); j++)
				cout << scc[i][j] << " ";
			cout << '\n';
			return 0;
		}
		for (int j = 0; j < nv[x].size(); j++)
		{
			int nx = nv[x][j];
			cnt[nx]--;
			if (!cnt[nx])
				Q.push({ nx,ans });
		}
	}
	cout << 0 << '\n';
}