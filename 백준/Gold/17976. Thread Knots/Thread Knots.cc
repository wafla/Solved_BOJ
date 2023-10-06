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
int n;
vector<pi> v;
bool check(int dist)
{
	int tmp = v[0].X;
	for (int i = 1; i < n; i++)
	{
		if (v[i].X - tmp >= dist)
			tmp = v[i].X;
		else
		{
			if (tmp + dist > v[i].Y)
				return 0;
			tmp += dist;
		}
	}
	return 1;
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
		v.push_back({ x,x + y });
	}
	sort(v.begin(), v.end());

	int ans = 0;
	int left = 0, right = 2000000000;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (check(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans << '\n';
}