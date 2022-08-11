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
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m;
	cin >> m;
	vector<pair<int, int>> v;
	while (1)
	{
		int l, r;
		cin >> l >> r;
		if (l == 0 && r == 0)
			break;
		if (l == r)
			continue;
		if (l > r)
		{
			int tmp = l;
			l = r;
			r = tmp;
		}
		v.push_back({l, r});
	}
	sort(v.begin(), v.end());
	int cur = 0, ans = 0, i = 0;
	while (cur < m)
	{
		int maxx = -1;
		for (; i < v.size() && v[i].X <= cur; i++)
			maxx = max(maxx, v[i].Y);
		if (cur < maxx)
		{
			cur = maxx;
			ans++;
		}
		else
			break;
	}
	if (cur >= m)
		cout << ans << '\n';
	else
		cout << 0 << '\n';
}