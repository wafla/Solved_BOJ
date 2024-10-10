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
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
int n, k;
int ans, diff;
void solve(int w)
{
	if (diff > abs(k - w))
	{
		diff = abs(k - w);
		ans = w;
	}
	else if (diff == abs(k - w))
	{
		if (ans > w)
			ans = w;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> k >> n;
		vector<int> a(n), b(n), c(n), d(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
			cin >> c[i];
		for (int i = 0; i < n; i++)
			cin >> d[i];

		vector<int> v1, v2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				v1.push_back(a[i] + b[j]);
				v2.push_back(c[i] + d[j]);
			}
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		ans = INF, diff = INF;
		for (int i = 0; i < v1.size(); i++)
		{
			int num = v1[i];
			int idx = lower_bound(v2.begin(), v2.end(), k - num) - v2.begin();
			if (idx < v2.size())
			{
				int w = num + v2[idx];
				solve(w);
			}
			if (idx > 0)
			{
				int w = num + v2[idx - 1];
				solve(w);
			}
		}
		cout << ans << '\n';
	}
}