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
#define pi pair<ll, ll>
using namespace std;
int n, m;
ll dis[501] = { 0 };
vector<pair<pi, int>> v;
int Bellman_Ford()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			ll from = v[j].X.X;
			ll to = v[j].X.Y;
			ll cost = v[j].Y;
			if (dis[from] == INF)
				continue;
			if (dis[to] > dis[from] + cost)
				dis[to] = dis[from] + cost;
		}
	}
	for (int j = 0; j < v.size(); j++)
	{
		ll from = v[j].X.X;
		ll to = v[j].X.Y;
		ll cost = v[j].Y;
		if (dis[from] == INF)
			continue;
		if (dis[to] > dis[from] + cost)
			return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[1] = 0;
	for (int i = 0; i < m; i++)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		v.push_back({ {x,y},z });
	}
	if (!Bellman_Ford())
		cout << -1 << '\n';
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dis[i] == INF)
				cout << -1 << '\n';
			else
				cout << dis[i] << '\n';
		}
	}
}
// 참고 : https://yabmoons.tistory.com/365