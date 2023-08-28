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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int n, k, src;
int dist[1001] = { 0 };
vector<pair<pi,int>> v;
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
	cin >> n >> k;

	int flag = 0;
	for (int i = 0; i < k; i++)
	{
		int a, x, y, z;
		cin >> a >> x >> y >> z;
		if (a == 1)
		{
			v.push_back({ {x,y},-z });
			if (!flag)
			{
				dist[x] = 0;
				flag = 1;
			}
		}
		else if (a == 2)
		{
			v.push_back({ {y,x},z });
			if (!flag)
			{
				dist[y] = 0;
				flag = 1;
			}
		}
		else
		{
			v.push_back({ {y,x},z });
			v.push_back({ {x,y},-z });
			if (!flag)
			{
				dist[x] = 0;
				flag = 1;
			}
		}
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
		if (maxx - minn > 100)
			cout << -1 << '\n';
		else
			cout << maxx - minn << '\n';
	}
	else
		cout << -1 << '\n';
}