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
#define LINF 9223372036854775807
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<int, pi>
using namespace std;
int n, m, x;
int dist[2][1001];
vector<pi> v[2][1001];
void dijkstra(int k)
{
	priority_queue<int, vector<int>, greater<int>> PQ;
	PQ.push(x);
	dist[k][x] = 0;
	while (PQ.size())
	{
		auto cur = PQ.top();
		PQ.pop();
		for (int i = 0; i < v[k][cur].size(); i++)
		{
			int nw = v[k][cur][i].X;
			int nx = v[k][cur][i].Y;
			if (dist[k][cur] + nw < dist[k][nx])
			{
				dist[k][nx] = dist[k][cur] + nw;
				PQ.push(nx);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v[0][x].push_back({ w,y });
		v[1][y].push_back({ w,x });
	}
	for (int i = 1; i <= n; i++)
	{
		dist[0][i] = INF;
		dist[1][i] = INF;
	}

	dijkstra(0);
	dijkstra(1);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dist[0][i] + dist[1][i]);
	cout << ans << '\n';
}