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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
bool visit[3001] = { 0 };
int ans[3001] = { 0 };
bool check[3001] = { 0 };
int n, t = -1, flag = 0;
vector<vector<int>> v;
void solve(int idx, int prv)
{
	if (visit[idx])
	{
		t = idx;
		flag = 1;
		return;
	}
	if (flag)
		return;
	visit[idx] = 1;
	for (int i = 0; i < v[idx].size(); i++)
	{
		if (v[idx][i] == prv)
			continue;
		solve(v[idx][i], idx);
		if (flag)
			return;
	}
}
void dfs(int idx, int prv)
{
	if (visit[idx] == 1)
	{
		check[idx] = 1;
		return;
	}
	visit[idx] = 1;
	for (int i = 0; i < v[idx].size(); i++)
	{
		if (v[idx][i] == prv)
			continue;
		dfs(v[idx][i], idx);
		if (check[v[idx][i]])
			check[idx] = 1;
	}
}
void bfs(int idx)
{
	queue<pi> Q;
	Q.push({ idx,0 });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		ans[cur.X] = cur.Y;
		for (int i = 0; i < v[cur.X].size(); i++)
		{
			if (!visit[v[cur.X][i]])
			{
				visit[v[cur.X][i]] = 1;
				if (check[v[cur.X][i]])
					Q.push({ v[cur.X][i],0 });
				else
					Q.push({ v[cur.X][i], cur.Y + 1 });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	solve(1, 1);
	memset(visit, 0, sizeof(visit));
	dfs(t, t);
	memset(visit, 0, sizeof(visit));
	bfs(t);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << '\n';
}