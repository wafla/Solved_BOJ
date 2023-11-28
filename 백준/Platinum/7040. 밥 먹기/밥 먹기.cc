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
int n, ml, md;
int dist[1001] = { 0 };
vector<pair<pi, int>> v;
int solve()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int from = v[j].X.X;
			int to = v[j].X.Y;
			int cost = v[j].Y;
			if (dist[from] == INF)
				continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}
	for (int j = 0; j < v.size(); j++)
	{
		int from = v[j].X.X;
		int to = v[j].X.Y;
		int cost = v[j].Y;
		if (dist[from] == INF)
			continue;
		if (dist[to] > dist[from] + cost)
			return 0;
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> ml >> md; // x - y <= ml, y - x >= -md
	for (int i = 1; i <= 1000; i++)
		dist[i] = INF;
	dist[1] = 0;
	for (int i = 0; i < ml; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ {x,y},z });
	}
	for (int i = 0; i < md; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ {y,x},-z });
	}
	if (solve())
	{
		int maxx = 0, minn = INF;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] == INF)
				continue;
			if (dist[i] > maxx)
				maxx = dist[i];
			if (dist[i] < minn)
				minn = dist[i];
		}
		if (dist[n] >= INF)
			cout << -2 << '\n';
		else
			cout << dist[n] << '\n';
	}
	else
		cout << -1 << '\n';
}