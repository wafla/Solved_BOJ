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
int seg[400001] = { 0 };
int n, k;
int init(int node, int s, int e)
{
	if (s == e)
		return seg[node] = 1;
	int mid = s + (e - s) / 2;
	return seg[node] = init(2 * node, s, mid) + init(2 * node + 1, mid + 1, e);
}
int query(int node, int s, int e, int idx)
{
	if (s == e)
		return s;
	int mid = s + (e - s) / 2;
	if (idx <= seg[2 * node])
		return query(2 * node, s, mid, idx);
	else
		return query(2 * node + 1, mid + 1, e, idx - seg[2 * node]);
}
int update(int node, int s, int e, int idx)
{
	seg[node]--;
	if (s == e)return 0;
	int mid = s + (e - s) / 2;
	if (idx <= mid)
		return update(2 * node, s, mid, idx);
	else
		return update(2 * node + 1, mid + 1, e, idx);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	init(1, 1, n);
	int idx = 1;

	cout << "<";
	for (int i = 0; i < n; i++)
	{
		int size = n - i;
		idx += k - 1;

		if (idx % size == 0)
			idx = size;
		else if (idx > size)
			idx %= size;

		int tmp = query(1, 1, n, idx);
		update(1, 1, n, tmp);
		if (i < n - 1)
			cout << tmp << ", ";
		else
			cout << tmp;
	}
	cout << ">\n";
}
// 참고 : https://cocoon1787.tistory.com/433