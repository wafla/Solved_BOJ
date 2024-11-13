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
using namespace std;
vector<int> parent(1000001);
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
	if (px > px)
		swap(px, py);
	parent[py] = px;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 0)
		{
			merge(a, b);
		}
		else if (x == 1)
		{
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}