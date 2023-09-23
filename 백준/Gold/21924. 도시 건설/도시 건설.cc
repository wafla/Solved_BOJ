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
vector<vector<pi>> v;
bool visit[100001] = { 0 };
int cost[100001] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, sum = 0;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
		sum += c;
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	for (int i = 1; i <= n; i++)
		cost[i] = INF;
	priority_queue<pi, vector<pi>, greater<pi>> PQ; // 값, 도시
	PQ.push({ 0,1 });
	cost[1] = 0;
	while (!PQ.empty())
	{
		auto cur = PQ.top();
		PQ.pop();
		if (visit[cur.Y])
			continue;
		visit[cur.Y] = 1;
		for (int i = 0; i < v[cur.Y].size(); i++)
		{
			int n_city = v[cur.Y][i].Y;
			int n_cost = v[cur.Y][i].X;
			if (n_cost < cost[n_city] && !visit[n_city])
			{
				cost[n_city] = n_cost;
				PQ.push({ n_cost, n_city });
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cost[i] == INF)
		{
			ans = -1;
			break;
		}
		ans += cost[i];
	}
	if (ans == -1)
		cout << ans << '\n';
	else
		cout << sum - ans << '\n';
}