#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int parent[1001] = { 0 };
int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	parent[u] = v;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	long long n, ans = 0;
	vector<pair<int, pair<int, int>>> edges;
	vector<pair<int, pair<int, int>>> mst;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			int x;
			cin >> x;
			if (i == j)
				continue;
			edges.push_back({ x, {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 1;i <= n;i++)
		parent[i] = i;
	for (int i = 0;i < edges.size();i++)
	{
		auto cur = edges[i];

		if (find(cur.Y.X) == find(cur.Y.Y))
			continue;

		ans += cur.X;
		mst.push_back(cur);
		merge(cur.Y.X, cur.Y.Y);

		if (mst.size() == n - 1)
			break;
	}
	cout << ans;
}