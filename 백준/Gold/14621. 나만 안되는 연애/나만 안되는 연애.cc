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
int parent[1001] = { 0 };
int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
	int px = find(x);
	int py = find(y);
	if (px < py)
		parent[py] = px;
	else
		parent[px] = py;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + 1);
	vector<pair<int, pi>> v(m);
	vector<bool> visited(n + 1);
	map<int, char> M;
	iota(parent, parent + n, 0);
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		M[i + 1] = x;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v[i] = { w,{x,y} };
	}
	sort(v.begin(), v.end());

	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int w = v[i].X;
		int x = v[i].Y.X;
		int y = v[i].Y.Y;
		if (M[x] == M[y])
			continue;
		else
		{
			if (visited[x] && visited[y])
			{
				if (find(x) == find(y))
					continue;
				else
				{
					merge(x, y);
					ans += w;
				}
			}
			else
			{
				if (!visited[x])
				{
					visited[x] = 1;
					cnt++;
				}
				if (!visited[y])
				{
					visited[y] = 1;
					cnt++;
				}
				ans += w;
				merge(x, y);
			}
		}
	}
	if (cnt == n)
		cout << ans << '\n';
	else
		cout << -1 << '\n';
}