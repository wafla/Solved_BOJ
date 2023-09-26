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
bool visit[100001];
int parent[100001] = { 0 };
int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<pi> vx(n), vy(n), vz(n);
	vector<pair<int, pi>> v;
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 0; i < n; i++)
	{
		cin >> vx[i].X >> vy[i].X >> vz[i].X;
		vx[i].Y = i;
		vy[i].Y = i;
		vz[i].Y = i;
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vz.begin(), vz.end());

	for (int i = 1; i < n; i++)
	{
		v.push_back({ abs(vx[i].X - vx[i - 1].X),{vx[i - 1].Y, vx[i].Y} });
		v.push_back({ abs(vy[i].X - vy[i - 1].X),{vy[i - 1].Y, vy[i].Y} });
		v.push_back({ abs(vz[i].X - vz[i - 1].X),{vz[i - 1].Y, vz[i].Y} });
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (find(v[i].Y.X) != find(v[i].Y.Y))
		{
			Union(v[i].Y.X, v[i].Y.Y);
			ans += v[i].X;
		}
	}
	cout << ans << '\n';
}
// 참고 : https://chanhuiseok.github.io/posts/baek-34/