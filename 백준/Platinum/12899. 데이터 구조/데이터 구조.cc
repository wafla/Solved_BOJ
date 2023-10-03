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
int seg[8000001] = { 0 };
int n;
int query(int node, int s, int e, int idx)
{
	seg[node]--;
	if (s == e)
		return s;
	int mid = s + (e - s) / 2;
	if (idx <= seg[2 * node])
		return query(2 * node, s, mid, idx);
	else
		return query(2 * node + 1, mid + 1, e, idx - seg[2 * node]);
}
int add(int node, int s, int e, int idx)
{
	if (s == e) return seg[node]++;
	int mid = s + (e - s) / 2;
	if (idx <= mid)
		add(2 * node, s, mid, idx);
	else
		add(2 * node + 1, mid + 1, e, idx);
	return seg[node] = seg[2 * node] + seg[2 * node + 1];
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
		if (x == 1)
			add(1, 1, 2000000, y);
		else
			cout << query(1, 1, 2000000, y) << '\n';
	}
}