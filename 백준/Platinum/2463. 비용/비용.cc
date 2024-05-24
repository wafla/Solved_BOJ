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
#define MOD 1000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
int n, m, sum = 0;
vector<T> v;
int parent[100001] = { 0 };
int setSize[100001] = { 0 };
int find(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	parent[b] = a;
	setSize[a] += setSize[b];
	setSize[b] = 1;
}
bool cmp(T a, T b)
{
	if (a.Y > b.Y)
		return true;
	return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
		setSize[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v[i].X.X = x;
		v[i].X.Y = y;
        v[i].Y = z;
		sum += z;
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a = find(v[i].X.X);
		int b = find(v[i].X.Y);
		int cost = v[i].Y;

		if (a != b)
		{
			ans += (((setSize[a] * setSize[b]) % MOD) * sum) % MOD;
			ans %= MOD;
			merge(a, b);
		}
		sum -= cost;
	}
	cout << ans << '\n';
}
// 참고 : https://jaimemin.tistory.com/943