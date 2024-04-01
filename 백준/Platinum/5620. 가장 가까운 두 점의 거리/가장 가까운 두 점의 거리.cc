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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi piar<int, int>
using namespace std;
vector<pair<int, int>> v;
int n;
int dist(pair<int, int> a, pair<int, int> b)
{
	int x = (a.X - b.X) * (a.X - b.X);
	int y = (a.Y - b.Y) * (a.Y - b.Y);
	return x + y;
}
int solve(int l, int r)
{
	int size = r - l + 1;

	if (size == 2)
		return dist(v[l], v[r]);
	else if (size == 3)
		return min(dist(v[l], v[l + 1]), min(dist(v[l], v[r]), dist(v[l + 1], v[r])));

	int mid = (l + r) / 2;
	int ret = min(solve(l, mid), solve(mid + 1, r));

	vector<pair<int, int>> p;
	p.reserve(n);

	int line = (v[mid].X + v[mid + 1].X) / 2;
	for (int i = l; i <= r; i++)
		if ((line - v[i].X) * (line - v[i].X) < ret)
			p.push_back({ v[i].Y, v[i].X });
	sort(p.begin(), p.end());

	for (int i = 0; i < p.size(); i++)
	{
		for (int j = i + 1; j < p.size(); j++)
		{
			if ((p[i].X - p[j].X) * (p[i].X - p[j].X) >= ret)
				break;
			else
				ret = min(ret, dist(p[i], p[j]));
		}
	}
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	cout << solve(0, n - 1) << '\n';
}